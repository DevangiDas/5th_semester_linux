#include <cpp>


int main() {
/*
for j=2 to n
key=A[J]
i=j-1
while i>0 and A[i]>key
A[i+1]=A[1]\
i=i-1
A[i+1]=key
*/
 _ A=random(10,1000);
 print("INPUT:",A);
 let count=0;
 for(_ j=1;j<len(A);++j)
 {
   _ key=A[j];
   _ i=j-1;
   while(i>=0 && A[i]>key)
{
  A[i+1]=A[i];
  i=i-1;
  ++count;
} 
   A[i+1]=key;
   }
 print(" sorted ", A, " in ",count, " steps");
 
 }
