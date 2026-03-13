#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int>& ar){
    int n=ar.size();
    for(int i=0;i<n;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(ar[j]>ar[j+1]){
                swap(ar[j],ar[j+1]);
                swapped=true;
            }
        }
        if(!swapped)break;
    }


}
void insertion_sort(vector<int>& ar){
    int n=ar.size();
    for(int i=1;i<n;i++){
        int key=ar[i];
        int j=i-1;
        while(j>=0 && ar[j]>key){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=key;

    }
}
void selection_sort(vector<int>& ar){
    int n=ar.size();
    for(int i=0;i<n;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(ar[j]<ar[minIndex]){
                minIndex=j;
            }
        }
        swap(ar[i],ar[minIndex]);
    }
}

int max_min_sum(vector<int>ar,int k){
    multiset<pair<int,int>>mp;
    int i=0,j=0;
    int sum=0;
    while(j<ar.size()){
        mp.insert({ar[j],j});
        if(j-i+1==k){
            int min=mp.begin()->first;
            int max=mp.rbegin()->first;
            sum+=(max+min);
            mp.erase({ar[i],i});
            i++;


        }
        j++;
    }
    return sum;
}
void count_distinct(vector<int>ar,int k){
    vector<int>res;
    unordered_map<int,int>mp;
    for(int i=0;i<k;i++){
        mp[ar[i]]+=1;
    }
    res.push_back(mp.size());
    for(int i=k;i<ar.size();i++){
        mp[ar[i]]+=1;
        mp[ar[i-k]]-=1;
        if(mp[ar[i-k]]==0)mp.erase(ar[i-k]);
        res.push_back(mp.size());
    }
    for(int x:res)cout<<x<<" ";
}
int main(){
    vector<int> ar={2, 5, -1, 7, -3, -1, -2};
    count_distinct(ar,4);

}