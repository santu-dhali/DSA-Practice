class Solution {
public:
    int minimumPushes(string word){
        int n = word.size();
        map<char, int>mp;
        vector<int>vis;

        for(int i=0; i<n; i++){
            mp[word[i]]++;
        }

        for(auto it: mp){
          vis.push_back(it.second);  
        }
        sort(vis.begin(), vis.end(), greater<int>());
        int count = 0;

        for(int i=1; i<=vis.size(); i++){
            if(i <= 8){
                count += vis[i-1];
            }else if(i>=9 and i<=16){
                count += vis[i-1]*2;
            }else if(i>=17 and i<=24){
                count += vis[i-1]*3;
            }else{
                count += vis[i-1]*4;
            }
        }

        return count;
    }
};