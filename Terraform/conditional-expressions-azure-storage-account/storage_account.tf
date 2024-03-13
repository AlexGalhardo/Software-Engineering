resource "azurerm_resource_group" "resource_group" {
  name     = "rg-${var.environment}"
  location = var.location

  tags = local.common_tags
}

resource "azurerm_storage_account" "storage_account" {
  count = var.environment == "dev" ? 0 : 1

  name                     = "danielgil${var.environment}"
  resource_group_name      = azurerm_resource_group.resource_group.name
  location                 = var.location
  account_tier             = var.environment == "prod" ? "Premium" : "Standard"
  account_replication_type = var.environment != "prod" ? "LRS" : "RAGZRS"

  tags = local.common_tags
}