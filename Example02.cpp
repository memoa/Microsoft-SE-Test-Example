// TreeNode

#include <iostream>
using namespace std;

struct TreeNode {
  int value;
  TreeNode* sibling;
  TreeNode* firstChild;
  
  TreeNode(int value) {
      this->value = value;
      sibling = NULL;
      firstChild = NULL;
  }
};

struct Stack_element {
    TreeNode* element;
    Stack_element* prev;
    
    Stack_element(TreeNode* element) {
        this->element = element;
        prev = NULL;
    }
};

// Helper class for tracking parent nodes in node tree
class Stack {
private:
    Stack_element* top;

public:
    Stack() {
        top = NULL;
    }
    
    void push(TreeNode* element) {
        Stack_element* new_elem = new Stack_element(element);
        new_elem->prev = top;

        top = new_elem;
        // cout << "push: " << top->element << " -> " << top->element->value << endl;
    }
    
    TreeNode* pop() {
        Stack_element* prev;
        TreeNode* element = top->element;
        if (top == NULL) {
            prev = NULL;
            element = NULL;
        }
        else {
            prev = top->prev;
            element = top->element;
            // cout << "pop: " << top->element << " <- " << element->value << endl;
            delete top;
            top = prev;
        }
        
        return element;
    }
    
    TreeNode* top_stack() {
        if (top == NULL)
            return NULL;
        else {
            //cout << "top stack: " << top->element << " -> " << top->element->value << endl;
            return top->element;
        }
    }
};

// Node tree
class Tree {
private:
    TreeNode* root;
  
public:
    Tree() { // create empty tree
        root = NULL;
    }
    
    // Create node tree from static array
    Tree(int* a, int m) { // 
        TreeNode* prev = NULL; // parent node
        TreeNode* curr; // current node
        
        Stack stack; // parent nodes tracker
        
        int even = 0; // count of even nodes
        
        int i = 0;
        while (i < m) { // iterate through static array
            curr = new TreeNode(a[i]); // create current node
            if (i == 0)
                root = curr;
            else {
                // If parent node exists, linking, else skip linking
                if (prev != NULL) { 
                    // If parent is odd, link: parent -> firstChild -> current
                    if ((prev->value) % 2 == 1) { 
                        prev->firstChild = curr;
                        even = 0;
                    }
                    // If parent is even
                    else {
                        // Count adjacent even nodes
                        // Second adjasent even node is leaf
                        ++even; 
                        // If parent is leaf, find first free parent with free sibling link
                        if (even > 1) {
                            stack.pop();
                            do { // reset parent node to first parent with free sibling link
                                prev = stack.pop();
                            } while (prev->sibling != NULL);
                            even = 0;
                        }
                        // Link: parent -> sibling -> current
                        prev->sibling = curr;
                    }
                }
            }
            
            stack.push(curr); // track current node
            prev = curr; // parent is now current node
            ++i; // static array iterator
        }
    }
    
    // Debug: Helper method for printing nodes 
    void print_node(TreeNode* node) {
        if (node == NULL) {
            cout << "node: NULL" << endl;
            return;
        }
        
        cout 
            << "node: " << node->value
            << "\n  first child: " << ((node->firstChild != NULL) ? node->firstChild->value : 0)
            << "\n  sibling: " << ((node->sibling != NULL) ? node->sibling->value : 0)
            << endl;
    }
    
    // Walk through node tree using recursion
    void pre_order(TreeNode* node) {
        if (node == NULL)
            return;
        
        print_node(node); // debug: print current node
        //cout << node->value << endl;
        
        if (node->firstChild != NULL)
            pre_order(node->firstChild);
        
        if (node->sibling != NULL)
            pre_order(node->sibling);
    }
    
    // Walk through node tree starting from root
    void pre_order() {
        pre_order(root);
    }
};

int main() {
    int m = 9;
    int a[] = { 3, 1, 4, 48, 2, 5, 3, 6, 18 };
    
    // Debug: test stack
    /*
    Stack stack;
    for (int i = 0; i < m; ++i)
        stack.push(new TreeNode(a[i]));
    
    for (int i = 0; i < m; ++i)
        stack.pop();
    */
    
    Tree tree(a, m);
    tree.pre_order();
    
    return 0;
}



