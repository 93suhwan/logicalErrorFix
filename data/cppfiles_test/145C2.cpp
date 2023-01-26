#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
long long power(long long a, long long b) {
  long long res = 1;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long fermat_inv(long long y) { return power(y, MOD - 2); }
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
class Dsu {
 public:
  long long n;
  vector<long long> parent;
  vector<long long> height;
  vector<long long> sz;
  Dsu(long long _n) {
    n = _n;
    parent.resize(n + 1);
    height.resize(n + 1, 0);
    sz.resize(n + 1, 1);
    for (long long i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }
  long long getSize(long long x) { return sz[findPar(x)]; }
  long long findPar(long long x) {
    if (parent[x] == x) {
      return x;
    }
    long long p = findPar(parent[x]);
    parent[x] = p;
    return p;
  }
  void unite(long long x, long long y) {
    long long x_par = findPar(x), y_par = findPar(y);
    if (x_par == y_par) {
      return;
    }
    if (height[x_par] < height[y_par]) {
      parent[x_par] = y_par;
      sz[y_par] += sz[x_par];
    } else {
      parent[y_par] = x_par;
      sz[x_par] += sz[y_par];
    }
  }
};
void solveQuestion() {
  long long n, k;
  cin >> n >> k;
  vector<array<long long, 3> > arr(n);
  vector<array<long long, 3> > y_index(n), x_index(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    x_index[i] = {arr[i][0], arr[i][1], i};
    y_index[i] = {arr[i][1], arr[i][0], i};
  }
  sort(x_index.begin(), x_index.end());
  sort(y_index.begin(), y_index.end());
  Dsu d(n);
  for (long long i = 0; i < (n - 1); i++) {
    if ((x_index[i][0] == x_index[i + 1][0]) &&
        (x_index[i + 1][1] - x_index[i][1]) <= k) {
      d.unite(x_index[i + 1][2], x_index[i][2]);
    }
  }
  for (long long i = 0; i < (n - 1); i++) {
    if ((y_index[i][0] == y_index[i + 1][0]) &&
        (y_index[i + 1][1] - y_index[i][1]) <= k) {
      d.unite(y_index[i + 1][2], y_index[i][2]);
    }
  }
  map<long long, long long> lowestTimeComponent;
  for (long long i = 0; i < n; i++) {
    long long par = d.findPar(i);
    if (lowestTimeComponent.count(par)) {
      lowestTimeComponent[par] = min(lowestTimeComponent[par], arr[i][2]);
    } else {
      lowestTimeComponent[par] = arr[i][2];
    }
  }
  vector<long long> times;
  for (auto it : lowestTimeComponent) {
    times.push_back(it.second);
  }
  sort(times.begin(), times.end());
  long long N = times.size(), ans = min(N - 1, times.back());
  for (long long i = 1; i < N; i++) {
    ans = min(ans, max(times[i - 1], N - i - 1));
  }
  cout << ans << "\n";
}
int32_t main(int32_t argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt-- > 0) {
    solveQuestion();
  }
  return 0;
}
