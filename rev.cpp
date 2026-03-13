#include<iostream>
using namespace std;
void bubble_sort(int ar[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(ar[j]>ar[j+1]){
                swap(ar[j],ar[j+1]);
            }
        }
    }
    for(int x=0;x<n;x++){
        cout<<ar[x]<<" ";
    }

}
void selection_sort(int ar[],int n){
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(ar[j]<ar[minIndex]){
                minIndex=j;
            }
        }
        swap(ar[i],ar[minIndex]);
    }
     for(int x=0;x<n;x++){
        cout<<ar[x]<<" ";
    }
}
void insertion_sort(int ar[],int n){
    for(int i=0;i<n;i++){
        int key=ar[i];
        int j=i-1;
        while(j>=0 && ar[j]>key){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=key;
    }
     for(int x=0;x<n;x++){
        cout<<ar[x]<<" ";
    }
}
void merge(int ar[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)L[i]=ar[l+i];
    for(int j=0;j<n2;j++)R[j]=ar[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if()
    }
}
void mergesort(int ar[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(ar,l,m);
        mergesort(ar,m+1,r);
    }
}
int main(){
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;
    insertion_sort(arr,n);
}