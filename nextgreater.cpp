#include<bits/stdc++.h>
using namespace std;

void next_greater(vector<int> ar){
    stack<int> st;
    int n = ar.size();
    vector<int> res(n, -1);

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= ar[i]){
            st.pop();
        }

        if(!st.empty()){
            res[i] = st.top();
        }

        st.push(ar[i]);
    }

    for(int x : res) cout << x << " ";
}
void previous_greater(vector<int>ar){
    int n=ar.size();
    vector<int>res(n,-1);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()<=ar[i])st.pop();
        if(!st.empty())res[i]=st.top();
        st.push(ar[i]);
    }
    for(int x:res)cout<<x<<" ";
    
}
int main(){
    vector<int> ar = {2, 1, 13, 4, 5};
    cout<<"NextGreater";
    next_greater(ar);
    cout<<endl;
    cout<<"Previous Greater";
    previous_greater(ar);
    return 0;
}
