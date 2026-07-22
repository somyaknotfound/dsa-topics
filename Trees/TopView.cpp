/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector <int> ans;
        
        if (!root) {
            return ans;
        }
        
        queue<pair<Node* , int>>q;
        q.push({root , 0});
        map <int,int> mpp;
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
        
            if (mpp.find(line)== mpp.end()) {
                mpp[line] = node->data;
                
            }
        
            if (node->left != nullptr) {
                q.push({node->left , line-1});
            }
            
            if (node->right != nullptr) {
                q.push({node->right , line+1});
            }
        }
        
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
