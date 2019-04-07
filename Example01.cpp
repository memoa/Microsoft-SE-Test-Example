// Are Strings Isomorphic

struct Char_dict {
    string key;
    string val;
    
    bool check_keyval(char key, char val) {
        for (int i = 0; i < (this->key).length(); ++i) {
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
        (this->key) += key;
        (this->val) += val;
    } 
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        Char_dict char_dict;
        
        if (s.length() != t.length())
            return false;
        
        for (int i = 0; i < s.length(); ++i) {
            bool ok = char_dict.check_keyval(s[i], t[i]);
            if (!ok) return false;
        }
        return true;
    }
};