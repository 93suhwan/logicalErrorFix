# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, n, m;

int main(){
    cin >> t;
    while(t--){
        cin >> m >> n;
        vector<vector<pair<lli, int>>> g(m, vector<pair<lli, int>>(n, {0, 0}));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> g[i][j].first, g[i][j].second = j;
        set<lli> s;
        lli gift[n] = {0};
        int store[n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[j][i].first > gift[i]){
                   gift[i] = g[j][i].first;
                   store[i] = j; 
                }
            }
        }
        set<int> stores;
        for(int i = 0; i < n; i++) stores.insert(store[i]);

        for(int i = 0; i < m; i++) sort(g[i].begin(), g[i].end(), greater<pair<lli, int>>());
        for(int i = 0; i < n; i++) s.insert(gift[i]);
        if(m <= (n - 1) || stores.size() <= (n - 1)){
            cout << *s.begin() << endl;
        }
        else{
            lli ans = 0;
            for(int i = 0; i < m; i++){

                for(int j = 0; j < n - 1; j++){
                    auto [val, p] = g[i][j];
                    auto [val2, p2] = g[i][j + 1];

                    lli opval = gift[p], op2val = gift[p2];

                    s.erase(opval);
                    s.erase(op2val);

                    s.insert(val);
                    s.insert(val2);

                    ans = max(ans, *s.begin());
                    
                    //cout << " ---- " << *s.begin() << endl;

                    s.erase(val);
                    s.erase(val2);

                    

                    s.insert(opval);
                    s.insert(op2val);
                }

                
                

            }
            cout << ans << endl;
        }
    }
    return 0;
}