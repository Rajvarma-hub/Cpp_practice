#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void  printN1(int n){
    if(n==0)return;
    printN1(n-1);
    cout<<n;
}
void print1N(int n){
    if(n==0)return;
    cout<<n<<" ";
    print1N(n-1);

}
int count_digits(int n,int count){
    if(n==0)return count;
    n/=10;
    count++;
    return count_digits(n,count);
}
int sumOfDigits(int n,int sum){
    if(n==0)return sum;
    return sumOfDigits(n-1,sum+n);
}
int powerofn(int n,int pow){
    if(pow==0)return 1;
    int val= powerofn(n,pow-1);
    return val*n;
}
int countZeros(int n,int count){
    if(n==0)return count;
    int m=n%10;
    if(m==0)count++;
    n/=10;
    return countZeros(n,count);
}
int main(){
  int res=countZeros(100050,0);
  cout<<res;

}
