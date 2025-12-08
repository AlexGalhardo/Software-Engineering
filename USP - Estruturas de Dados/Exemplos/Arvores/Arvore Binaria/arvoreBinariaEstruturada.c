#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

#define YES 1
#define NO  0

typedef struct no2
{
   int valor;
   int h, bal;
   struct no2 * anterior, * proximo;
} node2;

/*****************************************************/
int QtdNo( node2 * root )
{
   int retorno;
   
   retorno = 0;
   
   if ( root != NULL )
   { retorno = QtdNo(root->anterior)+QtdNo(root->proximo)+1; }
   
   return( retorno );
}

/*****************************************************/
int IsAVL( node2 * root )
{
   if ( root == NULL )
   { return( YES );}
   else
   {
      if (((root->bal < -1) || (root->bal > 1 )) ||
          ((root->anterior        != NULL) && 
           (root->anterior->valor >  root->valor )) ||
          ((root->proximo         != NULL) && 
           (root->proximo->valor  <  root->valor ))
         )
          
      { return( NO );}
      else
      { return( BalancedTree( root->anterior) && 
                BalancedTree( root->proximo) );
      }
   }
}

/*****************************************************/
int BalancedTree( node2 * root )
{
   if ( root == NULL )
   { return( YES );}
   else
   {
      if ((root->bal < -1) || (root->bal > 1 ))
      { return( NO );}
      else
      { return( BalancedTree( root->anterior) && 
                BalancedTree( root->proximo) );
      }
   }
}

/*****************************************************/
void CalcHBal( node2 * root )
{ 
   if (root != NULL)
   { 
         root->bal = VoltaH( root->anterior ) - 
                     VoltaH( root->proximo);
         if (root->bal > 0 )
         { root->h = VoltaH( root->anterior )+1; }
         else
         { root->h = VoltaH( root->proximo )+1; }
   }
}

/*****************************************************/
int VoltaH( node2 * root )
{ 
   if (root == NULL)
   { return( 0 );}
   else
   { return( root->h ); }
}
/*****************************************************/
int VoltaBal( node2 * root )
{ 
   if (root == NULL)
   { return( 0 );}
   else
   { return( root->bal ); }
}
/*****************************************************/
void PreencheBal( node2 * root )
{ int besq, bdir;

   if (root != NULL)
   { 
      root->bal = VoltaH(root->anterior) - VoltaH(root->proximo);
      
      PreencheBal( root->anterior  );
      PreencheBal( root->proximo   );
   }
}


/*****************************************************/
int PreencheH( node2 * root )
{ int hesq, hdir, hret;
   if (root == NULL)
   {
      hret = 0;
   }
   else
   { 
      hesq = PreencheH( root->anterior );
      hdir = PreencheH( root->proximo );
      if (hesq > hdir )
      {
         hret = hesq+1;
      }
      else
      {
         hret = hdir+1;
      }
      root->h = hret;
   }
   return( hret );
}
   
/*****************************************************/
node2 * CriaNode2( int value )
{
   node2 * no;
   
//   printf("\nCN\n");
   no = (node2*) malloc(sizeof( node2 ) );
   if (no != NULL)
   {  (*no).valor    = value;
      (*no).proximo  = NULL; 
      (*no).anterior = NULL;
      no->h   = 1;
      no->bal = 0;
   }
   return( no );
}

