#include <bits/stdc++.h>
using namespace std;
const int DIR4[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int DIR8[8][2] = {{1, 0},   {-1, 0}, {0, 1},  {0, -1},
                        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
const int MOD197 = 1e9 + 7;
const int MOD19 = 1e9;
const int MOD353 = 998244353;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const long long LNINF = 0xc0c0c0c0c0c0c0c0;
inline int LT(int x) { return x << 1; }
inline int RT(int x) { return (x << 1) | 1; }
inline int LB(int x) { return x & -x; }
inline int MSK(int x) { return 1 << x; }
inline int HF(int x) { return x >> 1; }
inline int DB(int x) { return x << 1; }
inline int GT(int x, int i) { return (x >> i) & 1; }
inline int ST(int x, int i) { return x | (1 << i); }
inline int ODD(int x) { return x & 1; }
inline int SGN(int x) { return x >= 0 ? (x == 0 ? 0 : 1) : -1; }
template <int mod>
long long fpow(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1, a = (a * a) % mod)
    if (b & 1) ans = (ans * a) % mod;
  return ans;
}
template <int mod>
struct MODINT {
  long long val;
  MODINT() : val(0) {}
  MODINT(long long v) : val(v % mod) {}
  MODINT operator+(const MODINT &o) const { return MODINT(val + o.val); }
  MODINT &operator+=(const MODINT &o) {
    val = (val + o.val) % mod;
    return *this;
  }
  MODINT operator*(const MODINT &o) const { return MODINT(val * o.val); }
  MODINT &operator*=(const MODINT &o) {
    val = (val * o.val) % mod;
    return *this;
  }
  MODINT operator-(const MODINT &o) const {
    return MODINT((val - o.val) % mod + mod);
  }
  MODINT &operator-=(const MODINT &o) {
    val = ((val - o.val) % mod + mod) % mod;
    return *this;
  }
  MODINT operator/(const MODINT &o) const {
    return MODINT(val * fpow<mod>(o.val, mod - 2));
  }
  MODINT &operator/=(const MODINT &o) {
    val = (val * fpow<mod>(o.val, mod - 2)) % mod;
    return *this;
  }
};
template <int mod>
ostream &operator<<(ostream &out, const MODINT<mod> &val) {
  out << val.val;
  return out;
}
long long fdiv(long long a, long long b) {
  return a / b - ((a ^ b) < 0 && a % b);
}
long long cdiv(long long a, long long b) {
  return a / b + ((a ^ b) > 0 && a % b);
}
int a[1000005];
int b[1000005];
int p[1000005];
int big[1000005];
int sml[1000005];
long long tree[3000005];
int N;
void add(int x, long long val) {
  while (x <= N) {
    tree[x] += val;
    x += LB(x);
  }
}
long long query(int x) {
  long long val = 0;
  while (x) {
    val += tree[x];
    x -= LB(x);
  }
  return val;
}
void conquer(int bl, int br, int al, int ar) {
  if (bl > br) return;
  int mid = (bl + br) / 2;
  big[al] = 0;
  for (int i = al + 1; i <= ar; i++) {
    big[i] = big[i - 1];
    if (a[i - 1] > b[mid]) big[i]++;
  }
  sml[ar + 1] = 0;
  for (int i = ar; i >= al; i--) {
    sml[i] = sml[i + 1];
    if (a[i] < b[mid]) sml[i]++;
  }
  p[mid] = al;
  for (int i = al; i <= ar; i++) {
    if (big[i] + sml[i] < big[p[mid]] + sml[p[mid]]) p[mid] = i;
  }
  conquer(bl, mid - 1, al, p[mid]);
  conquer(mid + 1, br, p[mid], ar);
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(b + 1, b + m + 1);
  a[n + 1] = INT_MAX;
  conquer(1, m, 1, n + 1);
  vector<int> lis;
  int ptr = 1;
  for (int i = 1; i <= n + 1; i++) {
    while (ptr <= m && p[ptr] == i) lis.push_back(b[ptr++]);
    lis.push_back(a[i]);
  }
  vector<int> decre;
  for (int i : lis) decre.push_back(i);
  sort(decre.begin(), decre.end());
  decre.erase(unique(decre.begin(), decre.end()), decre.end());
  for (int i = 0; i < lis.size(); i++)
    lis[i] =
        lower_bound(decre.begin(), decre.end(), lis[i]) - decre.begin() + 1;
  N = decre.size();
  for (int i = 0; i <= N; i++) tree[i] = 0;
  long long ans = 0;
  for (int i = 0; i < lis.size(); i++) {
    ans += i - query(lis[i]);
    add(lis[i], 1);
  }
  cout << ans << endl;
}
int main() {
  ;
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
