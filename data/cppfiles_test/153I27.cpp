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
template<typename T, typename T2> void debug(map<T,T2>&v){for(auto [k,v]: v) cerr << k spa v << "\n"; cerr<<"\n";}
template<typename T, typename T2> void debug(unordered_map<T,T2>&v){for(auto [k,v]: v) cerr << k spa v << "\n";cerr<<"\n";}
V<int> listrange(int n) {V<int> res(n); rep(i,n) res[i]=i; return res;}

template<typename T> P<T,T> divmod(T a, T b) {return make_pair(a/b, a%b);}

const ll INF = (1ll<<62);
// const ld EPS   = 1e-10;
// const ld PI    = acos(-1.0);


template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using m17 = ModInt<1'000'000'007>;
using m98 = ModInt<998'244'353>;
// using MOD = m17;
// ll mod = 1'000'000'007;
using MOD = m98;
ll mod = 998'244'353;


const int _B = 500500;
MOD g1[_B];
MOD g2[_B];
MOD inverse[_B];
void prepare() {
  g1[0] = g1[1] = g2[0] = g2[1] = 1;
  inverse[0] = 0;
  inverse[1] = 1;
  range(i,2,_B,1) {
    g1[i] = g1[i-1]*i;
    inverse[i] = -inverse[mod%i]*(mod/i);
    g2[i] = g2[i-1]*inverse[i];
  }
}
template<typename T>
MOD cmb(T n, T r) {
  assert(g1[0]==1);
  if (r<0 || r>n) return 0;
  r = min(r, n-r);
  return g1[n]*g2[r]*g2[n-r];
}
template<typename T>
MOD perm(T n, T r) {
  if (r<0 || r>n) return 0;
  return g1[n]*g2[n-r];
}



void Main(){
    ll n;
    cin >> n;
    const int m = 26;
    VV<int> vs(n, V<int>(m,0));
    rep(i,n) {
        string s;
        cin >> s;
        rep(j, s.size()) {
            vs[i][int(s[j]-'a')]++;
        }
    }
    VV<V<int>> index(m, VV<int>(1<<n));
    rep(b, 1<<n) {
        V<int> l;
        rep(j,n) if (b>>j&1) l.push_back(j);
        rep(c, m) {
            sort(all(l), [&](int i, int j) {return vs[i][c]<vs[j][c];});
            index[c][b] = l;
        }
    }
    // debug(vs);
    // for (auto item: index[0]) debug(item);
    V<MOD> dp(1<<n);
    dp[(1<<n)-1] = 1;
    rep(c, m) {
        V<MOD> ndp(1<<n);
        rrep(b, 1<<n) {
            MOD val = dp[b];
            if (val==0) continue;
            int nb = b;
            int p = 0;
            // cout << c spa b << endl;
            // debug(index[c][b]);
            for (auto i : index[c][b]) {
                ndp[nb] += val * (vs[i][c]-p+1);
                nb ^= 1<<i;
                p = vs[i][c]+1;
            }
        }
        // debug(ndp);
        swap(dp, ndp);
    }
    // debug(dp);
    V<MOD> dp2 = dp;
    rep(i,n) rep(j,1<<n) if (!(j>>i&1)) dp2[j] += dp2[j^(1<<i)]; // zeta_sub res[b] = sum_{bb<=b} count[bb]
    rep(b,1<<n) dp2[b] -= dp[b];
    rep(i,n) rep(j,1<<n) if ((j>>i&1)) dp[j] += dp[j^(1<<i)]; // zeta_sub res[b] = sum_{bb<=b} count[bb]
    // range(i, 1, (1<<n)-1, 1) dp[i] += 1;
    ll ans = 0;
    rep(b, 1<<n) {
        dp[b] += dp2[b];
        ll v = 0;
        for (auto ind : index[0][b]) v += (ind+1);
        v *= index[0][b].size();
        ans ^= (ll(dp[b].x) * v);
        // cout << b spa v spa dp[b] << endl;
    }
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
