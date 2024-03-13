- https://gitlab.com/terraform-basico-ao-avancado
- https://www.udemy.com/course/terraform-do-basico-ao-avancado

# CRIAR AWS KEY
```
ssh-keygen -f aws-key
```

# Conectar a VM
```
ssh -i aws-key ubuntu@52.91.104.81
```

## Comandos
```
terraform providers
```

```
terraform init
```

```
terraform init -reconfigure
```

```
terraform init -migrate-state
```

- Mesma coisa que o migrate-state, mas não pede confirmação
```
terraform init -force-copy
```

- Arquivos que o terraform mudaria
```
terraform check
```

- Alterações que o terraform fez no seu código
```
terraform diff
```

- Formatação automatica
```
terraform fmt
```

```
terraform -recursive
```

- Formatação é valida? só funciona depois do terraform init
```
terraform validate
```

- Ver o plano que o terraform pretende fazer
```
terraform plan
```

- Aplicar terraform no provider
```
terraform apply
```

```
terraform apply --destroy
```

```
terraform apply -auto-approve
```

```
terraform plan -out plan.out
```

```
terraform apply plan.out
```

```
terraform apply -out plan.out -destroy
```

```
terraform destroy
```

```
export TF_VAR_container_name=container-envvar
```

```
terraform output
```

```
terraform output -raw {storage_account_id}
```

```
terraform show plan.out
```

```
terraform state -help
```

```
terraform state mv aws_s3_bucket.bucket_1 aws_s3_bucket.bucket_um
```

```
terraform state pull
```

```
terraform state pull > state.tfstate
```

```
terraform state push --force state.tfstate
```

```
terraform state replace-provider registry.terraform.io/hashicorp/aws-v2 registry.terraform.io/hashicorp/aws
```

```
terraform state show aws_s3_bucket.bucket_1
```

```
terraform state rm aws_s3_bucket.bucket_1
```

```
terraform import aws_s3_bucket.bucket_um alexgalhardo-terraform-commands-1
```

```
terraform refresh
```

```
terraform force-unlock ID_STATE_LOCK
```

```
terraform console
```

```
terraform workspace --help
```

```
terraform workspace list
```

```
terraform workspace new dev
```

```
terraform workspace show
```

```
terraform workspace select prod
```

```
terraform workspace delete dev
```