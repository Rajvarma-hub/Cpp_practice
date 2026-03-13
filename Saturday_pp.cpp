#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void selection_sort(vector<int> ar){
    for(int i=0;i<ar.size();i++){
        int mini=i;
        for(int j=i+1;j<ar.size();j++){
           if(ar[j]<ar[mini]){
            mini=j;
           }
        }
        swap(ar[i],ar[mini]);
    }
    for(int x:ar)cout<<x<<" ";
}
void bubblesort(vector<int> ar){
    for(int i=0;i<ar.size();i++){
        for(int j=0;j<ar.size()-i-1;j++){
            if(ar[j]>ar[j+1]){
                swap(ar[j],ar[j+1]);
            }
        }
    }
    cout<<"Bubble sorting";
        for(int x:ar)cout<<x<<" ";
}
void insertion_sort(vector<int>ar){
    for(int i=0;i<ar.size();i++){
        int j=i;
        while(j>0 && ar[j-1]>ar[j]){
            swap(ar[j-1],ar[j]);
            j--;
        }
    }
     cout<<"Insertion sorting";
        for(int x:ar)cout<<x<<" ";
}
int main(){
    vector<int> ar={5,3,8,4,2};
    insertion_sort(ar);
}