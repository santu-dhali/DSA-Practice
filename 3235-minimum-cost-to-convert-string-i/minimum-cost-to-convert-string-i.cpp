class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& change, vector<int>& cost){
        int n = original.size();
        int m = change.size();
        vector<vector<int>>dis(26, vector<int>(26, 1e9));

        for(int i=0; i<26; i++){
            dis[i][i] = 0;
        }

        for(int i=0; i<n; i++){
            int x = original[i] - 'a';
            int y = change[i] - 'a';
            int z = cost[i];
            dis[x][y]= min(dis[x][y], z);
        }

        for(int k=0; k<26; k++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            int x = source[i] - 'a';
            int y = target[i] - 'a';
            if(x != y){
                if(dis[x][y] == 1e9){
                    return -1;
                }
                ans += dis[x][y];
            }
        }

        return ans;
    }
};