/*****************************************************/
node2 * rebalancear( node2 * root )
{
   node2 * aux;
   
//      printf("\nEntrou\n");
//      printf("Bals %d - %d - %d", VoltaBal(root->anterior),
//                  VoltaBal(root), VoltaBal(root->proximo));
   if ( (VoltaBal(root) == 2) && (VoltaBal(root->anterior) == 1) )
   { //pendente pro anterior pai e filho - rodar para direita
      printf("\nCaso 1\n");
      aux = root;
      root = root->anterior;
      aux->anterior = root->proximo;
      root->proximo = aux;
   }
   else
   {
//      printf("\nElse 1\n");
      if ( (VoltaBal(root) == -2) && (VoltaBal(root->proximo) == -1) )
      { //pendente pro proximo pai e filho - rodar para esquerda
      printf("\nCaso 2\n");
         aux = root;
         root = root->proximo;
         aux->proximo = root->anterior;
         root->anterior = aux;

/*   No* b = *r;
  No* a = b->esq;
  b->esq = a->dir;
  a->dir = b;
  a->bal = 0;
  b->bal = 0;
  *r = a;
*/
      }
      else
      {
      printf("\nElse 2\n");
         if ( (VoltaBal(root) == 2) && (VoltaBal(root->anterior) == -1) )
         { //pendente pro anterior pai e proximo filho
           //rodar para esquerda e depois para direita
      printf("\nCaso 3\n");
            aux = root->anterior;
            root->anterior = root->anterior->proximo;
            aux->proximo = root->anterior->anterior;
            root->anterior->anterior = aux;
            aux = root;
            root = root->anterior;
            aux->anterior = root->proximo;
            root->proximo = aux;
         }
         else
         { //pendente pro proximo pai e anterior filho
           //rodar para direita e depois para esquerda
      printf("\nCaso 4\n");
            aux = root->proximo;
            root->proximo = root->proximo->anterior;
            aux->anterior = root->proximo->proximo;
            root->proximo->proximo = aux;
            
            aux = root;
            root = root->proximo;
            aux->proximo = root->anterior;
            root->anterior = aux;
         }
      }
   }
   return( root );
}
      
      
   

/*****************************************************/
node2 * InsereBinariaOrd( node2 * root, node2 * novo )
{
   if (root == NULL)
   {
      root = novo; 
   }
   else
   {
         if( root->valor > novo->valor )
         {
            root->anterior = InsereBinariaOrd( root->anterior, novo );
         }
         else
         {
            root->proximo = InsereBinariaOrd( root->proximo, novo );
         }

//      printf("\nCalcHBal root: %d\n", root->valor);

         CalcHBal( root );         
                     
         if (((VoltaH( root->anterior )-VoltaH( root->proximo))>1) ||
             ((VoltaH( root->anterior )-VoltaH( root->proximo))<-1)
            )
         {
      printf("\nRebalancear\n");
            //rebalancear
            root = rebalancear( root );
         }
         
//      printf("\nCalcHBals\n");
         
         CalcHBal( root->anterior );
         CalcHBal( root->proximo );
         CalcHBal( root );
   }
   
   return( root );
}

/*****************************************************/
void PrintBinariaOrd( node2 * root )
{
   if (root != NULL)
   {
      PrintBinariaOrd( root->anterior );
      printf("val: %d h:%d b:%d\n", root->valor, root->h, root->bal );
      PrintBinariaOrd( root->proximo );
   }
}

/*****************************************************/
node2 * BuscaBin( node2 * root, int value )
{
   node2 * retorno;
   
   if (root == NULL)
   { 
      retorno = NULL;
   }
   else
   {
      if (root->valor == value)
      {
         retorno = root;
      }
      else
      {
         if( root->valor > value )
         {
            retorno = BuscaBin( root->anterior, value );
         }
         else
         {
            retorno = BuscaBin( root->proximo, value );
         }
      }
   }
   return(retorno);   
}


/*****************************************************/
int main(void)
{
  node2 * novo2, * head2;
  int contador;

  /*****************************************************/
  printf("\n #### Arvore Binaria ####\n" );
  head2 = NULL;
  for( contador = 0; contador < 5; contador++ )
  {
      printf("********************  %d **************\n", contador );
      novo2 = CriaNode2( contador );
      head2 = InsereBinariaOrd( head2, novo2 );
/*      printf("###############################\n" );
      PrintBinariaOrd( head2 );
      printf("###############################\n" );
*/  }
//  PreencheH( head2 );
//  PreencheBal( head2 );
    
  PrintBinariaOrd( head2 );

  printf("\nBalanceada: %d\n", BalancedTree( head2 ));
  printf("\nIsAVL: %d\n",IsAVL( head2 ));

  printf("\nQtde nos: %d\n", QtdNo( head2 ));   
      
  
  novo2 = BuscaBin( head2, 3 );
  printf("\nNo achado -> %d\n", novo2->valor );
  

  getch();
  return( 0 );     
}