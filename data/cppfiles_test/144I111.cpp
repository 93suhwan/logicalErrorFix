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
const int md = (int)1e9+7;
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

void add(int& a,int b){
    a = (a + b >= md ? a + b - md : a + b);
}

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
    int n,m,k;
    cin >> n >> m >> k;

    int t1,t2;
    t1 = t2 = 0;

    int k1 = (n + m - 1) / m, k2 = n / m;

    for(int i = 0; i <= n; i++){
        if((n - (i * k1)) % k2 == 0){
            t1 = i;
            t2 = (n - (i * k1)) / k2;
            break;
        }
    }

    set<pair<int,int>> q;
    for(int i = 1; i <= n; i++){
        q.insert(mp(0,i));
    }
    for(int i = 0; i < k; i++){
        set<int> used;
        vector<pair<int,int>> v;
        for(int j = 0; j < t1; j++){
            cout << k1 << " ";
            for(int T = 0; T < k1; T++){
                int id = q.begin()->second, cnt = q.begin()->first;
                q.erase(q.begin());
                cout << id << " ";
//                cerr << "???\n";
                v.pb(mp(cnt+1,id));
                used.insert(id);
            }
            cout << "\n";
        }
        for(auto& x : v)
            q.insert(x);
        int ptr = 1;
        for(int j = 0; j < t2; j++){
            cout << k2 << " ";
            int c = k2;
            while(c--){
                while(used.count(ptr))
                    ptr++;
                cout << ptr++ << " ";
            }
            cout << "\n";
        }
    }

    cout << "\n";

    return;
}

/**

**/

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

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

(a;b) -> (a+c,b+d) = g

c = (g - a%g) % g, d = (g - b%g)%g

a % g != 0 and b % g != 0 (this can be done in O(sqrt(4000) * 4000), which is pretty fast)

g - a%g + g - b%g <= k /// k <= 4000

a ; g

(g - g % a)%g + t <= k

(g - b%g)%g <= k - (g-g%a)%g

t = k - (g - g%a)%g

(g - b%g)%g <= t

b%g != 0 (other case can be checked in O(logN))

g - b%g <= t

g - t <= b%g

b%g = [g-t;g-1]

**/
