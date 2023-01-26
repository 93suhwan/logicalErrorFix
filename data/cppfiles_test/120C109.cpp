#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int MAX = 1e9 + 1;
const long long modd = 998244353;
const int MAXN = 2e5 + 10;
const long long val = 1073741824;
long long cnt = 0;
vector<int> prime(MAXN, 0);
vector<int> check(MAXN, 0);
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b > a) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long pwr2(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long ans = pwr2(a, b / 2);
  if (b % 2 == 0) return (ans * ans) % modd;
  return ((ans * ans) % modd * a) % modd;
}
void traversal(vector<vector<int>> &mat, int n, int m, int i, int j, int &cnt) {
  if (i >= n || i < 0 || j >= m || j < 0 || mat[i][j] != 1) {
    return;
  }
  mat[i][j] = 2;
  cnt++;
  traversal(mat, n, m, i + 1, j, cnt);
  traversal(mat, n, m, i - 1, j, cnt);
  traversal(mat, n, m, i, j + 1, cnt);
  traversal(mat, n, m, i, j - 1, cnt);
}
static bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first > b.first;
}
void generate_prime() {
  for (int i = 2; i <= 10000000; i++) {
    if (!check[i]) prime[cnt++] = i;
    for (int j = 0; j < cnt && prime[j] * i <= 10000000; j++) {
      check[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int nCr(int n, int r) {
  int p = 1, k = 1;
  if (n - r < r) r = n - r;
  if (r != 0) {
    while (r) {
      p *= n;
      k *= r;
      int m = gcd(p, k);
      p /= m;
      k /= m;
      n--;
      r--;
    }
  } else {
    p = 1;
  }
  return p;
}
long long rev(long long x) {
  long long ans = 0, m = 0;
  m = log2(x) + 1;
  for (int i = 0; i < m; i++) {
    if (x & (1LL << i)) ans += (1LL << (m - i - 1));
  }
  return ans;
}
int pre[MAXN][21];
void precalculate() {
  memset(pre, 0, sizeof(pre));
  for (int i = 1; i < MAXN; i++) {
    for (int j = 0; j <= 20; j++) {
      if (i < (1 << j)) break;
      if (i & (1 << j)) {
        pre[i][j] = 1;
      }
      pre[i][j] += pre[i - 1][j];
    }
  }
}
int solve() {
  long long t, i = 0, j = 0, sum = 0, k = 0, l, r, temp, count = 0;
  long long n, m, c = 0, nH = 0, nT = 0, x, y, z, ans = INT_MIN, zero = 0,
                  one = 0;
  cin >> l >> r;
  n = log2(l);
  m = log2(r);
  if (n == m) {
    cout << 0 << '\n';
    return 0;
  }
  for (int i = 0; i <= 20; i++) {
    temp = pre[r][i] - pre[l - 1][i];
    ans = max(ans, temp);
  }
  cout << r - l + 1 - ans << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, ans, temp, sum, k;
  string sans;
  t = 1;
  precalculate();
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
