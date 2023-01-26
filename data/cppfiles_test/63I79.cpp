 bool TEST = false;

using namespace std;
#include<bits/stdc++.h>
#include<fstream>

#define rep(i,n) for(int (i)=0;(i)<(ll)(n);i++)
#define rrep(i,n) for(int (i)=(ll)(n)-1;(i)>=0;i--)
#define range(i,start,end,step) for(int (i)=start;(i)<(ll)(end);(i)+=(step))
#define rrange(i,start,end,step) for(int (i)=start;(i)>(ll)(end);(i)+=(step))

#define dump(x)  cerr << "Line " << __LINE__ << ": " <<  #x << " = " << (x) << "\n";
#define spa << " " <<
#define fi first
#define se second
#define all(a)  (a).begin(),(a).end()
#define allr(a)  (a).rbegin(),(a).rend()

using ld = long double;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
 
template<typename T> using V = vector<T>;
template<typename T> using VV = V<V<T>>;
template<typename T, typename T2> using P = pair<T, T2>;
template<typename T, typename T2> using M = map<T, T2>;
template<typename T> using S = set<T>;
template<typename T, typename T2> using UM = unordered_map<T, T2>;
template<typename T> using PQ = priority_queue<T, V<T>, greater<T>>;
template<typename T> using rPQ = priority_queue<T, V<T>, less<T>>;
template<typename T> vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template<typename... Ts> auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template<class SS, class T> ostream& operator << (ostream& os, const pair<SS, T> v){os << "(" << v.first << ", " << v.second << ")"; return os;}
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << ' '; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>> &v){ for(auto &e : v){os << e << "\n";} return os;}
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
 
template <class T> void UNIQUE(vector<T> &x) {sort(all(x));x.erase(unique(all(x)), x.end());}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
void fail() { cout << -1 << '\n'; exit(0); }
inline int popcount(const int x) { return __builtin_popcount(x); }
inline int popcount(const ll x) { return __builtin_popcountll(x); }
template<typename T> void debug(vector<vector<T>>&v){for(ll i=0;i<v.size();i++)
{cerr<<v[i][0];for(ll j=1;j<v[i].size();j++)cerr spa v[i][j];cerr<<"\n";}};
template<typename T> void debug(vector<T>&v){if(v.size()!=0)cerr<<v[0];
for(ll i=1;i<v.size();i++)cerr spa v[i];
cerr<<"\n";};
template<typename T> P<T,T> divmod(T a, T b) {return make_pair(a/b, a%b);}

const ll INF = (1ll<<62);
// const ld EPS   = 1e-10;
// const ld PI    = acos(-1.0);

template<typename T>
struct Counter {
    int n;
    int B = 300;
    V<unordered_map<T,int>> values;
    V<T> a;
    Counter(int n, V<T> b): n(n) {
        values = V<unordered_map<T,int>>((n+B-1)/B);
        rep(i,b.size()) {
            auto v = b[i];
            values[i/B][v]++;
        }
        a = b;
    }
    int query(int l, int r, T v) {
        return query(r, v) - query(l, v);
    }
    int query(int l, T v) {
        int res = 0;
        rep(i, l/B) res += values[i][v];
        range(j, (l/B)*B, l, 1) if (a[j]==v) res++;
        return res;
    }
};

void Main(){
    ll n;
    cin >> n;
    V<int> total;
    V<int> bottom;
    V<int> ls;
    V<unordered_map<int,int>> index_list;
    V<unordered_map<int,int>> counts;
    V<unordered_map<int,int>> counts2;
    rep(i,n) {
        string s;
        cin >> s;
        unordered_map<int,int> vs;
        unordered_map<int,int> index;
        unordered_map<int,int> count;
        int v = 0;
        int mm = 0;
        rep(j, s.size()) {
            if (s[j]=='(') v++;
            else v--;
            vs[v]++;
            if (index.find(v)==index.end()) {index[v] = j; count[v] = vs[v+1];}
            chmin(mm, v);
        }
        index_list.push_back(index);
        counts.push_back(count);
        counts2.push_back(vs);
        ls.push_back(vs.size());
        total.push_back(v);
        bottom.push_back(mm);
    }
    V<int> dp(1<<n);
    V<int> dp1(1<<n);
    V<int> dp2(1<<n);
    dp2[0] = 1;
    int ans = 0;
    rep(b, 1<<n) {
        if (dp2[b]==0) continue;
        int s = dp[b];
        int v = dp1[b];
        rep(i,n) {
            if (b>>i&1) continue;
            int tt = total[i];
            int mm = bottom[i];
            bool valid = 1;
            int ns, nv, nb;
            nb = b | (1<<i);
            if (mm + s < 0) {
                valid = 0;
                // int ind = index_list[i][-s-1];
                ns = s + tt;
                nv = v + counts[i][-s-1];
                // if (i==0) cout << ind spa -s spa counts[i].query(ind, -s) << endl;
            } else {
                ns = s + tt;
                nv = v + counts2[i][-s];
            }
            dp2[nb] = valid;
            dp[nb] = ns;
            dp1[nb] = max(dp1[nb], nv);
            chmax(ans, nv);
            // if (nv==2) cout << b spa i << endl;
        }
    }
    // debug(dp);
    // debug(dp1);
    cout << ans << endl;
}

int main(void){
    std::ifstream in("tmp_in");
    if (TEST) {
        std::cin.rdbuf(in.rdbuf());
        std::cout << std::fixed << std::setprecision(15);
    } else {
        std::cin.tie(nullptr);
        std::ios_base::sync_with_stdio(false);
        std::cout << std::fixed << std::setprecision(15);
    }
    Main();
}
