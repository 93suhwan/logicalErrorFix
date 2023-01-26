#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

template< uint32_t mod, bool fast = false >
struct MontgomeryModInt {
  using mint = MontgomeryModInt;
  using i32 = int32_t;
  using i64 = int64_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 get_r() {
    u32 ret = mod;
    for(i32 i = 0; i < 4; i++) ret *= 2 - mod * ret;
    return ret;
  }

  static constexpr u32 r = get_r();
  static constexpr u32 n2 = -u64(mod) % mod;

  static_assert(r * mod == 1, "invalid, r * mod != 1");
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");

  u32 x;

  MontgomeryModInt() : x{} {}

  MontgomeryModInt(const i64 &a)
      : x(reduce(u64(fast ? a : (a % mod + mod)) * n2)) {}

  static constexpr u32 reduce(const u64 &b) {
    return u32(b >> 32) + mod - u32((u64(u32(b) * r) * mod) >> 32);
  }

  mint &operator+=(const mint &p) {
    if(i32(x += p.x - 2 * mod) < 0) x += 2 * mod;
    return *this;
  }

  mint &operator-=(const mint &p) {
    if(i32(x -= p.x) < 0) x += 2 * mod;
    return *this;
  }

  mint &operator*=(const mint &p) {
    x = reduce(u64(x) * p.x);
    return *this;
  }

  mint &operator/=(const mint &p) {
    *this *= p.inverse();
    return *this;
  }

  mint operator-() const { return mint() - *this; }

  mint operator+(const mint &p) const { return mint(*this) += p; }

  mint operator-(const mint &p) const { return mint(*this) -= p; }

  mint operator*(const mint &p) const { return mint(*this) *= p; }

  mint operator/(const mint &p) const { return mint(*this) /= p; }

  bool operator==(const mint &p) const { return (x >= mod ? x - mod : x) == (p.x >= mod ? p.x - mod : p.x); }

  bool operator!=(const mint &p) const { return (x >= mod ? x - mod : x) != (p.x >= mod ? p.x - mod : p.x); }

  u32 get() const {
    u32 ret = reduce(x);
    return ret >= mod ? ret - mod : ret;
  }

  mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  mint inverse() const {
    return pow(mod - 2);
  }

  friend ostream &operator<<(ostream &os, const mint &p) {
    return os << p.get();
  }

  friend istream &operator>>(istream &is, mint &a) {
    i64 t;
    is >> t;
    a = mint(t);
    return is;
  }

  static u32 get_mod() { return mod; }
};

const unsigned int MOD = 1073400569;
using H = MontgomeryModInt< MOD >;

const int MAX = 5e5 + 5;
H pow10[MAX];
H invpow10[MAX];

H substr_hsh(vector<H> &s, int start, int len){
    return (s[start + len] - s[start] * pow10[len]);
}

// lcp of two prefixes s[x:] and t[y:]
int lcp(vector<H> s, vector<H> t, int x, int y){
    int ans = 0;
    for(int add = (1<<19); add; add >>= 1){
        int mid = ans + add;
        if(x + mid >= s.size() || y + mid >= t.size()) continue;
        if(substr_hsh(s, x, mid) == substr_hsh(t, y, mid)){
            ans = mid;
        }
    }
    return ans;
    // return max(0, (int) min(s.size() - x - 1, t.size() - y - 1) / 2);
}

void output(int a, int b, int d){
    cout << a+1 << ' ' << b << '\n' << b+1 << ' ' << d << '\n';
    exit(0);
}

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

vi Z(string S) {
    vi z(sz(S));
    int l = -1, r = -1;
    rep(i,1,sz(S)) {
        z[i] = i >= r ? 0 : min(r - i, z[i - l]);
        while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
            z[i]++;
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    return z;
}

void solve(){
    debug("st");
    pow10[0] = H(1);
    invpow10[0] = H(1);
    for(int i = 1; i < MAX; i++){
        pow10[i] = pow10[i-1] * H(10);
        invpow10[i] = pow10[i].inverse();
    }

    string s, x;
    cin >> s >> x;

    int n = s.size(), m = x.size();
    vector<H> prefs(n+1);
    prefs[0] = H(0);
    for(int i = 0; i < n; i++){
        prefs[i+1] = prefs[i] * H(10) + (s[i]-'0');
    }
    
    vector<H> prefx(m+1);
    prefx[0] = H(0);
    for(int i = 0; i < m; i++){
        prefx[i+1] = prefx[i] * H(10) + (x[i]-'0');
    }

    // debug(substr_hsh(prefs, 2, 3));
    // debug(lcp(prefs, prefx, 2, 4));

    vi z = Z(x + '$' + s);

    debug("start");

    for(int l = 0; l + m < n; l++){
        if(l % 1000 == 0) debug(l);
        // int cp = lcp(prefs, prefx, l, 0);
        int cp = z[l+x.size()+1];
        // debug(cp);
        int diff = l + cp;

        if(s[diff] > x[cp] || cp == m) continue;

        int chk = m - cp; // or chk-1

        H cur = substr_hsh(prefs, l, m);

        // right
        if(l+m+chk <= n && prefx[m] == cur + substr_hsh(prefs, l+m, chk)){
            output(l, l+m, l+m+chk);
        }
        if(chk > 1 && l+m+chk-1 <= n && prefx[m] == cur + substr_hsh(prefs, l+m, chk-1)){
            output(l, l+m, l+m+chk-1);
        }

        // left
        if(l-chk >= 0 && prefx[m] == cur + substr_hsh(prefs, l-chk, chk)){
            output(l-chk, l, l+m);
        }
        if(chk > 1 && l-chk+1 >= 0 && prefx[m] == cur + substr_hsh(prefs, l-chk+1, chk-1)){
            output(l-chk+1, l, l+m);
        }
    }
    debug("done");

    // todo (m-1)+(m-1)
    if(m > 1){
        for(int i = 0; i+2*m-2 <= n; i++){
            if(prefx[m] == substr_hsh(prefs, i, m-1) + substr_hsh(prefs, i+m-1, m-1)){
                output(i, i+m-1, i+2*m-2);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    // string s = "234059827348780241734019284723475726394582345293857234059812349";
    // int n = s.size();
    // vector<H> prefs(n+1);
    // prefs[0] = H(0);
    // for(int i = 0; i < n; i++){
    //     prefs[i+1] = prefs[i] * H(10) + (s[i]-'0');
    // }
    // H x = 0;
    // for(int i = 0; i < 500000; i++){
    //     x += lcp(prefs, prefs, i%20, i%17);
    // }
    // cout << x << endl;
    return 0;
}
