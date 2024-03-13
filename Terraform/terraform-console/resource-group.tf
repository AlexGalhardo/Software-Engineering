resource "azurerm_resource_group" "resource_group" {
  name     = "rg-console"
  location = var.location

  tags = local.common_tags
}