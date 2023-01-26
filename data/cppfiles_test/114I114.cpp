/* Author : Hakesh D */
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
 
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define ld long double
 
 
#define vi vector<int>
#define append push_back
#define pb push_back
#define pii pair<int,int>
#define popf pop_front
#define popb pop_back

#define MAX *max_element
#define MIN *min_element
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define GCD __gcd
 
#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define for1(e) FOR(i, 0, e, 1)
#define for2(i, e) FOR(i, 0, e, 1)

#define inf 1e9
#define INF 1e18

int cil(int x,int y){if(x%y == 0) {return x/y;}; return x/y+1;}
/***********************************************************************************************/
 

void solve(){
    int n;
    cin >> n;

    vi siz(n+1);
    vector<vector<int>> a(n+1); 
    for(int i = 1;i <= n;i++) {
        int c; cin >> c;
        siz[i] = c;
        for(int j = 0;j < c; j++) {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }

    int m;
    cin >> m;

    map<array<int,10>,int> hash;
    for(int i = 1; i <= m;i++) {
        array<int,10> x;
        for(int j = 0;j < n; j++) {cin >> x[j]; x[j]--;}
        for(int j = n;j < 10;j++) x[j] = -1;
        hash[x] = 1;
    }



    vector<vector<int>> arr;
    
    vector<int> tmp;
    for(int i = 1;i <= n;i++) tmp.push_back(siz[i]-1);
    arr.push_back(tmp);

    while(sz(arr) <= m) {
        int curr_sz = sz(arr);
        for(int i = 0;i < curr_sz; i++) {
            for(int j = 0; j < n;j++) {
                vector<int> t;
                for(auto x : arr[i]) t.push_back(x);
                if(t[j] > 0) {
                    t[j]--;
                    arr.push_back(t);

                }
            }

        }
        //cout << sz(arr) << endl;
    }

    sort(all(arr), [&](const auto p, const auto q){
        int s1 = 0, s2 = 0;
        for(int i = 0;i < n;i++) {
            s1 += a[i+1][p[i]];
            s2 += a[i+1][q[i]];
        } 
        return s1 > s2;
    }

        );

    for(auto x : arr) {
        array<int,10> ans;
        for(int i = 0;i < n;i++) ans[i] = x[i];
        for(int i = n;i < 10; i++) ans[i] = -1;
        if(hash[ans] == 0) {
            for(int i = 0;i < n;i++) cout << ans[i] + 1 << " ";
            cout << endl;
            return;
        }
    }


}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int tt = 1;
    
    for(int tc = 1; tc <= tt; tc++) {
        //cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
/***********************************************************************************************/





 