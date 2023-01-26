#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define int long long
#define uint __int128
#define mp make_pair
#define left left_compile
#define right right_compile

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

const int INF = (int)1e18;
const int md = (int)998244353;
const int MAXN = (int)1e18;
const int N = (int)2e5 + 111;
//const int L = 20;
const int debug = 0;
const long double eps = 0.0001;
//const int P[2] = {29,31};

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct DSU{
    int n;
    vector<int> parent;
    vector<int> sz;
    vector<int> deep;
    DSU(int nn){
        n = nn;
        parent.resize(n+1);
        sz.resize(n+1,1);
        deep.resize(n+1,1);
        for(int i = 0; i <= n; i++)
            parent[i] = i, sz[i] = 1, deep[i] = 1;
    }
    int find_parent(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find_parent(parent[x]);
    }
    void union_sets(int a,int b){
        a = find_parent(a);
        b = find_parent(b);
        if(a == b)
            return;
        if(deep[a] <= deep[b])
            parent[a] = b, sz[b] += sz[a], deep[b] = max(deep[b],deep[a]+1);
        else
            parent[b] = a, sz[a] += sz[b], deep[a] = max(deep[a],deep[b]+1);
    }
    bool connected(int a,int b){
        return find_parent(a) == find_parent(b);
    }
};

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int bpow(int a,int b){
    if(b <= 0)
        return 1ll;
    if(b % 2 == 0){
        int t = bpow(a,b/2) % md;
        return (t * t) % md;
    }
    return (a * bpow(a,b-1)) % md;
}

int inv(int a){ /// return 1/a by PRIME modulo md
    return bpow(a,md-2);
}

template<class T>
void myerase(ordered_multiset<T>& st, T t){
    T r = st.order_of_key(t);
    typename ordered_multiset<T>::iterator it = st.find_by_order(r);
    st.erase(it);
    return;
}

int dp[555][555];

int fac[555];
int invfac[555];

void init(){
    fac[0] = 1;
    invfac[0] = 1;

    for(int i = 1; i < 555; i++){
        fac[i] = fac[i-1] * i % md;
        invfac[i] = inv(fac[i]);
    }

    return;
}

void add(int& a,int b){
    a = (a + b >= md ? a + b - md : a + b);
}
//
//void sub(int& a,int b){
//    a = (a < b ? a - b + md : a - b);
//}

int mult(int a,int b){
    return a * b % md;
}

int C(int n,int k){
    assert(k >= 0 && k <= n);
    return mult(fac[n],mult(invfac[n-k],invfac[k]));
}

void solve(){
    int n,x;
    cin >> n >> x;

    dp[n][0] = 1;
    for(int i = n; i > 0; i--){
        for(int j = 0; j <= x; j++){
            for(int t = i; t >= 0; t--){
                int damage = min(x,j+i-1);
                add(dp[t][damage],dp[i][j] * C(i,i-t) * bpow(damage - j,i-t) % md);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= x; i++){
        add(ans,dp[0][i]);
    }

    cout << ans;

    return;
}

/**
1000000007
1000000009
**/

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    init();

    int tests = 1;
//    cin >> tests;

    for(int _ = 1; _ <= tests; _++){
        solve();
    }

//    #ifdef __WIN32
//        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
//    #endif

    return 0;
}
/**

**/
