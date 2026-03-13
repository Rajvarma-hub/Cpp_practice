#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print_matrix_spiral(int ar[100][100],int n,int m){
    int top=0,bottom=n-1;
    int left=0,right=m-1;
    while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++){
            cout<<ar[top][j]<<" ";
        }
        top++;
        for(int i=top;i<=bottom;i++)
        cout<<ar[i][right]<<" ";
        right--;

        if(top<=bottom){
            for(int i=right;i>=left;i--)
            cout<<ar[bottom][i]<<" ";
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--)
            cout<<ar[i][left]<<" ";
            left++;
        }


    }
    
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int matrix[100][100];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    print_matrix_spiral(matrix,rows,cols);
    return 0;
}