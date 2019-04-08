// Are Strings Isomorphic?

#include <iostream>
using namespace std;

struct Char_dict {
private:
    char* key;
    char* val;
    int count;

public:
    Char_dict(int maxLength) {
        key = new char[maxLength];
        val = new char[maxLength];
        count = 0;
    }
    
    bool check_keyval(char key, char val) {
        for (int i = 0; i < count; ++i) {
            if (key == (this->key)[i] && val == (this->val)[i])
                return true; // pair found and completely match
            else if (
                key == (this->key)[i] && val != (this->val)[i] ||
                key != (this->key)[i] && val == (this->val)[i])
                return false; // pair found but does not completely match
        }
        // Pair not found, new added
        add_keyval(key, val);
        return true;
    }
    
    void add_keyval(char key, char val) {
        (this->key)[count] = key;
        (this->val)[count] = val;
        ++count;
    } 
};

int charArrayLength(char* cArr) {
    int length = 0;
    while (*(cArr + length) != '\0') {
        ++length;
    }
    
    return length;    
}

bool AreStringsIsomorphic(char* a, char* b) {
    int lengthA = charArrayLength(a);
    int lengthB = charArrayLength(b);
    
    if (lengthA != lengthB)
        return false;
    
    Char_dict char_dict(lengthA);
        
    for (int i = 0; i < lengthA; ++i) {
        bool ok = char_dict.check_keyval(a[i], b[i]);
        if (!ok) return false;
    }
    return true;
}

int main()
{
    // char A[] = "brain";
    // char B[] = "space";
    
    // char A[] = "noon";
    // char B[] = "feet";
    
    // This test example returns true because it meets all listed rules
    // so, false result cannot be expected here.
    char A[] = "aab";
    char B[] = "ccd";
    
    cout << AreStringsIsomorphic(A, B) << endl;

    return 0;
}
