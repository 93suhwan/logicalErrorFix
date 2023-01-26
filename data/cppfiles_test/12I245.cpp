#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define mp make_pair
#define pb push_back
#define sz(x) ((int)((x).size()))
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define debug(x) cerr << __LINE__ << ' ' << #x << ':' << (x) << '\n'
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

using ll = long long;
using ull = unsigned long long;

using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int MOD = 1e9 + 7;
const int mxN = 1e2+1;
const int INF = 1e10;
const char nl = '\n';


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> mat(n, vector<int>(m));
    int verticale=n*m/2-k;
    for(int i=0; i<n-1; i+=2) {
        F0R(j, m) {
            if(verticale==0) break;
            mat[i][j]=mat[i+1][j]=1;
            --verticale;
        }
        if(verticale==0) break;
    }
    F0R(i, n) {
        for(int j=0; j<m-1; ++j) {
            if(k>0&&mat[i][j]==0&&mat[i][j+1]==0) {
                mat[i][j]=mat[i][j+1]=1;
                ++j;
                --k;
            }
            else if(k<=0) break;
        }
        if(k==0) break;
    }
    trav(x, mat)
        trav(y, x)
            if(y==0) {
                cout << "NO" << nl;
                return;
            }
    cout << "YES" << nl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef ONPC
        auto _time_begin = std::chrono::high_resolution_clock::now();
    #endif
    // *****
    int tt=1;
    cin >> tt;
    while(tt--)
        solve();

    // *****
    #ifdef ONPC
        auto _time_end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(_time_end - _time_begin).count() << " seconds";
    #endif
    return 0;
}
