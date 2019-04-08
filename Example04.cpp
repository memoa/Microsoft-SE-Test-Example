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
    Node* head; // pointer to first node in list
    
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
    
    // Create list from array
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
            // cout << prev->val << endl; // debug: nodes in list
        }
    }
    
    void reverseNodes(Node** head, int indexA, int indexB) {
        int range = indexB - indexA;
        
        // If range is less than 2 elements, break
        if (range < 2)
            return;

        Node* curr = *head;
        // Reverse linking pointers
        Node* L1 = NULL;
        Node* L2 = NULL;
        Node* L3 = NULL;
        
        // Positioning pointers
        for (int i = 1; i < indexB; ++i) {
            if (i == indexA - 1)
                L1 = curr;
            if (i == indexA)
                L2 = curr;
            if (i == indexA + 1)
                L3 = curr;
            curr = curr->next;
        }

        // I stage: link nodes at range endpoints
        if (L1 == NULL) // if range starts from first node in list
            *head = curr;
        else
            L1->next = curr;
        
        L2->next = curr->next;

        // II stage: reverse linking list nodes in range
        for (int i = 0; i < range; ++i) {
            // Move pointers
            L1 = L2;
            L2 = L3;
            L3 = L3->next;
            // Reverse link
            L2->next = L1;
        }
    }
    
    void reverseNodes(int indexA, int indexB) {
        reverseNodes(&head, indexA, indexB);
    }
    
    void print_node(Node* node) {
        if (node == NULL)
            return;
            
        cout << "node: " << node->data << endl;
        cout << "  next: " << ((node->next == NULL) ? '0' : node->next->data) << endl;
    }
    
    // Return array from list elements
    char* list_to_arr() {
        Node* curr = head;
        int len = length();
        char* arr = new char(len);
        
        for (int i = 0; i < len; ++i) {
            arr[i] = curr->data;
            curr = curr->next;
            // cout << arr[i] << endl; // debug: elements in array
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
    
    // int indexA = 1;
    // int indexB = 3;
    
    // int indexA = 4;
    // int indexB = 6;
    
    // int indexA = 1;
    // int indexB = 6;
    
    List list(a, m);
    list.reverseNodes(indexA, indexB);
    b = list.list_to_arr();
    
    for (int i = 0; i < m; ++i)
        cout << b[i] << endl;
    
    return 0;
}
