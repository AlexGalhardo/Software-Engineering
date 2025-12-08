terraform {
  required_version = ">= 1.4.0"

  required_providers {
    azurerm = {
      source  = "hashicorp/azurerm"
      version = "3.69.0"
    }
  }

  backend "azurerm" {
    resource_group_name  = "rg-terraform-state"
    storage_account_name = "galhardoterraformstate"
    container_name       = "remote-state"
    key                  = "data-source/terraform.tfstate"
  }
}

provider "azurerm" {
  features {}
}