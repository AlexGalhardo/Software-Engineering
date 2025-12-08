resource "aws_vpc" "vpc" {
  cidr_block = "10.0.0.0/16"

  tags = {
    Name = "vpc-${terraform.workspace}"
  }
}

resource "aws_subnet" "subnet" {
  count = terraform.workspace == "prod" ? 3 : 1

  vpc_id     = aws_vpc.vpc.id
  cidr_block = "10.0.${count.index}.0/24"

  tags = {
    Name = "subnet-${terraform.workspace}-${count.index}"
  }
}