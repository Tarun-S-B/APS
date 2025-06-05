#include<iostream>

using namespace std;

int n;

class Node {
    public:
        unsigned int data;
        Node* next;
    
    Node(unsigned int e) : data(e), next(nullptr) {}
};

class LinkList {
    public:
        Node* head;
        Node* tail;

        LinkList(): head(nullptr) {}

        //while constructing the LL
        void insert(unsigned int e) {
            if(head==nullptr) {
                head = new Node(e);
                tail = head;
                return;
            }
            Node *p = new Node(e);
            // Node *curr = head;
            // while(curr->next)
            //     curr = curr->next;
            
            // curr->next = p;
            tail->next = p;
            tail = p;
            return;            
        }

        //1 based indexing
        void insertAt(unsigned int e, int pos) {
            Node *p = new Node(e);

            if(head==nullptr) {
                head = p;
                return;
            }

            Node* curr = head;
            for(int i=1; i<n; i++) {
                curr = curr->next;
            }
            p->next = curr->next;
            curr->next = p;
            return;
        }

        // 1 based indexing of pos
        unsigned int removeAt(int pos) {
            Node *curr = head;
            Node *prev = nullptr;
            unsigned int temp;

            while(pos-- > 1) {
                prev = curr;
                curr = curr->next;
            }
            if(curr == head) {
                temp = curr->data;
                head = curr->next;
                delete(curr);
                return temp;
            }
            prev->next = curr->next;
            temp = curr->data;
            delete(curr);
            return temp;
        }
};

int main() {
    LinkList ll;
    int n;
    unsigned int x;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x;
        ll.insert(x);
    }
    for(int i=0; i<n; i++) {
        cin >> x;
        cout << ll.removeAt(x) << " ";
    }
    return 0;
}