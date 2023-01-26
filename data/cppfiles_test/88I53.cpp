#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// find_by_order(x) -> access xth element
// find_by_key(x) -> find index where x is stored
template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ogset = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;

#define int long long
#define R(i,a,b) for(int i=a;i<b;i++)
#define RE(i,a,b) for(int i=a;i<=b;i++)
#define RR(i,a,b) for(int i=a;i>b;i--)
#define RRE(i,a,b) for(int i=a;i>=b;i--)
#define t(tup, i) get<i>(tup)
#define endl "\n"
#define flush cout << flush

#define F(i,n) for(int i=0;i<n;i++)
#define FE(i,n) for(int i=0;i<=n;i++)
#define FR(i,n) for(int i=n;i>0;i--)
#define FRE(i,n) for(int i=n;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)((x).size())
#define pii pair <int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define ft first
#define sd second

#ifdef LOCAL
template<class K,class V>ostream& operator<<(ostream &s,const pair<K,V>&p){s<<'<'<<p.ft<<", "<<p.sd<<'>';return s;}
template<class K,class V>ostream& operator<<(ostream &s,const map<K,V>&m){for(auto i:m){s<<" { "<<i.first<<" : "<<i.second<<" } ";}return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream &s,const T&v){s<<'[';for(auto &x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
ostream& operator<<(ostream &s,const vector<bool>&v){s<<'[';for(auto x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cout<<endl;}template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cout<<a<<" ";__prnt(etc...);}
#define debug(...) cout << "[ " << #__VA_ARGS__ << " ] : ", __prnt(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void solve() {
    int n,m;
    cin >> n >> m;

    vi a(n*m);
    vector<vector<bool>> seats(n, vector<bool>(m, false));

    map<int, int> counts, seated;
    map<int, pair<int,int>> locs;
    F(i,n*m) {
        cin >> a[i];
        counts[a[i]]++;
    }

    int cur_loc = 0;
    for (auto [k,v] : counts) {
        locs[k] = {cur_loc, cur_loc+v-1};
        cur_loc += v;
    }
    debug(a);

    int ans = 0;
    for (int i=0; i<n*m; i++) {
        auto [x,y] = locs[a[i]];
        // debug(x,y);
        
        int row = (x+seated[a[i]])/m;
        // debug(row);

        int col = min(y, (row+1)*m - 1) - (row*m-1);
        // debug(col);
        while (seats[row][col]) {
            col--;
        }
        // debug(col);
        
        seated[a[i]]++;
        seats[row][col] = true;
        debug(row, col, i, a[i]);
        while (col > 0) {
            if (seats[row][col-1]) {
                ans++;
            }
            col--;
        }
        debug(ans);
    }

    cout << ans << endl;
}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int T = 1;
    cin >> T;

    for (int __rep=0; __rep<T; ++__rep) {
        // cout << "Case #" << __rep+1 << ": ";
        solve();
    }
    return 0;
}