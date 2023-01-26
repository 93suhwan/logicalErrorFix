#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int64_t longinf = LLONG_MAX - 100000;
const long long inf = INT_MAX;
long long pw(long long x, long long y, long long p = longinf) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long invmod(long long a, long long m = mod) { return pw(a, m - 2, m); }
long long cl(long long a, long long x) {
  return a % x == 0 ? a / x : a / x + 1;
}
const long long N = 1e5 + 10;
long long parent[N], siz[N];
long long findParent(long long i) {
  if (i == parent[i]) return i;
  return parent[i] = findParent(parent[i]);
}
void unionNodes(long long a, long long b) {
  long long parent_a = findParent(a), parent_b = findParent(b);
  if (parent_a == parent_b) return;
  if (siz[parent_a] >= siz[parent_b]) {
    swap(parent_a, parent_b);
  }
  siz[parent_b] += siz[parent_a];
  parent[parent_a] = parent_b;
}
void cleardsu(long long n) {
  for (long long i = 0; i <= n; i++) {
    parent[i] = i;
    siz[i] = 1;
  }
}
void run_time_terror(long long case_no = 0) {
  long long n, k;
  cin >> n >> k;
  set<pair<long long, long long> > ans;
  cleardsu(n + 5);
  for (long long i = 0; i < k; ++i) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (findParent(a) == findParent(c)) continue;
    unionNodes(a, c);
    if (ans.find({c, a}) == ans.end() or ans.find({a, c}) == ans.end())
      ans.insert({a, c});
  }
  set<long long> s;
  for (long long i = 0; i < n; ++i) {
    s.insert(findParent(i + 1));
  }
  long long p = *s.begin();
  s.erase(p);
  for (auto &it : s) {
    if (ans.find({p, it}) == ans.end() or ans.find({it, p}) == ans.end())
      ans.insert({p, it});
  }
  for (auto &it : ans) {
    cout << it.first << " " << it.second << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0), cout.setf(ios::fixed);
  cout << setprecision(0);
  long long tt = 1;
  cin >> tt;
  for (long long case_no = 1; case_no <= tt; case_no++) {
    run_time_terror(case_no);
  }
  return 0;
}
