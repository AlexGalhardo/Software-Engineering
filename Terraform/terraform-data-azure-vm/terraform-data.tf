resource "terraform_data" "data" {
  triggers_replace = [
    azurerm_storage_account.storage_account.id,
    azurerm_linux_virtual_machine.vm.id
  ]

  connection {
    type        = "ssh"
    user        = "terraform"
    private_key = file("./azure-key")
    host        = azurerm_linux_virtual_machine.vm.public_ip_address
  }

  provisioner "remote-exec" {
    inline = [
      "echo \"Storage Account key: ${azurerm_storage_account.storage_account.primary_access_key}\" >> /tmp/storage-account-key.txt"
    ]
  }
}

resource "null_resource" "null" {
  triggers = {
    storage_account = azurerm_storage_account.storage_account.id
    virtual_machine = azurerm_linux_virtual_machine.vm.id
  }

  connection {
    type        = "ssh"
    user        = "terraform"
    private_key = file("./azure-key")
    host        = azurerm_linux_virtual_machine.vm.public_ip_address
  }

  provisioner "remote-exec" {
    inline = [
      "echo \"Storage Account Connection String: ${azurerm_storage_account.storage_account.primary_connection_string}\" >> /tmp/storage-account-connection-string.txt"
    ]
  }
}

resource "terraform_data" "variable_trigger" {
  input = var.infra_version
}