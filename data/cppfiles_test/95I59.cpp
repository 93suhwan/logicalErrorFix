#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vi;
typedef vector<ll> vll;

#define FOR(i,j,k,in) for(int i=(j); i < (k);i+=in)
#define FORD(i,j,k,in) for(int i=(j); i >=(k);i-=in)
#define REP(i,b) FOR(i,0,b,1)
#define REPD(i,b) FORD(i,b,0,1)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) begin(x), end(x)
#define MANY_TESTS int tcase; cin >> tcase; while(tcase--)

const double EPS = 1e-9;
const int MOD = 1e9+7;
const ll INFF = 1e18;
const int INF = 1e9;
const ld PI = acos((ld)-1);
const vi dy = {1, 0, -1, 0, -1, 1, 1, -1};
const vi dx = {0, 1, 0, -1, -1, 1, -1, 1};

void DBG(){cout << "]" << endl;}
template<typename T, typename ...U> void DBG(const T& head, const U... args){ cout << head << "; "; DBG(args...); }
#define dbg(...) cout << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__);
#define chk() cout << "Check at line(" << __LINE__ << ") hit." << endl;

template<class T, unsigned int U>
ostream& operator<<(ostream& out, const array<T, U> &v){out << "[";  REP(i, U) out << v[i] << ", ";  out << "]"; return out;}
template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U> &par) {out << "[" << par.first << ";" << par.second << "]"; return out;}
template <class T>
ostream& operator<<(ostream& out, const set<T> &cont) { out << "{"; for( const auto &x:cont) out << x << ", "; out << "}"; return out; }
template <class T, class U>
ostream& operator<<(ostream& out, const map<T, U> &cont) {out << "{"; for( const auto &x:cont) out << x << ", "; out << "}"; return out; }
template<class T>
ostream& operator<<(ostream& out, const vector<T> &v){ out << "[";  REP(i, v.size()) out << v[i] << ", ";  out << "]"; return out;}

template<class T>
istream& operator>>(istream& in, vector<T> &v){ for(auto &x : v) in >> x; return in; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL); cout.tie(NULL);
    MANY_TESTS{
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        REP(i, n){
            cin >> a[i];
        }
        vector<vector<int>> maxp(n, vector<int>(m, -INF)), minp(n, vector<int>(m, INF)),
        maxs(n, vector<int>(m, -INF)), mins(n, vector<int>(m, INF));
        REP(i, n){
            REP(j, m){
                maxp[i][j] = minp[i][j] = a[i][j];
                if(j > 0){
                    maxp[i][j] = max(maxp[i][j], maxp[i][j - 1]);
                    minp[i][j] = min(minp[i][j], minp[i][j - 1]);
                }
            }
            REPD(j, m - 1){
                maxs[i][j] = mins[i][j] = a[i][j];
                if(j < m - 1){
                    maxs[i][j] = max(maxs[i][j], maxs[i][j + 1]);
                    mins[i][j] = min(mins[i][j], mins[i][j + 1]);
                }
            }
        }
        bool fn = false;
        REP(cut, m - 1){
            if(fn)
                break;
            vector<int> sorted;
            REP(i, n){
                sorted.pb(i);
            }
            sort(all(sorted), [&](int lhs, int rhs){return maxp[lhs][cut] < maxp[rhs][cut];});
            // sorted by max on prefixes until cut;
            // now if there is a colouring, first x rows are blue then red;
            // proof is on paper;
            vector<int> f(n), s(n), t(n), l(n);
            REP(i, n){
                int v = sorted[i];
                f[i] = maxp[v][cut];
                s[i] = minp[v][cut];
                t[i] = maxs[v][cut + 1];
                l[i] = mins[v][cut + 1];
            }
            FOR(i, 1, n, 1){
                f[i] = max(f[i], f[i - 1]);
                l[i] = min(l[i], l[i - 1]);
            }
            FORD(i, n - 2, 0, 1){
                s[i] = min(s[i], s[i + 1]);
                t[i] = max(l[i], l[i + 1]);
            }
            REP(pre, n - 1){
                if(f[pre] < s[pre + 1] && l[pre] > t[pre + 1]){
                    string re(n, 'a');
                    fn = true;
                    REP(g, n){
                        if(g <= pre){
                            re[sorted[g]] = 'B';
                        }
                        else{
                            re[sorted[g]] = 'R';
                        }
                    }
                    cout << "YES\n";
                    cout << re << " ";
                    cout << cut + 1 << "\n";
                    break;
                }
            }
        }
        if(!fn){
            cout << "NO\n";
        }
    };
    return 0;
}