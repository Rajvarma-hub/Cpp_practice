#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void largest_element(vector<int> ar){
    sort(ar.begin(),ar.end());
    int n=ar.size();
    for(int i=n-1;i>=0;i--){
        if(ar[i]!=ar[i-1]){
            cout<<ar[i-1];
            break;
        }

    }
   
}
int main(){
    vector<int> ar={6,6,6,6,2};
    largest_element(ar);
}