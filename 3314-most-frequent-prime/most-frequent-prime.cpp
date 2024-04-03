class Solution {
public:
    //For checking prime numbers
    bool prime[10000000];
    void Sieve(){
        int n = 999999;
        memset(prime, true, sizeof(prime));
    
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p){
                    prime[i] = false;
                }
            }
        }
    }
    bool flag = true;
    bool isPrime(int num){
        for(int i=2; i*i<=num; i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    void solve(int i, int j, int n, int m, int dir1, int dir2, int num, vector<vector<int>>& mat, map<int,int>&mp){
        if(i<0 or j<0 or i>=n or j>=m){
            return;
        }

        num = num*10+mat[i][j];
        if(num>10 and prime[num]){
            cout<<num<<endl;
            mp[num]++;
        }
        solve(i+dir1, j+dir2, n, m, dir1, dir2, num, mat, mp);
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int,int>mp;
        
        if(flag){
            Sieve();
            flag = false;
        }
        
        
        int direc[8][2] = {{-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1, 1}};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(auto it: direc){
                    solve(i, j, n, m, it[0], it[1], 0, mat, mp);
                }
            }
        }

        int maxi = -1e5;
        int ans = 0;
        for(auto it: mp){
            if(it.second>=maxi){
                maxi = it.second;
                ans = it.first;
            }
            
        }
        
        
        return (ans==0)?-1:ans;
    }
};