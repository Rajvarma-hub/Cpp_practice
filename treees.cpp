#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int input){
        data=input;
        left=nullptr;
        right=nullptr;
    }
};

Node *build(){
    int input;
    cin>>input;
    if(input==-1)return NULL;
    Node* temp=new Node(input);
    temp->left=build();
    temp->right=build();
    return temp;
}

void inorder(Node* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->data<<"->";
    inorder(root->right);
}

int maximum(Node* input){
    if(input==NULL)return INT_MIN;
    int input1=maximum(input->left);
    int input2=maximum(input->right);
    return max(input->data,max(input1,input2));
}
int countleaft(Node* input,vector<int>& leaves){
    if(input->left==nullptr && input->right==nullptr){
        leaves.push_back(input->data);
        return 1;}
    int left=countleaft(input->left,leaves);
    int right=countleaft(input->right,leaves);
    return left+right;
}
int main(){
    Node* root=build();
    inorder(root);
    vector<int>leaves;
    int max=countleaft(root,leaves);
    cout<<"Maximum value: "<<max;
    for(int x:leaves)cout<<x<<" ";
}


