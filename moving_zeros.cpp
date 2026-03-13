#include <iostream>
#include <unordered_map>
#include<bits/stdc++.h>

using namespace std;
void move_zerosTOEnd(vector<int>&ar){
    int j=0;
    for(int i=0;i<ar.size();i++){
        if(ar[i]!=0){
            swap(ar[i],ar[j]);
            j++;
        }
    }

}
vector<int> findunion(vector<int> ar1,vector<int> ar2,int n,int m){
    map<int,int> freq;
    vector<int> un;
    for(int i=0;i<n;i++){
        freq[ar1[i]]++;
    }
    for(int i=0;i<m;i++){
        freq[ar2[i]]++;
    }
    for(auto &it:freq){
        un.push_back(it.first);
    }
    return un;
}
vector<int> finunion(vector<int>ar,vector<int> ar2,int n,int m){
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(ar[i]);
    }
    for(int i=0;i<m;i++){
        st.insert(ar2[i]);
    }
    vector<int> un(st.begin(),st.end());
    return un;
}
vector<int> finunion_two(vector<int>ar,vector<int> ar2,int n,int m){
vector<int> res;
int i=0,j=0;
while(i<n&& j<m){
    if(ar[i]<ar2[j]){
        if(res.empty()|| res.back()!=ar[i]){
        res.push_back(ar[i]);
        i++;
        }
    }
    else if(ar2[j]<ar[i]){
        if(res.empty()|| res.back()!=ar2[j]){
            res.push_back(ar2[j]);
            j++;
        }
    }
    else{
        if(res.empty()|| res.back()!=ar[i]){
            res.push_back(ar[i]);
            i++;j++;
        }
    }
}
while(i<n){
    if(res.empty()|| res.back()!=ar[i])res.push_back(ar[i]);i++;

}
while(j<m)if(res.empty()|| res.back()!=ar[j])res.push_back(ar[j]);j++;

return res;
}

void longest_subarray(vector<int> ar,int k){
    int i=0,left=0;
    int j=ar.size();
    int maxlen=0;
    int sum=0;
    while(left<j){
        while(sum>k && i<=j){
            sum-=ar[i];
            i++;
        }
        if(sum <k){
            sum+=ar[left];
            left++;
        }else{
            int len=j-left;
            maxlen=max(maxlen,len);
            left++;
        }

    }
    cout<<"Maxlength  "<<maxlen;
}
void twosum(vector<int>ar,int k){
    sort(ar.begin(),ar.end());
    int i=0;
    int right=ar.size()-1;
    int sum=0;
    while(i<right){
       sum=ar[i]+ar[right];
       if(sum==k){
        cout<<"Yes";
        return;
       }
       if(sum>k){
        right--;
       }
       else{
        i++;

}

}
cout<<"NO";
}
void twosumhash(vector<int> ar,int k){
    unordered_set<int> s;
    for(int i=0;i<ar.size();i++){
        int need=k-ar[i];
        if(s.find(need)!=s.end()){
            cout<<"Yes";
            return;
        }
        s.insert(ar[i]);
    }
    cout<<"NO";
}
void buyandsell(vector<int> ar){
    int minprice=ar[0];
    int maxprice=0;
    for(int i=1;i<ar.size();i++){
        minprice=min(minprice,ar[i]);
        maxprice=max(maxprice,ar[i]-minprice);
    }
    cout<<"Max Profit "<<maxprice;
}
void longest_sequence(vector<int> ar){
    
}
int main() {

    int n = 9;

    int m = 7;
    vector<int> ar={7, 6, 4, 3, 1};
    vector<int> ar1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

 vector<int> ar2 = {2, 3, 4, 4, 5, 11, 12};
 
//     // Call FindUnion function
// //    / vector<int> Union = finunion(ar1, ar2, n, m);
//     // Print output messag
//     cout << "Union of arr1 and arr2 is " << endl;
//     // Print all elements of union
//     for (auto &val : Union)
//         cout << val << " ";
    // Return success
    buyandsell(ar);
    return 0;
}