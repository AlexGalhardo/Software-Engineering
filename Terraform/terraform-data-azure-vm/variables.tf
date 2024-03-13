variable "location" {
  description = "Região onde os recursos serão criados na Azure"
  type        = string
  default     = "West Europe"
}

variable "infra_version" {
  description = "Versão da infraestrutura"
  type        = number
  default     = 2
}