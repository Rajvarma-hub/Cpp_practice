#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void total_sum(vector<int> ar){
    int sum=0;
    int n=INT_MIN;
    for(int x:ar)n=max(n,x);
    for(int x: ar)sum+=x;
    int total=n*(n+1)/2;
    int number=total-sum;
    cout<<"Missing number"<< number;

}
int total_sum_bit(vector<int> ar){
    int n = ar.size()+1;
    int result = 0;

    for(int i = 1; i <= n; i++) result ^= i;
    for(int x : ar) result ^= x;

    return result;
}
void increasing_array(vector<int> ar){
    int totalMoves=0;
    for(int i=0;i<ar.size();i++){
        if(ar[i+1]<ar[i]){
            int dif=ar[i]-ar[i+1];
            totalMoves+=dif;
        }
    }
    cout<<totalMoves;
}
void max_frequency(string s){
    vector<int> freq(26);
    for(char c: s)freq[(int)c-'A']++;
    int maxLength=INT_MIN;
    for(int x:freq)maxLength=max(x,maxLength);
    cout<<"Maximum Length: "<<maxLength;


}
int main(){
    vector<int> ar={3,2,5,1,7};
    string s="AATTTTTGGGHH";
    // max_frequency(s);
//    int res= total_sum_bit(ar);
//    cout<<res;
     increasing_array(ar);


}