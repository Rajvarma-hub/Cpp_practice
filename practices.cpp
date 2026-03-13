#include <bits/stdc++.h>
using namespace std;

void majority_element(vector<int>& ar) {
    int max_val = *max_element(ar.begin(), ar.end());
    int n = ar.size();
    vector<int> res;
    vector<int> freq(max_val + 1, 0);

    for (int x : ar) {
        freq[x]++;
    }

    int cs = n / 3;

    for (int i = 0; i <= max_val; i++) {
        if (freq[i] > cs) {   // change to >= if needed
            res.push_back(i);
        }
    }

    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> ar = {3, 2, 3};
   
    string s="123";
    int res=0;
    int i=0;
    while(s[i+1]>s[i] && i<s.length()){
        cout<<"True";
        res=10*res+(s[i]-'0');
        i++;

    }
    cout<<res;
}
