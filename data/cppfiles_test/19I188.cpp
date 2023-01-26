#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

void debug_out(){
    cerr << endl;
}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T){
    cerr << ' ' << H;
    debug_out(T...);
}
#ifdef local
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 55
#endif

const int N = 15;
int a[N], b[N], n, flag;
void dfs(int p){
    if(flag) return;
    if(p == n + 1){
        gp_hash_table<int, int> g;
        for(int i = 1; i <= n; i++) g[b[i]] = 1;
        for(int i = 1; i <= n; i++){
            if(g.find(a[n] - b[i]) != g.end() || g.find(a[n] + b[i]) != g.end()){
                flag = 1;
                break;
            }
        }
        return;
    }
    for(int i = 1; i < p; i++){
        b[p] = a[p - 1] + b[i];
        dfs(p + 1);
        b[p] = b[i] - a[p - 1];
        dfs(p + 1);
    }
}
int main() {
#ifdef local
    freopen("../in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        flag = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        b[1] = 0;
        dfs(2);
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}