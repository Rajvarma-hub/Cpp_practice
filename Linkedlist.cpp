#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
class Linkedlist{
    private:
    Node*head=nullptr;
    public:
    void insertatend(int input){
        if(head==nullptr){
           Node* newnode=new Node(input);
            head=newnode;
            return;

        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;

        }
        Node* newnode=new Node(input);
        temp->next=newnode;

    }
    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;}
            cout<<"NULL";
    }
    int middleofll(){
        int count=0;
        Node* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<count/2;i++){
            temp=temp->next;
        }
        return temp->data;
    }
    int middleofLLSf(){
        Node*slow=head;
        Node*fast=head;
        while(fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow->data;
    }
    void displayHead(Node* head){
        Node* temp=head;
        while(temp){
            cout<<temp->data<<"->";
            temp=temp->next;}
            cout<<"NULL";
    }
    Node* reverseLL(Node* head){
        Node*temp=head;
        Node* prev=nullptr;
        while(temp){
            Node*next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
    void detect_cycle(Node* head){
        int count=1;
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                fast=fast->next;
                while(slow!=fast){
                    fast=fast->next;
                    count++;
                   
                }
                cout<<count;
                return;
            }
        }
        cout<<"No Loop Detected";
    }
    void palindrone(Node* head){
        if(head==nullptr || head->next==nullptr){
            cout<<"True";
            return;}
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;

        }
        Node* newhead=reverseLL(slow->next);
        Node* first=head;
        Node* second=newhead;
        bool ispalindrome=true;
        while(second!=nullptr){
            if(first->data!=second->data){
                slow->next=(newhead);
                ispalindrome=false;
                break;
            }
            first=first->next;
            second=second->next;
        }
           slow->next= reverseLL(newhead);
           if(ispalindrome){
            cout<<"Palindrome";
        }else{
            cout<<"Not a Palindrome";
        }

    }


};
int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop for testing
    // fifth->next = third;
    Linkedlist ds;
    ds.displayHead(head);
     cout<<"insertion completed"<<endl;
    ds.palindrone(head);
    ds.displayHead(head);
    

   
    // ds.insertatend(1);
    // ds.insertatend(2);
    // ds.insertatend(3);
    // ds.insertatend(30);
    // ds.insertatend(3);
    // ds.insertatend(4);
    // ds.insertatend(7);
  
    // cout<<"Middle of LL"<<ds.middleofLLSf();
    // cout<<endl;
    // // Node* root=ds.reverseLL();
   
    // int pos,val;
    // cin>>pos>>val;
    // ds.insertatpostion(pos,val);
    // ds.printforward();
    // ds.printbackward();
    // int target;
    // cin>>target;
    // ds.deletebyvalue(target);
    // ds.printforward();
    
   

   
    return 0;
}
