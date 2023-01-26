#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 998244353;
const long long mod = 1e9 + 7;
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
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
const int M = 4 * 1e5 + 1;
long long parent[M];
long long size1[M];
void make_set(long long v) {
  parent[v] = v;
  size1[v] = 1;
}
long long find_set(long long v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
bool union_sets(long long a, long long b) {
  a = find_set(a);
  b = find_set(b);
  if (a == b) {
    return false;
  }
  if (a != b) {
    if (size1[a] < size1[b]) swap(a, b);
    parent[b] = a;
    size1[a] += size1[b];
  }
  return true;
}
long long findMinNumber(long long n) {
  long long count = 0, ans = 1;
  while (n % 2 == 0) {
    count++;
    n /= 2;
  }
  if (count % 2) ans *= 2;
  for (int i = 3; i <= sqrt(n); i += 2) {
    count = 0;
    while (n % i == 0) {
      count++;
      n /= i;
    }
    if (count % 2) ans *= i;
  }
  if (n > 2) ans *= n;
  return ans;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long x[n], y[n], i, val[n], j;
    vector<pair<long long, pair<long long, long long>>> v, v1;
    for (i = 0; i < n; i++) {
      cin >> x[i] >> y[i] >> val[i];
      v.push_back({x[i], {y[i], i}});
      v1.push_back({y[i], {x[i], i}});
    }
    for (i = 0; i < n; i++) make_set(i);
    sort((v).begin(), (v).end());
    sort((v1).begin(), (v1).end());
    ;
    for (i = 0; i < n - 1; i++) {
      if (v[i + 1].first == v[i].first and
          abs(v[i + 1].second.first - v[i].second.first) <= k) {
        long long x1 = find_set(v[i + 1].second.second);
        long long y1 = find_set(v[i].second.second);
        if (x1 != y1) {
          union_sets(x1, y1);
          val[find_set(x1)] = min(val[x1], val[y1]);
        }
      }
    }
    for (i = 0; i < n - 1; i++) {
      if (v1[i + 1].first == v1[i].first and
          abs(v1[i + 1].second.first - v1[i].second.first) <= k) {
        long long x1 = find_set(v1[i + 1].second.second);
        long long y1 = find_set(v1[i].second.second);
        if (x1 != y1) {
          union_sets(x1, y1);
          val[find_set(x1)] = min(val[x1], val[y1]);
        }
      }
    }
    vector<bool> vis(n);
    vector<pair<long long, long long>> ans1;
    long long ans = 0;
    for (i = 0; i < n; i++) {
      val[i] = val[find_set(i)];
      ans1.push_back({val[i], i});
    }
    sort((ans1).rbegin(), (ans1).rend());
    for (i = 0; i < n; i++) {
      if (!vis[find_set(ans1[i].second)]) {
        if (ans > find_set(ans1[i].second))
          break;
        else {
          ans++;
          vis[find_set(ans1[i].second)] = true;
        }
      }
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}
