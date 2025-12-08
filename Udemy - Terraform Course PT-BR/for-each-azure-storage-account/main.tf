terraform {
  required_version = ">= 1.0.0"

  required_providers {
    azurerm = {
      source  = "hashicorp/azurerm"
      version = "3.48.0"
    }
  }

  backend "azurerm" {
    resource_group_name  = "rg-terraform-state"
    storage_account_name = "galhardoterraformstate"
    container_name       = "remote-state"
    key                  = "for-each/terraform.tfstate"
  }
}

provider "azurerm" {
  features {}
}