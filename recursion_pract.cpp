#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==0)return 1;
    return n*fact(n-1);
}
int Nsum(int n){
    if(n==0)return 0;
    return n+Nsum(n-1);
}
void printNtimes(int n){
    if(n==0)return;
    cout<<"Hello World"<<endl;
    return printNtimes(n-1);

}
void print12N(int n,int i=0){
    if(i==n+1)return;
    cout<<i<<endl;
    return print12N(n,i+1);

}
void printN21(int n){
    if(n==0)return;
    cout<<n<<endl;
    return printN21(n-1);
}
void print12Nrev(int i,int n){
    if(i<1)return;
    cout<<i<<endl;
    print12Nrev(i-1,n);
    
}
void printN21Rev(int i,int n){
    if(i==2*n)return;
    cout<<i-n+1<<endl;
    return printN21Rev(i+1,n);
}
void reverse_array(int i,int ar[],int n){
    if(i>=n/2)return;
    swap(ar[i],ar[n-i-1]);
    reverse_array(i+1,ar,n);
}
bool palindrome(string s,int i=0){
    if(i>=s.length()/2)return true;
    if(s[i]!=s[s.length()-i-1])return false;
    return palindrome(s,i+1);
}

int main(){
    int n=5;
    cout<<"Enter the string";
    string s;
    getline(cin,s);
    if(palindrome(s)){
        cout<<"It is a Palindrome";
    }
    else{
        cout<<"It is not a Palindrome";
    }
}