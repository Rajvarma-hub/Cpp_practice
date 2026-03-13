#include<bits/stdc++.h>
using namespace std;
void insertheap(vector<int>&heap,int val){
    heap.push_back(val);
    int idx=heap.size()-1;
    while(idx>0){
        int parent=(idx-1)/2;
        if(heap[parent]<heap[idx]){
            swap(heap[parent],heap[idx]);
            idx=parent;
        }else break;
    }
}
void heapifydown(vector<int>&heap,int idx){
    int n=heap.size();
    while(true){
        int largest=idx;
        int left=2*idx+1;
        int right=2*idx+2;
        if(left<n && heap[left]>heap[largest])largest=left;
        if(right<n && heap[right]>heap[largest])largest=right;
        if(largest!=idx){
            swap(heap[largest],heap[idx]);
            idx=largest;
        }else break;
    }
}
int main(){
    vector<int>heap={50, 30, 40, 10, 20};
    insertheap(heap,60);
    for(int x:heap)cout<<x<<" ";
    heap[0]=heap.back();
    heap.pop_back();
    heapifydown(heap,0);
     for(int x:heap)cout<<x<<" ";
}