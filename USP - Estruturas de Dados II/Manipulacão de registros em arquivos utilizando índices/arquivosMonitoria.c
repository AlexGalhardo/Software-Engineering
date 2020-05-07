#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
typedef struct {
    int rg;
    char nome[10];
} registro_t;
 
typedef struct {
    int tamanho;
} header_t;
 
registro_t registros[100];
int n;
 
void read_registros(const char *filename) {

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        n = 0;
        return;
    }
 
    // le o cabecalho do arquivo
    header_t header;
    fread(&header, sizeof(header_t), 1, fp);
    n = header.tamanho;
 
    // le os dados
    fread(registros, sizeof(registro_t), n, fp);
 
    fclose(fp);
}
 
typedef struct {
    int rg;
    int rrn;
} indice_t;
 
indice_t indice[100];
 
int cmp_indice(const void *a, const void *b) {
    indice_t *pa = (indice_t *) a;
    indice_t *pb = (indice_t *) b;
    return pa->rg - pb->rg;
}
 
void make_indice() {
    for (int i = 0; i < n; i++) {
        indice[i].rg = registros[i].rg;
        indice[i].rrn = i;
    }
    qsort(indice, n, sizeof(indice_t), cmp_indice);
}
 
void read_indice(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "arquivo de indice nao encontrado, recriando o indice\n");
        make_indice();
        for (int i = 0; i < n; i++) {
            printf("%d %d\n", indice[i].rg, indice[i].rrn);
        }
        return;
    }
 
    // le o indice
    fread(indice, sizeof(indice_t), n, fp);
 
    fclose(fp);
}
 
void write_indice(const char *filename) {
    
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        n = 0;
        return;
    }
 
    // escreve o indice
    fwrite(indice, sizeof(indice_t), n, fp);
 
    fclose(fp);
}
 
int search_indice(int key) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (indice[m].rg < key) lo = m + 1;
        else hi = m;
    }
    if (lo == n || indice[lo].rg != key) return -1;
    return indice[lo].rrn;
}
 
void write_registros(const char *filename) {

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "nao deu pra abrir o arquivo %s\n", filename);
        exit(0);
    }
 
    // escreve o cabecalho no arquivo
    header_t header;
    header.tamanho = n;
    fwrite(&header, sizeof(header_t), 1, fp);
 
    // escreve os dados
    fwrite(registros, sizeof(registro_t), n, fp);
 
    fclose(fp);
}
 
int main() {

    read_registros("dados");
    read_indice("ind");
 
    while (1) {
        int op;
        scanf("%d", &op);
 
        if (op == 1) {
            int rg;
            char nome[256];
            scanf("%d %s", &rg, nome);
            nome[10] = '\0';
            registros[n].rg = rg;
            strcpy(registros[n].nome, nome);
            n++;
        } else if (op == 2) {
            for (int i = 0; i < n; i++) {
                printf("RG: %d NOME: %s\n", registros[i].rg, registros[i].nome);
            }
        } else if (op == 3) {
            break;
        } else if (op == 4) {
            int rg;
            scanf("%d", &rg);
            make_indice();
            int k = search_indice(rg);
            if (k == -1) {
                printf("chave nao encontrada\n");
            } else {
                printf("k: %d\n", k);
                printf("RG: %d NOME: %s\n", registros[k].rg, registros[k].nome);
            }
        }
    }
 
    write_registros("dados");
    write_indice("ind");
 
    return 0;
}