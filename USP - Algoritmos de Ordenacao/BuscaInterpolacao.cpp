/*

http://www.w3ii.com/pt/data_structures_algorithms/interpolation_search_algorithm.html

https://pt.wikipedia.org/wiki/Interpola%C3%A7%C3%A3o

https://www.codewhoop.com/tutorial/interpolation-search

*/
#include <iostream>
using namespace std;

//Function to perform interpolation Search
int interpolationSearch ( int A[] , int n, int e){
  int start, end , pos;
  start= 0;
  end = n-1;

  while( start<=end && e>=A[start] && e<=A[end]){

   pos = start + (((double)(end-start)/(A[end]-A[start]))*(e-A[start]));

   if (A[pos] == e)
    return pos;
   if (e > A[pos])
    start = pos + 1;
   else
    end = pos-1;
   }
  return -1;
}

int main(){
   int n,i,e;
   cout<<"enter number of elements\n";
   cin>>n;
   int A[n];
   cout<<"enter elements\n";
   for(i=0;i<n;i++)
    cin>>A[i];
   cout<<"Enter element to be searched\n";
   cin>>e;

   //interpolation search function call
   int index = interpolationSearch(A, n, e);
   if(index != -1)
   cout<<"found at index:"<<index;
   else
   cout<<"Not Found.";

   return 0;
}
