#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void matrix_multiplication(vector<vector<int>>a,vector<vector<int>>b,vector<vector<int>>&res){
    int n=a.size();
    int m=a[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res[i][j]=a[i][j]*b[i][j];
        }
    }
}
int main(){
    int n,m;
    cin>>n;
    cin>>m;
    cout<<"Enter the elements of first matrix";
    vector<vector<int>>a(n,vector<int>(m,0));
    vector<vector<int>>b(n,vector<int>(m,0));
    vector<vector<int>>res(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            a[i][j]=num;
        }
    }
    cout<<"Enter the elements of second matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            b[i][j]=num;
        }
    }
    matrix_multiplication(a,b,res);
    cout<<"Printing the matrix multiplication"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}