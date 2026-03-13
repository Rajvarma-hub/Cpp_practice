#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

void bit(int num,int n,int j=0){
    int b;
   for(int i=0;i<=n;i++){
     b=num%2;
    num=num/2;
   }
   if(b)cout<<"True";
   else cout<<"False";
}
void even_odd(int n){
    n=n&1;
    if(n==0)cout<<"Even";
    else cout<<"Odd";
}
void count_setbits(int num){
    int count=0;
    while(num!=0){
        num=(num&(num-1));
        count++;
    }
    cout<<"NO of set bits are: "<<count;
}
void count_setbit_brueforce(int num){
    int count=0;
    while(num){}
}
int division_without_divide_operators(int dividend,int div){
      if(dividend==INT_MIN && div ==-1)return INT_MAX;
      bool neg=(dividend<0)^(div<0);
      long long result=0;
      long long a=labs(dividend);
      long long b=labs(div);
      while(a>=b){
        long long temp=b,multiple=1;
        while(a>=(temp<<1)){
            temp<<=1;
            multiple<<=1;
        }
        a-=temp;
        result+=multiple;
      }
      if(neg)result=-result;
      if(result>INT_MAX)return INT_MIN;
      if(result < INT_MIN)return INT_MAX;
      return (int)result;

      

}
void xor_ofNumbers_L2R(int l,int r){
    int res=0;
    for(int i=l;i<=r;i++){
        res=res^i;
    }
    cout<<"Result: "<<res;
}
int xortillN(int n){
    if(n%4 ==1)return 1;
    if(n%4==2)return n+1;
    if(n%4==3)return 0;
    return n;

}
void findrangexor(int l,int r){
    int res=xortillN(l-1)^xortillN(r);
    cout<<"result "<<res;
}
int main(){
    int num,i;
    cin>>num;
    cin>>i;
    xor_ofNumbers_L2R(num,i);
    findrangexor(num,i);
}