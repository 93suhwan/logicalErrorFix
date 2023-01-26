#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define drep(i,j,n) for(int i=0;i<(int)(n-1);i++)for(int j=i+1;j<(int)(n);j++)
#define trep(i,j,k,n) for(int i=0;i<(int)(n-2);i++)for(int j=i+1;j<(int)(n-1);j++)for(int k=j+1;k<(int)(n);k++)
#define codefor int test;scanf("%d",&test);while(test--)
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define yes(ans) if(ans)printf("yes\n");else printf("no\n")
#define Yes(ans) if(ans)printf("Yes\n");else printf("No\n")
#define YES(ans) if(ans)printf("YES\n");else printf("NO\n")
#define popcount(v) __builtin_popcount(v)
#define vector1d(type,name,...) vector<type>name(__VA_ARGS__)
#define vector2d(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define vector3d(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
using namespace std;
using ll = long long;
template<class T>using rpriority_queue = priority_queue<T, vector<T>, greater<T>>;
const int MOD=1000000007;
const int MOD2=998244353;
const int INF=1<<30;
const ll INF2=(ll)1<<60;
//入力系
void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T,class L>void scan(pair<T, L>& p){scan(p.first);scan(p.second);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}
//出力系
void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T,class L>void print(const pair<T, L>& p){print(p.first);putchar(' ');print(p.second);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}
//デバッグ系
template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll modinv(ll a, ll m) {ll b = m, u = 1, v = 0;while (b) {ll t = a / b;a -= t * b; swap(a, b);u -= t * v; swap(u, v);}u %= m;if (u < 0) u += m;return u;}
ll updivide(ll a,ll b){if(a%b==0) return a/b;else return (a/b)+1;}
template<class T> void chmax(T &a,const T b){if(b>a)a=b;}
template<class T> void chmin(T &a,const T b){if(b<a)a=b;}

namespace internal {
constexpr long long safe_mod(long long x, long long m) {x %= m;if (x < 0) x += m;return x;}
struct barrett {
    unsigned int _m;
    unsigned long long im;
    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    unsigned int umod() const { return _m; }
    unsigned int mul(unsigned int a, unsigned int b) const {
        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned long long)(z)*im));
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}
constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {y = y * y % n;t <<= 1;}
        if (y != n - 1 && t % 2 == 0) {return false;}
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};
    long long s = b, t = a;
    long long m0 = 0, m1 = 1;
    while (t) {long long u = s / t;s -= t * u;m0 -= m1 * u;auto tmp = s;s = t;t = tmp;tmp = m0;m0 = m1;m1 = tmp;}
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}
constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {divs[cnt++] = i;while (x % i == 0) {x /= i;}}
    }
    if (x > 1) {divs[cnt++] = x;}
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {ok = false;break;}
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);
unsigned long long floor_sum_unsigned(unsigned long long n,unsigned long long m,unsigned long long a,unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {ans += n * (n - 1) / 2 * (a / m);a %= m;}
        if (b >= m) {ans += n * (b / m);b %= m;}
        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}
template <class T> using is_integral = typename std::is_integral<T>;
template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;
template <class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T> using to_unsigned_t = typename to_unsigned<T>::type;
struct modint_base {};
struct static_modint_base : modint_base {};
template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;
}  // namespace internal
template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;
  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {mint x;x._v = v;return x;}
    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();_v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {_v = (unsigned int)(v % umod());}
    unsigned int val() const { return _v; }
    mint& operator++() {_v++;if (_v == umod()) _v = 0;return *this;}
    mint& operator--() {if (_v == 0) _v = umod();_v--;return *this;}
    mint operator++(int) {mint result = *this;++*this;return result;}
    mint operator--(int) {mint result = *this;--*this;return result;}
    mint& operator+=(const mint& rhs) {_v += rhs._v;if (_v >= umod()) _v -= umod();return *this;}
    mint& operator-=(const mint& rhs) {_v -= rhs._v;if (_v >= umod()) _v += umod();return *this;}
    mint& operator*=(const mint& rhs) {unsigned long long z = _v;z *= rhs._v;_v = (unsigned int)(z % umod());return *this;}
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }
    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }
    mint pow(long long n) const {assert(0 <= n);mint x = *this, r = 1;while (n) {if (n & 1) r *= x;x *= x;n >>= 1;}return r;}
    mint inv() const {if (prime) {assert(_v);return pow(umod() - 2);} else {auto eg = internal::inv_gcd(_v, m);assert(eg.first == 1);return eg.second;}}
    friend mint operator+(const mint& lhs, const mint& rhs) {return mint(lhs) += rhs;}
    friend mint operator-(const mint& lhs, const mint& rhs) {return mint(lhs) -= rhs;}
    friend mint operator*(const mint& lhs, const mint& rhs) {return mint(lhs) *= rhs;}
    friend mint operator/(const mint& lhs, const mint& rhs) {return mint(lhs) /= rhs;}
    friend bool operator==(const mint& lhs, const mint& rhs) {return lhs._v == rhs._v;}
    friend bool operator!=(const mint& lhs, const mint& rhs) {return lhs._v != rhs._v;}
    //自分で加えたもの
    friend istream& operator>>(istream& os,mint& rhs) noexcept {
        long long v;
        rhs = mint{(os >> v, v)};
        return os;
    }
    friend constexpr ostream& operator << (ostream &os, const mint& rhs) noexcept {
        return os << rhs._v;
    }
  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};
using mint=static_modint<1000000007>;
using mint2=static_modint<998244353>;

int main(){
    codefor{
        INT(n);
        deque<ll> a(n);
        rep(i,n)in(a[i]);
        sort(all(a));
        ll sumv=0;
        /*rep(i,n){
            if(i)cerr<<' ';
            cerr<<a[i];
        }
        cerr<<endl;*/
        while(a.size()>=2){
            /*rep(i,a.size()){
                if(i)cerr<<' ';
                cerr<<sumv+a[i];
            }
            cerr<<endl;*/
            if(sumv+a[1]-(sumv+a[0])>=sumv+a[0]){
                sumv-=sumv+a[0];
                a.pop_front();
            }else break;
        }
        ll ans=sumv+a[0];
        for(int i=1;i<a.size();i++){
            chmax(ans,sumv+a[0]-(sumv+a[1]));
        }
        out(ans);
    }
}