output "rg_id" {
  description = "ID do Resource Group criado na Azure"
  value       = azurerm_resource_group.resource_group.id
}