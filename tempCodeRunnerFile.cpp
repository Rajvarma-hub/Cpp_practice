void lengthofthecycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            // Cycle detected, now count the length
            int counter = 1;
            fast = fast->next;
            while (fast != slow) {
                counter++;
                fast = fast->next;
            }
            cout << counter;
            return;
        }
    }
    return;
}
