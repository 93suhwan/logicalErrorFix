#include <bits/stdc++.h>
using namespace std;
const long long maxs = 1e6 + 5;
long long root[maxs];
class cmp {
  bool operator()(const long long &a, const long long &b) { return a < b; }
};
void init() { iota(root, root + maxs, 0); }
long long find(long long u) {
  long long f;
  if (root[u] == u)
    return u;
  else {
    long long f = find(root[u]);
    root[u] = f;
    return f;
  }
}
void Union(long long x, long long y) {
  long long u = find(x);
  long long v = find(y);
  root[v] = u;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void update(vector<long long> &BIT, long long ind, long long val) {
  while (ind < BIT.size()) {
    BIT[ind] += val;
    ind += (ind & (-ind));
  }
}
long long query(vector<long long> &BIT, long long ind) {
  long long sum = 0;
  while (ind > 0) {
    sum += BIT[ind];
    ind -= (ind & (-ind));
  }
  return sum;
}
void count_factors() {
  long long i, j;
  long long numOfDivisors[maxs] = {0};
  long long ans[maxs] = {0};
  for (i = 1; i < maxs; i++)
    for (j = i; j < maxs; j += i) {
      numOfDivisors[j]++;
      ans[j]++;
    }
  for (i = 1; i < maxs; i++)
    for (j = i; j < maxs; j += i)
      if (numOfDivisors[j / i] == 4) ans[j] = min(ans[j], ans[i]);
}
long long get(long long x, long long y) {
  if (x == 0) return 1;
  long long cnt = 0;
  while (x % y == 0) {
    cnt++;
    x /= y;
  }
  return cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, k, y, x, j, m, r, l;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<long long> arr(n + 1);
    for (i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= i; j++) {
        dp[i][j] = dp[i - 1][j];
        dp[i][j] = max(dp[i - 1][j - 1] + (arr[i] == j), dp[i][j]);
      }
    }
    long long ans = 0;
    for (i = 1; i <= n; i++) {
      if (dp[n][i] >= k) ans = i;
    }
    if (ans == 0)
      cout << -1 << '\n';
    else
      cout << n - ans << '\n';
  }
  return 0;
}
