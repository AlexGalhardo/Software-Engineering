terraform {
  required_version = "~> 1.0.0" # 1.0.0 até 1.0.n

  required_providers {
    aws = {
        version = "1.0"
        source = "hashicorp/aws"
    }

    azurerm = {
        version = "2.0"
        source = "hashicorp/azurerm"
    }
  }

  backend "azurerm" {

  }
}