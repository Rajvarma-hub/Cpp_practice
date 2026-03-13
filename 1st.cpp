#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int largest_element(vector<int> ar){
    int n=ar.size();
    int max_ele=0;
    for(int i=0;i<n;i++){
        if(ar[i]>=max_ele){
            max_ele=ar[i];
        }
    }
    return max_ele;
}
void second_largest_smallest(vector<int> ar){
    int n=ar.size();
    int second_largest=INT_MIN,second_smallest=INT_MAX,largest=INT_MIN,smallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(ar[i]>largest){
             second_largest=largest;
            largest=ar[i];
           
        }
        else if(ar[i]>second_largest&& ar[i]!=largest){
            second_largest=ar[i];
        }
        if(ar[i]<smallest){
            second_smallest=smallest;
            smallest=ar[i];
            
        }

        else if(ar[i]<second_smallest && ar[i]!=smallest){
            second_smallest=ar[i];
        }
    
        
    }
    if(second_largest==INT_MIN){
        cout<<"NO second largest element";
    }
    else if(second_smallest==INT_MAX){
        cout<<"No second smallest element";
    }else{
    cout<<"Second_Largest: "<<second_largest<<endl;
    cout<<"Second_Smallest"<<second_smallest;
    }
    

}
void check_array_sorted(vector<int> ar){
    int n=ar.size();
    bool asc=true,desc=true;
    for(int i=0;i<n-1;i++){
       if(ar[i]>ar[i+1])asc=false;
       if(ar[i]<ar[i+1])desc=false;
        
    }

    if(asc){
        cout<<"The array is sorted in ascending";
    }else if(desc){
        cout<<"The array is sorted in Descending order";
    }
    else{
        cout<<"The array is not sorted";
    }

}
void remove_duplicates(vector<int> ar){
    int n=ar.size();
    vector<int>unique;
    int pointer1=0,pointer2=0;
    for(int i=0;i<n;i++){
        if(!(ar[pointer1]==ar[pointer2+1+i])){
            unique.push_back(ar[pointer1]);
            pointer1=i+1;
        }
    }
    for(int x :unique)cout<<x<<" ";
}
void reversed(vector<int> ar,int start,int end){
    while(start<end){
        int temp=ar[start];
        ar[start]=ar[end];
        ar[end]=temp;
        start++;
        end--;
    }
}
void rotatearraybyone(vector<int>& ar,int d){
    int n=ar.size();
    int k=d%n;
    reverse(ar.begin(),ar.begin()+k);
    reverse(ar.begin()+k,ar.end());
    reverse(ar.begin(),ar.end());
}
void missingnumber(vector<int>ar){
    int n=ar.size();
    int missing;
    cout<<"Executing the missing value";
    for(int i=n-1;i>=0;i--){
        missing=ar[i]-ar[0];
        if(!missing==ar[i-1]){
            cout<<"Missing value is"<<missing<<endl;
        }
    }
}void unionele(const vector<int>& ar, const vector<int>& arr) {
    vector<int> temp;
    int n = ar.size(), m = arr.size();
    int i = 0, j = 0;

    // Traverse both arrays using two pointers
    while (i < n && j < m) {
        if (ar[i] < arr[j]) {
            if (temp.empty() || temp.back() != ar[i])
                temp.push_back(ar[i]);
            i++;
        }
        else if (ar[i] > arr[j]) {
            if (temp.empty() || temp.back() != arr[j])
                temp.push_back(arr[j]);
            j++;
        }
        else { // ar[i] == arr[j]
            if (temp.empty() || temp.back() != ar[i])
                temp.push_back(ar[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements from ar
    while (i < n) {
        if (temp.empty() || temp.back() != ar[i])
            temp.push_back(ar[i]);
        i++;
    }

    // Add remaining elements from arr
    while (j < m) {
        if (temp.empty() || temp.back() != arr[j])
            temp.push_back(arr[j]);
        j++;
    }

    // Print the union
    for (int x : temp)
        cout << x << " ";
    cout << endl;
}
void consecutive_ones(vector<int> ar){
    int count=0;
    int max=0;
    for(int i=0;i<ar.size();i++){
        if(ar[i]!=0){
            count++;
        }else{
            if(count>max)
              max=count;
            count=0;
        }
    }
    if(count>max)max=count;
    cout<<"Maximum consecutive ones"<<max;
}
void numberappearonce(vector<int>ar){
    unordered_map<int,int> freq;
    for(int x:ar){
        freq[x]++;
    }
    for(auto x:freq){
        if(x.second==1){
            cout<<x.first<<" ";
        }
    }
    
}
void twosum(vector<int> ar,int target){
    int n=ar.size(),k=0,j;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ar[i]+ar[j]==target && i!=j){
                cout<<ar[i]<<" "<<ar[j]<<" ";
                cout<<i<<" "<<j<<endl;
            }
        }
        


    }


}
void sortzerosones(vector<int> ar){
    int n=ar.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(ar[i]>ar[j]){
                swap(ar[i],ar[j]);
            }

        }
    }
}


