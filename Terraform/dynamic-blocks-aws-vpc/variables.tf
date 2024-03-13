variable "ports" {
  description = "Portas que serão abertas no Security Group"
  type = map(object({
    description = string
    cidr_blocks = list(string)
  }))
  default = {
    22 = {
      description = "Porta 22 para VPN"
      cidr_blocks = ["20.15.101.158/32"]
    }
    80 = {
      description = "Porta 80 para internet"
      cidr_blocks = ["0.0.0.0/0"]
    }
    443 = {
      description = "Porta 443 para internet"
      cidr_blocks = ["0.0.0.0/0"]
    }
  }
}