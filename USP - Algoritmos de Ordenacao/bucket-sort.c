/*

REFERÊNCIA: https://pt.wikipedia.org/wiki/Bucket_sort

https://www.youtube.com/watch?v=VuXbEb5ywrU

Bucket sort
Faça uma implementação do algoritmo de ordenação "bucket sort". O algoritmo deverá ler um número N que indica a quantidade de valores a serem ordenados. Em uma outra linha, o algoritmo deverá ler os N valores a serem ordenados, separados par a par por um único espaço. A saída do método deverá ser os valores ordenados ascendentemente e separados par a par por um único espaço. Imprima os números com 4 casos decimais.

É garantido que todos valores a serem ordenados são números reais entre 0 e 1.

Exemplo de Entrada e Saída
Entrada:

10
0.5000 0.3000 0.2000 0.7000 0.6000 0.8000 0.9000 0.1000 0.0000 0.4000
Saída:

0.0000 0.1000 0.2000 0.3000 0.4000 0.5000 0.6000 0.7000 0.8000 0.9000

*/

#include <stdio.h>
 
 #define tam_bucket 100
 #define num_bucket 10
 #define max 10
 
 typedef struct {
         int topo;
        float balde[tam_bucket];
 }bucket;
 
 void bucket_sort(float v[],int tam);                  
 void bubble(float v[],int tam);                                                 
                                                                  
 void bucket_sort(float v[],int tam){

        bucket b[num_bucket];                                      
        int i,j,k;                                                 
        for(i=0;i<num_bucket;i++){                  
                b[i].topo=0;
        }
         
        for(i=0;i<tam;i++){                          
                j=(num_bucket)-1;
                while(1){
                        if(j<0)
                                break;
                        if(v[i]>=j*10){
                                b[j].balde[b[j].topo]=v[i];
                                {(b[j].topo)++;
                                break;}
                        }
                        j--;
                }
        }
         
        for(i=0;i<num_bucket;i++){                 
                if(b[i].topo){
                        bubble(b[i].balde, b[i].topo);
                }
        }

        i=0;
        for(j=0;j<num_bucket;j++){                    
                for(k=0;k<b[j].topo;k++){
                        v[i]=b[j].balde[k];
                        i++;
                }
        }
 }
 
 void bubble(float v[],int tam){
        int i,j,temp,flag;
        if(tam){
                for(j=0;j<tam-1;j++){
                        flag=0;
                        for(i=0;i<tam-1;i++){
                                if(v[i+1]<v[i]){
                                        temp=v[i];
                                        v[i]=v[i+1];
                                        v[i+1]=temp;
                                        flag=1;
                                }
                        }
                        if(!flag)
                                break;
                }
        }
 }

 int main(){

    int tamanho, i;
    scanf("%d", &tamanho);

    float entrada[tamanho];
    for(i=0; i<tamanho; i++){
        scanf("%f", &entrada[i]);
    }

    bucket_sort(entrada, tamanho);             
    bubble(entrada, tamanho);

    for(i=0; i<tamanho; i++){
        printf("%.4f ", entrada[i]);
    }
    return 0;
}
