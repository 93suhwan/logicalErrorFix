#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Print(T v, int st = 0, int end = -1) {
  if (end == -1) end = (int)v.size() - 1;
  for (int i = st; i <= end; i++) cout << v[i] << (" ");
  cout << '\n';
}
int MOD = 998244353;
struct Mint {
  int val;
  bool operator==(const Mint& other) { return val == other.val; }
  Mint operator+(const Mint& other) {
    int res = val + other.val;
    while (res >= MOD) res -= MOD;
    while (res < 0) res += MOD;
    return Mint(res);
  }
  Mint operator-(const Mint& other) {
    int res = val - other.val;
    while (res >= MOD) res -= MOD;
    while (res < 0) res += MOD;
    return Mint(res);
  }
  Mint operator*(const Mint& other) {
    return Mint((val * 1ll * other.val) % MOD);
  }
  void operator-=(const Mint& other) { *this = *this - other; }
  void operator+=(const Mint& other) { *this = *this + other; }
  void operator*=(const Mint& other) { *this = *this * other; }
  Mint pow(int y) {
    Mint z(1);
    Mint x(val);
    while (y > 0) {
      if (y % 2 == 1) z = z * x;
      x = x * x;
      y /= 2;
    }
    return z;
  }
  Mint operator/(const Mint& other) {
    return Mint(val) * Mint(other.val).pow(MOD - 2);
  }
  void operator/=(const Mint& other) { *this = *this / other; }
  Mint() { val = 0; }
  Mint(int x) {
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    val = x;
  }
};
ostream& operator<<(ostream& out, const Mint& x) { return out << x.val; }
int INF = 998244353;
long long LINF = 1000000000000000000;
long long mod1 = 998244353;
long long mod2 = 1000000007;
long double pi = acos(-1);
long double eps = 1e-11;
const int N = 'z' - 'a', M = 24;
int cnt[M][N + 1];
Mint sum[1 << M];
signed main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (int j = 0; j <= N; j++) {
      while (s.back() == char(j + 'a')) {
        cnt[i][j]++;
        s.pop_back();
      }
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    sum[i] = Mint(1);
    for (int j = 0; j <= N; j++) {
      int m = INF;
      for (int k = 0; k < n; k++) {
        if (1 << k & i) m = min(m, cnt[k][j]);
      }
      sum[i] *= Mint(m + 1);
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    if (__builtin_popcount(i) % 2)
      sum[0] += sum[i];
    else
      sum[0] -= sum[i];
  }
  Mint all = sum[0];
  for (int i = 0; i < n; i++) {
    for (int m = 0; m < (1 << n); m++) {
      if (!((1 << i) & m)) sum[m] -= sum[m ^ (1 << i)];
    }
  }
  for (int i = 0; i < n; i++)
    for (int m = 0; m < (1 << n); m++)
      if ((1 << i) & m) sum[m] += sum[m ^ (1 << i)];
  int re = 0;
  for (int i = 0; i < (1 << n); i++) {
    int k = 0, s = 0;
    int t = (all - sum[((1 << n) - 1) - i]).val;
    for (int j = 0; j < n; j++)
      if ((1 << j) & i) k++, s += j;
    re ^= k * (s + k) * t;
  }
  cout << (re) << '\n';
}
