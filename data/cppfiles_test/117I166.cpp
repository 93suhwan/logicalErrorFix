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
const int md = (int)1e18 + 7;
const int MAXN = (int)1e6 + 111;
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
    vector<int> cnt;
    DSU(int nn){
        n = nn;
        parent.resize(n+11);
        sz.resize(n+11,1);
        deep.resize(n+11,1);
        cnt.resize(n+11);
        for(int i = 0; i < n + 10; i++){
            parent[i] = i, sz[i] = 1, deep[i] = 1;
            cnt[i] = 0;
        }
    }
    int find_parent(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find_parent(parent[x]);
    }
    void union_sets(int a,int b){
        a = find_parent(a);
        b = find_parent(b);
        if(a == b){
            return;
        }
        if(deep[a] <= deep[b])
            parent[a] = b, sz[b] += sz[a], deep[b] = max(deep[b],deep[a]+1), cnt[b] += cnt[a] + 1;
        else
            parent[b] = a, sz[a] += sz[b], deep[a] = max(deep[a],deep[b]+1), cnt[a] += cnt[b] + 1;
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

int fac[555555];
int invfac[555555];

void init(){
    fac[0] = 1;
    invfac[0] = 1;

    for(int i = 1; i < 555555; i++){
        fac[i] = fac[i-1] * i;
        invfac[i] = inv(fac[i]);
    }

    return;
}

//void add(int& a,int b){
//    a = (a + b >= md ? a + b - md : a + b);
//}
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

const int DX[] = {1,0,-1,0};
const int DY[] = {0,1,0,-1};

void solve(){
    int n,m;
    cin >> n >> m;

    vector<vector<char>> g(n+2,vector<char>(m+2));
    vector<vector<bool>> used(n+2,vector<bool>(m+2,false));
    int sx,sy;

    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++){
            g[i][j] = '#';
            used[i][j] = 1;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j];
            if(g[i][j] == 'L')
                sx = i, sy = j;
            used[i][j] = false;
        }
    }

    queue<pair<int,int>> q;
    q.push(mp(sx,sy));
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int xn = x + DX[i], yn = y + DY[i];
            if(!used[xn][yn] && g[xn][yn] != '#'){
                int cnt = 0;
                for(int j = 0; j < 4; j++){
                    int X = xn + DX[j], Y = yn + DY[j];
                    if(X <= n && Y <= m && Y >= 1 && X >= 1 && g[X][Y] != '#')
                        cnt++;
                }
                if(cnt <= 2){
                    used[xn][yn] = 1;
                    q.push(mp(xn,yn));
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(g[i][j] == 'L' || g[i][j] == '#')
                cout << g[i][j];
            else if(used[i][j])
                cout << "+";
            else
                cout << g[i][j];
        }
        cout << "\n";
    }

    return;
}

/**
7 7 7 0 2


**/

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

//    freopen("jobbery.in","r",stdin);
//    freopen("jobbery.out","w",stdout);

//    init();

    int tests = 1;
    cin >> tests;

    for(int _ = 1; _ <= tests; _++){
        solve();
    }
//
//    #ifdef __WIN32
//        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
//    #endif

    return 0;
}
/**

a,b
g

(g - a%g) % g + (g - b % g) % g

abs(a-b) <= k

gcd = max(a,b) + (k-abs(a-b)) / 2

a * a ~ 10^6



**/
