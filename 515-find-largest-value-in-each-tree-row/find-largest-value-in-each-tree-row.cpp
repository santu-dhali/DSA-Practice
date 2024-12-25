/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        map<int, vector<int>>mp;
        vector<vector<int>>vec;
        queue<pair<TreeNode*, int>>q;
        vector<int>ans;

        if(root == NULL){
            return ans;
        }
        q.push({root, 0});

        while(!q.empty()){
            TreeNode* nde = q.front().first;
            int level = q.front().second;
            q.pop();

            mp[level].push_back(nde->val);

            if(nde->left){
                q.push({nde->left, level+1});
            }
            if(nde->right){
                q.push({nde->right, level+1});
            }
        }
        for(auto it: mp){
            vector<int>temp;
            for(auto i: it.second){
                temp.push_back(i);
            }
            vec.push_back(temp);
        }

        for(auto it: vec){
            int maxi = INT_MIN;
            for(auto i: it){
                if(i > maxi){
                    maxi = i;
                }
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};