variable "location" {
  description = "Região onde os recursos serão criados na Azure"
  type        = string
  default     = "West Europe"
}

variable "environment" {
  description = "Ambiente a que pertencem os recursos criados na Azure"
  type        = string
  default     = "desenvolvimento"
}