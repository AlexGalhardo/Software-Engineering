output "sas_token" {
  description = "SAS Token para o Container de imagens"
  value       = data.azurerm_storage_account_blob_container_sas.sas_token.sas
}

output "container_url" {
  description = "URL do Container de imagens"
  value       = azurerm_storage_container.container.id
}