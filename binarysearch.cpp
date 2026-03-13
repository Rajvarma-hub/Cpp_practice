#include <bits/stdc++.h>
using namespace std;

void binarysearch(const vector<int>& ar, int target) {
    int low = 0, high = ar.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ar[mid] == target) {
            cout << "Target found at index " << mid << endl;
            return;
        } else if (ar[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Element not found in the array" << endl;
}

// Finds the minimum element in a rotated sorted array
void minimum_element(const vector<int>& ar) {
    int low = 0, high = ar.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (ar[mid] > ar[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    cout << "Minimum element is " << ar[low] << endl;
}
int target(vector<int>&ar,int low,int high,int value){
    if(low>high)return -1;
    int mid=(low+high)/2;
    if(ar[mid]==value)return mid;
    else if(ar[mid]>value){
        target(ar,low,mid-1,value);

    }else{
        target(ar,mid+1,high,value);
    }
}
int main() {
    vector<int> ar = {1,2,3,4,5,6,7,8,9};
    int valuet = 9;
   int res=target(ar,0,ar.size()-1,valuet);
   cout<<"Result"<<res;
   
    return 0;
}