# include <bits/stdc++.h>
using namespace std;

long long int findProduct(int num){
  long long product=1;
  while(num>0){
    int k=num%10;
    product*=k;
    num=num/10;
  }
  return product;
}

long long int findSum(int num){
  long long sum=0;
  while(num>0){
    int k=num%10;
    sum+=k;
    num=num/10;
  }
  return sum;
}

void SpecialNum(){
  long long int product=0;
  long long int sum=0;
  for(long long int i=1;i<999999;i++){
    product=findProduct(i);
    sum=findSum(i);
    if(product+sum==i){
      cout<<i<<" ";
  }
}
}
int main(){
  SpecialNuam();
  return 0;

}
