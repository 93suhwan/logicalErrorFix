#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < (t); ++i)
#define dsrep(i,t,s) for(int i = (t)-1; i >= (s); --i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define bn(x) ((1ll<<(x))-1)
#define newline puts("")
using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using PQ = priority_queue<T,vc<T>,greater<T> >;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using P = pair<int,int>;
using T3 = tuple<int,int,int>;
using vi = vc<int>;
using vvi = vv<int>;
using vl = vc<ll>;
using vp = vc<P>;
using vt = vc<T3>;
int getInt(){int x;scanf("%d",&x);return x;}
vi pm(int n, int s=0) { vi a(n); iota(rng(a),s); return a;}
template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const T&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
vc<string> split(const string& s,char d=' '){vc<string> r(1);for(char c:s)if(c==d)r.pb("");else r.back()+=c;return r;}
string operator*(const string& s,int t){return join(vc<string>(t,s));}
template<typename T1,typename T2>bool mins(T1& x,const T2&y){if(x>y){x=y;return true;}else return false;}
template<typename T1,typename T2>bool maxs(T1& x,const T2&y){if(x<y){x=y;return true;}else return false;}
template<typename Tx, typename Ty>Tx dup(Tx x, Ty y){return (x+y-1)/y;}
template<typename T>ll suma(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
template<typename T>void uni(T& a){sort(rng(a));a.erase(unique(rng(a)),a.end());}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// Mod int
const uint mod = 1000000007;
struct mint {
  uint x;
  mint(): x(0) {}
  mint(ll x):x((x%mod+mod)%mod) {}
  mint operator-() const { return mint(0) - *this;}
  mint operator~() const { return mint(1) / *this;}
  mint& operator+=(const mint& a) { if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a) { if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a) { x=(ull)x*a.x%mod; return *this;}
  mint& operator/=(const mint& a) { x=(ull)x*a.pow(mod-2).x%mod; return *this;}
  mint operator+(const mint& a) const { return mint(*this) += a;}
  mint operator-(const mint& a) const { return mint(*this) -= a;}
  mint operator*(const mint& a) const { return mint(*this) *= a;}
  mint operator/(const mint& a) const { return mint(*this) /= a;}
  mint pow(ll t) const {
    if(!t) return 1;
    mint res = pow(t/2);
    res *= res;
    return (t&1)?res*x:res;
  }
  bool operator<(const mint& a) const { return x < a.x;}
  bool operator==(const mint& a) const { return x == a.x;}
  bool operator!=(const mint& a) const { return x != a.x;}
};
mint ex(mint x, ll t) { return x.pow(t);}
istream& operator>>(istream&i,mint&a) {i>>a.x;return i;}
//*
ostream& operator<<(ostream&o,const mint&a) {o<<a.x;return o;}
/*/
ostream& operator<<(ostream&o, const mint&x) {
  int a = x.x, b = 1;
  rep(s,2)rrep(i,1000) {
    int y = ((s?-x:x)*i).x;
    if (abs(a)+b > y+i) a = s?-y:y, b = i;
  }
  o<<a; if (b != 1) o<<'/'<<b; return o;
}//*/
using vm = vector<mint>;
using vvm = vector<vm>;
struct modinv {
  int n; vm d;
  modinv(): n(2), d({0,1}) {}
  mint operator()(int i) { while (n <= i) d.pb(-d[mod%n]*(mod/n)), ++n; return d[i];}
  mint operator[](int i) const { return d[i];}
} invs;
struct modfact {
  int n; vm d;
  modfact(): n(2), d({1,1}) {}
  mint operator()(int i) { while (n <= i) d.pb(d.back()*n), ++n; return d[i];}
  mint operator[](int i) const { return d[i];}
} facs;
struct modfactinv {
  int n; vm d;
  modfactinv(): n(2), d({1,1}) {}
  mint operator()(int i) { while (n <= i) d.pb(d.back()*invs(n)), ++n; return d[i];}
  mint operator[](int i) const { return d[i];}
} ifacs;
mint comb(int a, int b) {
  if (a < b || b < 0) return 0;
  return facs(a)*ifacs(b)*ifacs(a-b);
}
//

struct NTT {
  int ceil_pow2(int n) { int x = 0; while ((1U<<x) < (uint)(n)) x++; return x;}
  int bsf(uint n) { return __builtin_ctz(n);}
  const static int _g = 3; // primitive root !!!
  void butterfly(vm& a) {
    static mint g = _g; int n = sz(a), h = ceil_pow2(n);
    static bool first = true; static mint sum_e[30];
    if (first) {
      first = false; mint es[30], ies[30]; int cnt2 = bsf(mod - 1);
      mint e = g.pow((mod - 1) >> cnt2), ie = ~e;
      for (int i = cnt2; i >= 2; i--) {
        es[i - 2] = e; ies[i - 2] = ie; e *= e; ie *= ie;
      }
      mint now = 1;
      rep(i,cnt2-1) sum_e[i] = es[i] * now, now *= ies[i];
    }
    rrep(ph,h) {
      int w = 1<<(ph-1), p = 1<<(h-ph); mint now = 1;
      rep(s,w) {
        int offset = s << (h - ph + 1);
        for (int i = 0; i < p; i++) {
          auto l = a[i + offset], r = a[i + offset + p] * now;
          a[i + offset] = l + r; a[i + offset + p] = l - r;
        }
        now *= sum_e[bsf(~(uint)(s))];
      }
    }
  }
  void butterfly_inv(vm& a) {
    static mint g = _g; int n = sz(a), h = ceil_pow2(n);
    static bool first = true; static mint sum_ie[30];
    if (first) {
      first = false; mint es[30], ies[30];
      int cnt2 = bsf(mod - 1); mint e = g.pow((mod - 1) >> cnt2), ie = ~e;
      for (int i = cnt2; i >= 2; i--) {
        es[i - 2] = e; ies[i - 2] = ie; e *= e; ie *= ie;
      }
      mint now = 1; rep(i,cnt2-1) sum_ie[i] = ies[i] * now, now *= es[i];
    }
    for (int ph = h; ph >= 1; ph--) {
      int w = 1 << (ph - 1), p = 1 << (h - ph); mint inow = 1;
      rep(s,w) {
        int offset = s << (h - ph + 1);
        for (int i = 0; i < p; i++) {
          auto l = a[i + offset], r = a[i + offset + p];
          a[i + offset] = l + r;
          a[i + offset + p] = (ull)(mod + l.x - r.x) * inow.x;
        }
        inow *= sum_ie[bsf(~(uint)(s))];
      }
    }
  }
  vm operator()(vm a, vm b) {
    int n = sz(a), m = sz(b); if (!n || !m) return {};
    if (min(n, m) <= 60) {
      if (n < m) swap(n, m), swap(a, b);
      vm ans(n+m-1); rep(i,n)rep(j,m) ans[i + j] += a[i] * b[j];
      return ans;
    }
    int z = 1 << ceil_pow2(n+m-1);
    a.resize(z); butterfly(a); b.resize(z); butterfly(b);
    rep(i,z) a[i] *= b[i];
    butterfly_inv(a); a.resize(n + m - 1); mint iz = ~(mint(z));
    rep(i,n+m-1) a[i] *= iz;
    return a;
  }
} ntt;

struct fps : vm {
#define d (*this)
#define s int(vm::size())
  template<class...Args> fps(Args...args): vm(args...) {}
  fps(initializer_list<mint> a): vm(rng(a)) {}
  int size() const { return vm::size();}
  void rsz(int n) { if (s < n) resize(n);}
  fps& low_(int n) { resize(n); return d;}
  fps low(int n) const { return fps(d).low_(n);}
  fps low(fps a, int n) const { return a.low_(n);}
  fps& rev_() { reverse(rng(d)); return d;}
  fps rev() const { return fps(d).rev_();}
  fps rev(fps a) const { return a.rev_();}
  mint& operator[](int i) { rsz(i+1); return vm::operator[](i);}
  mint operator[](int i) const { return i<s ? vm::operator[](i) : 0;}
  mint operator()(mint x) const { mint r; drep(i,s) r = r*x+d[i]; return r;}
  fps operator<<(int a) const { fps r(d); r.insert(r.begin(), a, 0); return r;}
  fps operator>>(int a) const { fps r(d); r.rsz(a); r.erase(r.begin(), r.begin()+a); return r;}
  fps& fit() { while (s && !back().x) pop_back(); return d;}
  fps operator-() const { fps r(d); rep(i,s) r[i] = -r[i]; return r;}
  fps& operator+=(const fps& a) { rsz(sz(a)); rep(i,sz(a)) d[i] += a[i]; return d;}
  fps& operator-=(const fps& a) { rsz(sz(a)); rep(i,sz(a)) d[i] -= a[i]; return d;}
  fps& operator*=(const fps& a) { return d = ntt(d, a);}
  fps& operator/=(const fps& a) {
    int w = s-sz(a)+1; if (w <= 0) return d = 0;
    return (rev_().low_(w) *= a.rev().inv(w)).low_(w).rev_();
  }
  fps& operator%=(const fps& a) { return (d -= d/a*a).low_(sz(a)-1);}
  fps& operator*=(mint a) { rep(i,s) d[i] *= a; return d;}
  fps& operator/=(mint a) { return d *= ~a;}
  fps& operator*=(int a) { return d *= mint(a);}
  fps& operator/=(int a) { return d /= mint(a);}
  fps operator+(const fps& a) const { return fps(d) += a;}
  fps operator-(const fps& a) const { return fps(d) -= a;}
  fps operator*(const fps& a) const { return fps(d) *= a;}
  fps operator/(const fps& a) const { return fps(d) /= a;}
  fps operator%(const fps& a) const { return fps(d) %= a;}
  fps operator*(mint a) const { return fps(d) *= a;}
  fps operator/(mint a) const { return fps(d) *= ~a;}
  fps operator*(int a) const { return fps(d) *= mint(a);}
  fps operator/(int a) const { return fps(d) /= mint(a);}
  fps& mul1(mint a) { pb(0); drep(i,s-1) d[i+1] += d[i], d[i] *= a; return d;} // *=(x+a), /=(x+a)
  fps& div1(mint a) { mint pre = back(); pop_back(); drep(i,s) std::swap(pre, d[i]), pre -= d[i]*a; return d;}
  fps dif() const { fps r(s-1); rrep(i,sz(r)) r[i-1] = d[i]*i; return r;}
  fps integ() const { fps r(s+1); rrep(i,s) r[i] = d[i-1]*invs(i); return r;}
  fps inv() const { return inv(s);}
  fps inv(int w) const {
    fps r({~d[0]});
    for (int i = 1; i < w; i <<= 1) r = r*2 - low(r*r*low(i<<1), i<<1);
    return r.low_(w);
  }
  vm operator()(const vm& x) const {
    int n = sz(x), n2 = n<<1;
    vc<fps> t(n2);
    rep(i,n) t[n+i] = {-x[i],1};
    for (int i = n-1; i; --i) t[i] = t[i<<1]*t[i<<1|1];
    t[1] = d%t[1];
    srep(i,2,n2) t[i] = t[i>>1]%t[i];
    vm r(n);
    rep(i,n) r[i] = t[n+i][0];
    return r;
  }
  fps taylorShift(mint c) const {
    fps res, a(s), b(s,1);
    rep(i,s) a[i] = d[i]*facs(i);
    drep(i,s-1) b[i] = b[i+1]*c;
    rep(i,s) b[i] *= ifacs(s-1-i);
    a *= b;
    rep(i,s) res[i] = a[s-1+i]*ifacs[i];
    return res;
  }
  fps combConv(bool _inv=true) const {
    fps res, a(s), b(s);
    rep(i,s) a[i] = d[i]*ifacs(i);
    rep(i,s) b[i] = ifacs(i);
    if (_inv) rep(i,s) if (i&1) b[i] = -b[i];
    a *= b;
    rep(i,s) res[i] = a[i]*facs(i);
    return res;
  }
#undef s
#undef d
};


struct Solver {
  void solve() {
    int n,k;
    scanf("%d%d",&n,&k);
    vi a(n);
    cin>>a;
    vm f(n+1);

    srep(i,1,n) {
      mint c = mint(n)*k - mint(n-i)*(k-2) - n;
      f[i+1] = (c*f[i] - mint(k-1)*i*f[i-1] - mint(i)*k) * invs(n-i);
    }

    map<int,int> mp;
    for (int x : a) mp[x]++;
    int r = mp[-1];
    fps c, d;
    for (auto p : mp) if (p.fi != -1) d[p.se] += 1;
    d[0] = k-(sz(mp)-1);

    mint kx = 1;
    drep(i,r+1) c[i] = comb(r,i)*kx, kx *= k-1;
    d *= c;
    mint ans = 0;
    rep(i,n+1) ans += f[i]*d[i];

    ans /= ex(k,r);
    ans -= f[n];
    cout<<ans<<endl;
  }
};

int main() {
  int ts = 1;
  // scanf("%d",&ts);
  rrep(ti,ts) {
    Solver solver;
    solver.solve();
  }
  return 0;
}
