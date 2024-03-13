output "vpc_id_default" {
  description = "ID da VPC criada na AWS na região default"
  value       = aws_vpc.default.id
}

output "vpc_id_provider_1" {
  description = "ID da VPC criada na AWS na região do provider 1"
  value       = aws_vpc.provider_1.id
}

output "vpc_id_provider_2" {
  description = "ID da VPC criada na AWS na região do provider 2"
  value       = aws_vpc.provider_2.id
}