void largestsubarray(vector<int> ar,int tar){
    int n=ar.size();
    int max_len=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=ar[j];
        
        if(sum==tar){
            max_len=max(max_len,j-i+1);

        }
    }
    }
    cout<<"Maximum length"<<max_len<<endl;

}
void majorityelement(vector<int> ar){
    int size=ar.size();
    int count=0,element;
    int n=size/2;
    for(int i=0;i<size;i++){
        if(count==0){
            element=ar[i];
            count++;
        }
        else if(count!=0 && ar[i]==element){
            count++;
        }
        else{
            count--;
        }
    }
    count=0;
    for(int x :ar){
        if(x ==element)count++;
    }
    if(count>n){
        cout<<"Majority element is "<<element;
    
    }else{
        cout<<"There is not majority element";
    }
}
void maximum_sum(vector<int> ar){
    int max_sum=INT_MIN;
    int n=ar.size();
    for(int i=0;i<n;i++){
         int sum=0;
        for(int j=i;j<n;j++){
                sum+=ar[j];
            
            
        }
        max_sum=max(max_sum,sum);
    }
    cout<<max_sum;
}
void buyandsell(vector<int>ar){
    int max_profit=0;
    int n=ar.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            sum=ar[j+1]-ar[i];
            max_profit=max(max_profit,sum);

        }
    }
    cout<<"Maximum profit that could be earnned  "<<max_profit<<endl;
}
void leaders(vector<int> ar){
    int n=ar.size();
    for(int i=0;i<n;i++){
        if(ar[i]>ar[i+1]){
            cout<<ar[i]<<" ";
        }
        // if(i==n-1){
        //     cout<<ar[i];
        // }
    }
}
void subsequence(vector<int> ar){
    int n=ar.size();
    

}
void max_freq(vector<int> ar){
    int n=ar.size();
    unordered_map<int,int> freq;
    for(int x:ar){
        freq[x]++;
    }
    int minfreq=n,maxfreq=0,minele,maxele;
    for(auto it : freq){
        int freq=it.second;
        int element=it.first;
        if(freq>maxfreq){
            maxfreq=freq;
            maxele=element;
        }
        if(freq<minfreq){
            minfreq=freq;
            minele=element;
        }

    }
    cout<<"Highest Frequency element is "<<maxele<<endl;
    cout<<"Lowest frequency element is"<<minele;
    
}
void max_freq_count(vector<int> ar,int k){
    int n=ar.size();
    int cnt=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ar[i]-ar[j]<=k && i!=j){
                if(cnt==n){
                    cout<<cnt;
                    return;
                }
                cnt+=1;
            }
        }
    }
}
void lower_bound(vector<int> ar,int k){
    int n=ar.size();
    int low=0,high=n-1;
    int ans;
    while(low<=high){
        int mid=(low+high)/2;
        
        if(ar[mid]>=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans;
}
void last_occurence(vector<int> ar,int target){
    int low=0,high=ar.size()-1;
    int ans;
    while(low<=high){
        int mid=(low+high)/2;
        if(ar[mid]>=target){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
}
void searchRange(vector<int>& ar, int target) {
    vector<int> res(2, -1);
    int n = ar.size();

    int low = 0, high = n - 1, ans = -1;
    // Find first occurrence (lower bound)
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ar[mid] == target) {
            ans = mid;
            high = mid - 1; // keep searching left
        } else if (ar[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    res[0] = ans;

    // Find last occurrence (upper bound - 1)
    int start = 0, end = n - 1, ans1 = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (ar[mid] == target) {
            ans1 = mid;
            start = mid + 1; // keep searching right
        } else if (ar[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    res[1] = ans1;

    for (int x : res) cout << x << " ";
}
void count_occurences(vector<int> ar,int target){
    int n=ar.size()-1;
    int ans=-1,ans1=-1;
    int low=0,high=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(ar[mid]==target){
            ans=mid;
            high=mid-1;
        }else if (ar[mid]<target){
            low=mid+1;
        }else{
            high=mid-1;

        }
    }
    int start=0,end=n;
    while(start<=end){
        int mid=(start+end)/2;
        if(ar[mid]==target){
            ans1=mid;
            start=mid+1;
        }else if(ar[mid]<target){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    int occ=(ans1-ans)+1;
    cout<<"Occurences"<<occ<<endl;
}
int rotated_array(vector<int> ar,int target){
    int n=ar.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(ar[mid]==target){
            return mid;
        }
        if(ar[low]<=ar[mid]){
            if(ar[low]<=target && target<=ar[mid]){
                high=mid-1;


              }
              else{
                low=mid+1;
              }
        }else{
            if(ar[mid]<=target && target<=ar[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

    }
}
bool find_postion_rotatedarray(vector<int> ar,int target){
    int n=ar.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(ar[mid]==target)return true;
        if(ar[low]<=ar[mid]){
            if(ar[low]<=target && target<=ar[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(ar[mid]<=target && target<=ar[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return false;

}
void find_minium(vector<int> ar){
    int low=0,high=ar.size()-1;
    while(low<high){
        int mid=(low+high)/2;
        if(ar[mid]>ar[high]){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    cout<<"Minimum element is "<<ar[low];
}
void minumum_element_sortedarray(vector<int> ar){
    int low=0,high=ar.size()-1;
    while(low<high){
        int mid=(low+high)/2;
        if(ar[mid]>ar[high])low=mid+1;
        else high=mid;


    }
    cout<<ar[low];
}
void find_howmany_time_rotated(vector<int> ar){
    int low=0,high=ar.size()-1;
    while(low<high){
        int mid=(low+high)/2;
        if(ar[mid]>ar[high])low=mid+1;
        else high=mid;
    }
    cout<<"How many time array is rotated "<<(ar.size()-low);
}
void countfrequ3(vector<int> ar){
    int count1=0,count2=0,c1=0,c2=0;
    vector<int>res;
    for(int x:ar){
        if(x==c1){count1++;}
        else if(x==c2)count2++;
        else if(c1==0){c1=x;count1++;}
        else if(c2==0){c2=x;count2++;}
        else{count1--;count2--;}
    }
    count1=0;count2=0;
    for(int x:ar){
        if(x==c1)count1++;
        else if(x==c2)count2++;
    }
    if(count1>(ar.size())/3){
        res.push_back(c1);
    }
    if(count2>(ar.size())/3){
        res.push_back(c2);
    }
    for (int x:res)cout<<x<<" ";
}
void threesumproblem(vector<int> ar){
    int n=ar.size();
    set<vector<int>>fina;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(ar[i]+ar[j]+ar[k]==0){
                    vector<int>temp={ar[i],ar[j],ar[k]};
                    sort(temp.begin(),temp.end());
                    fina.insert(temp);
                    
                }
            }
        }
    }

}
void squareofnumber(int n){
    int low=1,high=n;
    while(low<=high){
        long long mid=(low+high)/2;
        long long res=mid*mid;
        if(res<=n){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<"Square root is"<<high;
}
void rotate_array(vector<int> ar,int k){
    int n=ar.size();
    k=k%n;
    vector<int>temp(k);
    for(int i=n-k;i<n;i++){
        temp[i-n+k]=ar[i];
    }
    for(int i=n-k-1;i>=0;i--){
        ar[i+k]=ar[i];
    }
    for(int i=0;i<k;i++){
        ar[i]=temp[i];
    }
    for(int x:ar)cout<<x<<" ";


}
void rotatearrayleft(vector<int> ar,int k){
    int n=ar.size();
    vector<int> tmp(k);
    for(int i=0;i<k;i++){
        tmp[i]=ar[i];
    }

}
void largestsubarraykpositives(vector<int>ar,int k){
    int n=ar.size();
    int left=0,right=0;
    int sum=ar[0];
    int Maxlen=0;
    while(right<n){
        while(left<=right && sum>k){
            sum-=ar[left];
            left++;
        }
        if(sum==k){
            int length=right-left+1;
            Maxlen=max(Maxlen,length);
        }
        right++;
        if(right<n)sum+=ar[right];
    }
    cout<<"Maximum length of the subarray is "<<Maxlen;

}
void largestsubarraykpositivesbrueforce(vector<int> ar, int k){
    
    int n=ar.size();
    int maxlen=0,maxstar=0,maxend=0;
    for(int i=0;i<n;i++){
        long long sum=0;
        for(int j=i;j<n;j++){
            sum+=ar[j];
            if(sum==k){
                int length=j-i+1;
                if(length>maxlen){
                    maxlen=length;
                    maxstar=i;
                    maxend=j;
                }

            }
        }
    }
    cout<<"Maximum length of the subarray is "<<maxlen;
    cout<<"Starting index of subarray: "<<maxstar<<" ending index of the subarray: "<<maxend;
    cout<<"{";
    while(maxstar<=maxend){
        cout<<ar[maxstar]<<",";
        maxstar++;
    }cout<<"}";
}
int main(){
    vector<int>ar={5,4,2,-1,5,-3,1};
    vector<int> ab={4,5,5,5,4,4,8,9};
    int n;
    largestsubarraykpositivesbrueforce(ar,4);
  
}