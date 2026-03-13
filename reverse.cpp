#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> &ar){
    int n=ar.size();
    for(int i=0;i<n/2;i++){
        swap(ar[i],ar[n-i-1]);
    }
    for(int x: ar){
        cout<<x<<" ";
    }

}

int main(){
    vector<int> ar={5,4,3,2,1};
    reverse(ar);

}