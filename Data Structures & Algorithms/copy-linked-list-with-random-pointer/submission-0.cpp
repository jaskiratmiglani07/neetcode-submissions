class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*>mp;
        Node* curr = head;
        Node* prev = nullptr;
        Node* newHead = nullptr;
        while(curr){
            Node* temp = new Node(curr->val);
            mp[curr] = temp;
            if(newHead == nullptr){
                newHead = temp;
                prev = temp;
            }else{
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }
        curr = head;
        Node* newCurr = newHead;
        while(curr){
            newCurr->random = mp[curr->random];
            curr = curr->next;
            newCurr = newCurr->next;
        }
        return newHead;
    }
};
