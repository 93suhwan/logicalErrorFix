#include<bits/stdc++.h>
#define pi 3.141592653589793238
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define printclock cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n";
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll B) { return (unsigned ll)rng() % B;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll _T = 1;
    
    cin >> _T;
    while (_T--) {
        ll n, m;
        cin >> n >> m;
        vector<string> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<vector<ll>> visited(n, vector<ll>(m));
        vector<vector<ll>> cycle(n, vector<ll>(m));
        vector<vector<ll>> T(n, vector<ll>(m));
        ll cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j]){
                    continue;
                }
                cnt++;
                ll x = i, y = j;
                bool f = true;
                ll len = 0;
                bool gg = true;
                ll addt = 0, addc = 0;
                while(1){
                    len++;
                    if(v[x][y] == 'R') y++;
                    else if(v[x][y] == 'L') y--;
                    else if(v[x][y] == 'U') x--;
                    else x++;
                    if(x >= n || y >= m || x < 0 || y < 0){
                        f = false;
                        break;
                    }
                    if(visited[x][y] == cnt){
                        break;
                    }
                    if(visited[x][y]){
                        f = false;
                        gg = false;
                        addt = T[x][y];
                        addc = cycle[x][y];
                        break;
                    }
                    visited[x][y] = cnt;
                }
                if(!gg){
                    x = i, y = j;
                    while(1){
                        T[x][y] = addt + addc + len;
                        len--;
                        if(v[x][y] == 'R') y++;
                        else if(v[x][y] == 'L') y--;
                        else if(v[x][y] == 'U') x--;
                        else x++;
                        if(x >= n || y >= m || x < 0 || y < 0){
                            
                            break;
                        }
                        
                        if(visited[x][y] != cnt){
                            break;
                        }
                        
                    }
                    continue;
                }
                ll hx = x, hy = y;
                ll cyc = 0;
                if(f){
                    while(1){
                        assert(y < m && y >= 0);
                        assert(x < n && x >= 0);
                        if(v[x][y] == 'R') y++;
                        else if(v[x][y] == 'L') y--;
                        else if(v[x][y] == 'U') x--;
                        else x++;
                        cyc++;
                        if(x == hx && y == hy){
                            break;
                        }
                    }
                    x = hx, y = hy;
                    while(1){
                        assert(y < m && y >= 0);
                        cycle[x][y] = cyc;
                        if(v[x][y] == 'R') y++;
                        else if(v[x][y] == 'L') y--;
                        else if(v[x][y] == 'U') x--;
                        else x++;
                        if(x == hx && y == hy){
                            break;
                        }
                    }
                }
                ll tail = 0;
                x = i, y = j;
                if(cycle[x][y] == 0){
                    while(1){
                        tail++;
                        if(v[x][y] == 'R') y++;
                        else if(v[x][y] == 'L') y--;
                        else if(v[x][y] == 'U') x--;
                        else x++;
                        if(x >= n || y >= m || x < 0 || y < 0){
                            break;
                        }
                        if(cycle[x][y] != 0){
                            break;
                        }
                    }
                    x = i, y = j;
                    while(1){
                        T[x][y] = tail--;
                        if(v[x][y] == 'R') y++;
                        else if(v[x][y] == 'L') y--;
                        else if(v[x][y] == 'U') x--;
                        else x++;
                        if(x >= n || y >= m || x < 0 || y < 0){
                            break;
                        }
                        if(cycle[x][y] != 0){
                            break;
                        }
                    }
                }

            }
        }
        ll ans = -1;
        ll aa, bb;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ans < T[i][j] + cycle[i][j]){
                    ans = T[i][j] + cycle[i][j];
                    aa = i + 1, bb = j + 1;
                }
            }   
        }
        cout << aa << " " << bb << " " << ans << "\n";
    }
    return 0;
}