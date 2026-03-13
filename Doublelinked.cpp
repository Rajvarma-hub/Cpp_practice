#include <iostream>
using namespace std;

// Node class for doubly linked list
class DNode {
public:
    int data;
    DNode* next;
    DNode* pre;
    
    DNode(int val) {
        data = val;
        next = nullptr;
        pre = nullptr;
    }
};

// Doubly linked list class
class DoubleLinkedList {
public:
    DNode* head;

    DoubleLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the end
    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (head == nullptr) {        // Empty list
            head = newNode;
            return;
        }

        DNode* temp = head;
        while (temp->next != nullptr) {   // Traverse to last node
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->pre = temp;
    }

    // Function to print all elements
    void printForward() {
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " <-> ";
            temp = temp->next;
        }
        cout << " NULL" << endl;
    }
    void remove_duplicates(){
        DNode* curr=head;
        while(curr && curr->next){
            if(curr->data == curr->next->data){
                DNode* del=curr->next;
                curr->next=del->next;
                if(del->next)del->next->pre=curr;
            }else{
                curr=curr->next;
            }
        }
    }
    void deletealloccurence(int key){
        DNode* temp=head;
        while(temp!=nullptr){
            if(temp->data==key){
                DNode* del=temp;
                if(temp==head){
                    head=temp->next;
                }
                if(temp->pre!=nullptr){
                    temp->pre->next=temp->next;
                }
                if(temp->next!=nullptr){
                    temp->next->pre=temp->pre;
                }
                temp=temp->next;
                delete del;
            }
            else{
                temp=temp->next;
            }

        }
    }
    void parisoftarget(int target){
        DNode* first=head;
        DNode* last= head;
        while(last->next!=NULL){
            last=last->next;
        }
        while(first!=nullptr && last!=nullptr && first!=last && last->next != first){
            int sum=first->data+ last->data;
            if(sum==target){
                cout<<"("<<first->data<<","<<last->data<<")"<<endl;
                first=first->next;
                last=last->pre;
            }
            else if(sum<target){
                first=first->next;
            }else{
                last=last->pre;
            }

        }
    }
};

// Main function to test
int main() {
    DoubleLinkedList dll;

    dll.insertAtEnd(1);
     
      dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.insertAtEnd(5);
    dll.insertAtEnd(6);
    

    dll.printForward();
    dll.parisoftarget(7);
    
    return 0;
}
