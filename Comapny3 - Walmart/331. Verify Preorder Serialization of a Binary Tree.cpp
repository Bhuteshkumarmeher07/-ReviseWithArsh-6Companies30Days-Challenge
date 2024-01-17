class Solution {
public:
    int verify(vector<string>& preorder, int index) {
        if (index >= preorder.size()) {
            return index;
        }
        if (preorder[index] == "#") {
            return index;
        }
        return verify(preorder, verify(preorder, index + 1) + 1);
    }
    bool isValidSerialization(string preorder) {
        vector<string> traversal;
        string token;
        for (int i = 0; i < preorder.length(); i++) {
            if (preorder[i] == ',') {
                traversal.push_back(token);
                token = "";
            } else {
                token += preorder[i];
            }
        }
        traversal.push_back(token);
        return verify(traversal, 0) == traversal.size() - 1;
    }
};
