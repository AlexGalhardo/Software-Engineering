#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int nVert;
	int v1, v2;

	scanf("%d\n", &nVert);
	printf("Nro de vertices = %d\n", nVert);
	// agora leia cada aresta (par de vértices)
	// for (int i = 0; i < nVert; ++i)
	// {
	// 	scanf("%d %d\n", &v1, &v2);

	// 	// imprime
	// 	printf("%d-%d\n", v1,v2);
	// }

	while (scanf("%d %d\n", &v1, &v2)  != EOF){
	  // imprime
		printf("%d-%d\n", v1,v2);
	}
	return 0;
}