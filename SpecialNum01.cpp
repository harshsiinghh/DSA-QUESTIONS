# include <bits/stdc++.h>
using namespace std;


int factorial(int D){
  int fact=1;
  while(D!=0){
    fact=fact*D;
    D--;
  }
  return fact;
}



void SpecialNum(int n)
{
    int sum = 0;
    int temp = n;
    while (temp != 0) {
      int k=temp%10;
          sum += factorial(k);
          temp = temp / 10;
    }
    if(sum==n){
          cout<<n<<" ";
    }
}


int main(){
  for(int i=0;i<INT_MAX;i++){
      SpecialNum(i);
  }
  return 0;
}
