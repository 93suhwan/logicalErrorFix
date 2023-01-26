#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e6 + 10;
const long long inf = 1e18;
const int maxm = 1005;
vector<vector<char>> matrix(maxm, vector<char>(maxm));
struct event {
  int x, y, size;
};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
struct myComp {
  constexpr bool operator()(pair<int, int> const& a,
                            pair<int, int> const& b) const noexcept {
    return a.first < b.first;
  }
};
class even {
 public:
  int a, b, c, ind;
};
long long poww(long long a, long long b, long long m) {
  if (b == 0) return 1ll;
  if (b % 2 == 1) return a * poww(a, b - 1, m) % m;
  long long rs = poww(a, b / 2, m);
  rs = rs * rs % m;
  return rs;
}
long long fact[N];
long long ncr(long long n, long long r) {
  long long num = fact[n];
  long long deno = fact[n - r] * fact[r] % mod;
  deno = poww(deno, mod - 2, mod);
  num = num * deno;
  num = num % mod;
  return num;
}
vector<int> parent(N), st(N);
void set_parent() {
  for (int i = 0; i < N; i++) parent[i] = i, st[i] = 1;
}
int find_parent(int v) {
  if (parent[v] == v)
    return v;
  else
    return parent[v] = find_parent(parent[v]);
}
int x = 1;
void union_set(int a, int b) {
  int temp = a;
  if (a == b) return;
  a = find_parent(a);
  b = find_parent(b);
  if (a == b) {
    x = temp;
    return;
  }
  if (st[a] < st[b]) swap(a, b);
  st[a] += st[b];
  parent[b] = a;
}
const int maxx = 1e7 + 10;
vector<long long> spf(maxx, -1);
void sieve() {
  spf[1] = 1;
  for (long long i = 2; i * i < maxx; i++) {
    if (spf[i] == -1) {
      spf[i] = i;
      for (long long j = i * i; j < maxx; j += i) {
        if (spf[j] == -1) spf[j] = i;
      }
    }
  }
}
bool ok(int mid, int n, int m) {
  int res = 0;
  for (int i = 0; i < 32; i++) {
    if (mid & (1 << i)) {
      if (n & (1 << i)) {
      } else
        res += 1 << i;
    } else {
      if (n & (1 << i)) res += 1 << i;
    }
  }
  cout << mid << " " << res << " " << m << "\n";
  if (res <= m) return true;
  return false;
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  vector<vector<int>> sum(2, vector<int>(n + 1));
  if (n == 1) {
    cout << 0 << "\n";
    return;
  }
  long long ss = 0;
  for (int i = n - 1; i >= 1; i--) ss += a[0][i];
  int res = ss;
  long long ss2 = 0;
  for (int i = 0; i < n - 1; i++) {
    ss2 += a[1][i];
    ss -= a[0][i + 1];
    int temp = max(ss, ss2);
    res = min(res, temp);
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
