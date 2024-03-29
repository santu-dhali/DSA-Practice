/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* nde = q.front();
            q.pop();

            if (nde->left) {
                q.push(nde->left);
                parent_track[nde->left] = nde;
            }
            if (nde->right) {
                q.push(nde->right);
                parent_track[nde->right] = nde;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        unordered_map<TreeNode*, int> vis;
        queue<pair<TreeNode*, int>> q;
        vector<int> ans;
        markParent(root, parent_track);

        q.push({target, 0});
        vis[target] = 1;

        while (!q.empty()) {
            TreeNode* nde = q.front().first;
            int level = q.front().second;
            
            if(level == k) {
                while(!q.empty()) {
                    ans.push_back(q.front().first->val);
                    q.pop();
                }
                return ans;
            }
            q.pop();
            if(nde->left and !vis[nde->left]) {
                vis[nde->left] = 1;
                q.push({nde->left, level+1});
            }
            if(nde->right and !vis[nde->right]) {
                vis[nde->right] = 1;
                q.push({nde->right, level+1});
            }
            if(parent_track[nde] and !vis[parent_track[nde]]) {
                vis[parent_track[nde]] = 1;
                q.push({parent_track[nde], level+1});
            }
        }

        return ans;
    }
};