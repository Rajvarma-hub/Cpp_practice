#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void largest_element(vector<int>arr){
    sort(arr.begin(),arr.end());
    cout<<arr[arr.size()-1];
}
void largest_max(vector<int> ar){
    int largest=INT_MIN;
    int smallest=INT_MAX;
    int second_largest=INT_MIN;
    int second_smallest=INT_MAX;


    for(int x:ar){
        if(x>largest){
            second_largest=largest;
            largest=x;
        }
        else if(x>second_largest && x!=largest){
            second_largest=x;
        }
      if(x<smallest){
        second_smallest=smallest;
        smallest=x;
      }
      else if(x<second_smallest && x!=smallest){
        second_smallest=x;
      }
    }
    cout<<"largest "<<largest<<"Second large "<<second_largest<<endl;
    cout<<"smallest "<<smallest<<"Second smallest "<<second_smallest;
}
void check_array_sorted(vector<int>ar){
    
    for(int j=1;j<ar.size();j++){
        if(ar[j-1]>ar[j]){cout<<"not sorted";
            return;}
    }
    cout<<"Sorted";
}
void remove_duplicates_sorted(vector<int>& ar){
    int i=0;
    for(int j=1;j<ar.size();j++){
        if(ar[i]!=ar[j])
        i++;
        ar[i]=ar[j];
    }
    ar.resize(i+1);
    for(int x:ar){
    cout<<x<<" ";
}
}
void left_rotate_d(vector<int> &ar,int d){
    int k=d%ar.size();
    reverse(ar.begin(),ar.begin()+k);
    reverse(ar.begin()+k,ar.end());
    reverse(ar.begin(),ar.end());
      for(int x:ar){
    cout<<x<<" ";
}
}
void right_rotate(vector<int> &ar,int d){
    int k=d%ar.size();
    reverse(ar.begin(),ar.end());
    reverse(ar.begin(),ar.begin()+k);
    reverse(ar.begin()+k,ar.end());
      for(int x:ar){
    cout<<x<<" ";
}

}
void move_zeros(vector<int> ar){
    int i=0;
    for(int j=1;j<ar.size();j++){
        if(ar[j]!=0){
            ar[i]=ar[j];
            i++;
        }
    }
    while(i<ar.size()){
        ar[i]=0;
        i++;
    }
         for(int x:ar){
    cout<<x<<" ";
}
}
void find_missing_value(vector<int> ar){
    int n=*max_element(ar.begin(),ar.end());
    int apsum=(n*(n+1))/2;
    cout<<apsum;
    int sum=0;
    for(int x:ar){
        sum+=x;
    }
    cout<<sum;
    int missing=apsum-sum;
    cout<<"Missing number: "<<missing;

}
void consicuteive_ones(vector<int> ar){
    int count=0;
    int maximun=0;
    for(int i=0;i<ar.size();i++){
        if(ar[i]!=0){count++;
        maximun=max(maximun,count);}
        else count=0;
    }
    cout<<count;
    cout<<"Max"<<maximun;
}
void unionof(vector<int> ar,vector<int> br){
    vector<int> cr;
    int n=ar.size();
    int m=br.size();
    int i=0,j=0;
    while(i<n && j<m){
        if(ar[i]==br[j]){
            cr.push_back(ar[i]);
            i++;
            j++;
        }else if(ar[i]<br[j]){
            cr.push_back(ar[i]);
            i++;
        }else {
            cr.push_back(br[j]);
            j++;
    }
}
    while(i<n){
        cr.push_back(ar[i]);
        i++;
    }
    while(j<m){
        cr.push_back(br[j]);
        j++;
    }
    for(int x:cr){
    cout<<x<<" ";
}

}
void max_subarray(vector<int> ar,int k)
{
    int left=0,right=0;
    long long sum=ar[0];
    int maxe=0;
    int leftin=-1,rightin=-1;
    while(right<ar.size()){
        while(left<=right && sum>k){
            sum-=ar[left];
            left++;
        }
        if(sum==k){
            int length=right-left+1;
            if(length>maxe){
                maxe=length;
                leftin=left;
                rightin=right;
            }

        }
        right++;
        if(right<ar.size())sum+=ar[right];
    }
    cout<<"Maximum length"<<maxe<<endl;
    while(leftin<=rightin){
        cout<<ar[leftin]<<" ";
        leftin++;
    }
    
}
int main(){
    vector<int> ar={ 1, 1, -1, 1, 1, 1,1,1,-1};
    max_subarray(ar,5);
}