#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int get_second_largest(vector<int> &arr){
  int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=n-2;i>=0;i--){
      if(arr[i]!=arr[n-1]){
        return arr[i];
      }
      return -1;
    }
  }
int second_lar(vector<int> &arr){
  int n=arr.size();
  int largest=-1,sec_large=-1;
  for (int i=0;i<n;i++){
    if(arr[i]>largest){
      sec_large=largest;
      largest=arr[i];

    }
    else if(arr[i]<largest && arr[i]>sec_large){
      sec_large=arr[i];
    }
  }
  return sec_large;

}
  int main(){
    vector<int> arr={12, 35, 1, 10, 34, 1};
    int second_largest=second_lar(arr);
    cout<<second_largest;
  }