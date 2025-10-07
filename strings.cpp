#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void reverse_string_brute(string s){
    stack<string> st;
    string word="";
    s+=" ";
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            st.push(word);
            word="";
        }else{
            word+=s[i];
        }

    }
    string ans="";
    while(st.size()!=1){
        ans+=st.top()+" ";
        st.pop();
    }
    ans+=st.top();
    cout<<ans;
}
void reverse_string_optimal(string s){
    int left=0;
    int right=s.size()-1;
    string temp="";
    string ans="";
    while(left<=right){
        char c=s[left];
        if(c!=' '){
            temp+=c;
        }else if(c==' '){
            if(ans!="")ans=temp+" "+ans;
            else ans=temp;
            temp="";
        }
        left++;
    }
    if(temp!="")ans=temp+" "+ans;
    else ans=temp;
    cout<<ans;

}
void anagram_bruteforce(string s,string p){
    if(s.size()!=p.size())return;
    sort(s.begin(),s.end());
    sort(p.begin(),p.end());
    if(s==p){
        cout<<"They are anagrams";
    }else{
        cout<<"Not anagrams";
    }

}
void anagram_optima(string s,string p){
    if(s.size()!=p.size())return;
    vector<int>count(26,0);
    for(char c:s)count[c-'a']++;
    for(char c:p)count[c-'a']--;
    for(int x:count){
        if(x!=0)return;

    }
    cout<<"they are anagrams";
}
class sortcharcter{
    public:
    static bool comparator(pair<int,char>p1,pair<int,char>p2){
        if(p1.first>p2.first)return true;
        if(p1.first<p2.first)return false;
        return p1.second< p2.second;
    }
    void frequencysort(string& s){
        pair<int,char> freq[26];
        for(int i=0;i<26;i++){
            freq[i]={0,i+'a'};

        }
        for(char ch:s){
            freq[ch-'a'].first++;

        }
        sort(freq,freq+26,comparator);
        string res;
        for(int i=0;i<26;i++){
            if(freq[i].first>0){
                res.push_back(freq[i].second);
            }
        }
        cout<<"Answer is "<<res;
    }
};
void maximum_depth(string s){
    int depth=0;
    int max_depth=0;
    for(char c:s){
        if(c=='('){
            depth++;
            max_depth=max(max_depth,depth);
        }
        else if(c==')')depth--;
    }
    cout<<"Max depth of the paranthesis"<<max_depth;
}
void custom_atoi(string s){
    int n=1,res=0;
  for(char c:s){
    if(c==' ')continue;
    if(c=='-'){
        n*=-1;
        continue;
    }
    if(isdigit(c)){
        int digit=c-'0';
        res=res*10+digit;

    }
    if(!isdigit(c)){
        return;
    }
  }
  cout<<res;
}
void sum_of_beauty(string s){
    int total=0;
  for(int i=0;i<s.length();i++){
    vector<int> freq(26,0);
    for(int j=i;j<s.length();j++){
        freq[s[j]-'a']++;
        
        int minele=INT_MAX,maxelem=0;
        for(int x :freq){
            if(x>0){
                minele=min(minele,x);
                maxelem=max(maxelem,x);
            }
        }
        total+=(maxelem-minele);
    }
    
  }
  cout<<"Total length of the beauty of the string"<<total<<endl;
}
int main(){
    // cout<<"Enter the String to reverse ";
    // string input;
    // cin.ignore(); 
    // getline(cin, input);
    // reverse_string_optimal(input);
    string inp;
    // cout<<"Enter the first one"<<endl;
    // cin>>input;
    // // cout<<"Enter the second one"<<endl;
    // // cin>>inp;
    // // anagram_optima(input,inp);

    // sortcharcter s;
    // s.frequencysort(input);
    string s = "aabcb";
    sum_of_beauty(s);

}