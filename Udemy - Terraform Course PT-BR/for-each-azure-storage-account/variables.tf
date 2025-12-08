variable "location" {
  description = "Região onde os recursos serão criados na Azure"
  type        = map(string)
  default = {
    "europa" = "West Europe",
    "eua"    = "East Us",
    "asia"   = "Japan East",
    "brasil" = "Brazil South"
  }
}

variable "account_tier" {
  description = "Tier da Storage Account na Azure"
  type        = string
  default     = "Standard"
}

variable "account_replication_type" {
  description = "Tipo de replicação de dados da Storage Account"
  type        = string
  default     = "LRS"
}
