#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
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
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
vector<long long> parent, rnk;
void make_set(long long n) {
  long long i;
  rnk.assign(n + 1, 0);
  parent.assign(n + 1, 0);
  for (i = 1; i <= n; i++) {
    parent[i] = i;
  }
}
long long find_set(long long u) {
  if (parent[u] == u) return u;
  return parent[u] = find_set(parent[u]);
}
bool union_set(long long u, long long v) {
  u = find_set(u);
  v = find_set(v);
  if (u == v) return false;
  if (rnk[u] < rnk[v]) swap(u, v);
  parent[v] = u;
  if (rnk[v] == rnk[u]) rnk[u]++;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, ans, temp, sum, k;
  string sans;
  t = 1;
  cin >> t;
  while (t--) {
    sans = "NO";
    ans = temp = sum = 0;
    cin >> n >> k;
    make_set(n);
    map<long long, set<pair<long long, long long>>> x_to_y;
    map<long long, set<pair<long long, long long>>> y_to_x;
    vector<long long> x(n + 1, 0), y(n + 1, 0), timer(n + 1, 0);
    for (i = 1; i <= n; i++) {
      cin >> x[i] >> y[i] >> timer[i];
      x_to_y[x[i]].insert({y[i], i});
      y_to_x[y[i]].insert({x[i], i});
    }
    for (i = 1; i <= n; i++) {
      auto it = x_to_y[x[i]].upper_bound(make_pair(y[i], 1000000000000000005));
      if (it != x_to_y[x[i]].end() and it->first - y[i] <= k)
        union_set(i, it->second);
      it = y_to_x[y[i]].upper_bound(make_pair(x[i], 1000000000000000005));
      if (it != y_to_x[y[i]].end() and it->first - x[i] <= k)
        union_set(i, it->second);
    }
    map<long long, long long> min_time;
    for (i = 1; i <= n; i++) min_time[find_set(i)] = 1000000000000000005;
    for (i = 1; i <= n; i++) {
      long long root = find_set(i);
      min_time[root] = min(min_time[root], timer[i]);
    }
    vector<long long> min_times;
    for (auto x : min_time) min_times.push_back(x.second);
    sort((min_times).begin(), (min_times).end());
    ans = (long long)min_time.size() - 1;
    for (i = 0; i <= (long long)min_time.size() - 1; i++) {
      ans = min(ans, max((long long)min_times.size() - 2 - i, min_times[i]));
    }
    cout << ans << "\n";
  }
  return 0;
}
