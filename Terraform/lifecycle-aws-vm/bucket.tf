resource "aws_s3_bucket" "bucket" {
  bucket = "danielgil-lifecycle-test"

  lifecycle {
    create_before_destroy = true
    ignore_changes = [
      tags
    ]
  }

  tags = {
    test = "vscode"
  }
}