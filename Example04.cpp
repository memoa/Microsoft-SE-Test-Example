// Reverse Nodes

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    
    Node(char data) {
        this->data = data;
        next = NULL;
    }
};

class List {
private:
    Node* head; // pointer to first element in list
    
    int length() {
        Node* curr = head;
        int len = 0;
        
        while (curr != NULL) {
            curr = curr->next;
            ++len;
        }
        // cout << len << endl; // debug: list length
        return len;
    }

public:
    // Create empty list
    List() {
        head = NULL;
    }
    
    // Create list from static array
    List(char* arr, int len) {
        Node* prev;
        Node* curr;

        for (int i = 0; i < len; ++i) {
            curr = new Node(arr[i]);
            
            if (i == 0)
                head = curr;
            else
                prev->next = curr;
            
            prev = curr; 
            // cout << prev->val << endl; // debug: elements in list
        }
    }
    
    void ReverseNodes(Node* head, int indexA, int indexB) {
        Node* curr = head;
        // Linking iterators
        Node* L1 = NULL;
        Node* L2 = NULL;
        Node* L3 = NULL;
        
        int range = indexB - indexA;
        
        // If range is less than 2 elements, break
        if (range < 2)
            return;

        // Positioning iterators
        for (int i = 0; i < indexB - 1; ++i) {
            if (i == indexA - 2)
                L1 = curr;
            if (i == indexA - 1)
                L2 = curr;
            if (i == indexA)
                L3 = curr;
            curr = curr->next;
        }
        print_node(L3);
        // I stage: link first 2 nodes (endpoints)
        L1->next = curr;
        L2->next = curr->next;
        
        // II stage: reverse linking list in range
        for (int i = 0; i < range; ++i) {
            // Move iterators
            L1 = L2;
            L2 = L3;
            L3 = L3->next;
            // Reverse link
            L2->next = L1;
        }
    }
    
    void ReverseNodes(int indexA, int indexB) {
        ReverseNodes(head, indexA, indexB);
    }
    
    void print_node(Node* node) {
        if (node == NULL)
            return;
            
        cout << "node: " << node->data << endl;
        cout << "  next: " << ((node->next == NULL) ? '0' : node->next->data) << endl;
    }
    
    // Return static array from list elements
    char* list_to_arr() {
        Node* curr = head;
        int len = length();
        char* arr = new char(len);
        
        for (int i = 0; i < len; ++i) {
            arr[i] = curr->data;
            curr = curr->next;
            // cout << arr[i] << endl; // debug: elements in static list
        }
        return arr;
    }
};

int main()
{
    int m = 6;
    char a[] = "acxqe2";
    char* b;

    int indexA = 2;
    int indexB = 4;
    
    List list(a, m);
    list.ReverseNodes(indexA, indexB);
    b = list.list_to_arr();
    
    for (int i = 0; i < m; ++i)
        cout << b[i] << endl;
    
    return 0;
}


