#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long mod = 998244353;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const int LEVEL = log2(N) + 1;
long long n, m, q, a[N], pre[N], p[N], ct[N], ans = 0;
map<int, int> cur;
void make(long long n) {
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    ct[i] = 0;
  }
}
int find(long long x) { return (p[x] == x) ? x : p[x] = find(p[x]); }
void merge(long long x, long long y) {
  long long a = find(x);
  long long b = find(y);
  if (a != b) {
    p[a] = b;
    ans -= pre[b] - pre[b - ct[b]];
    ans -= pre[a] - pre[a - ct[a]];
    ct[b] += ct[a];
    ans += pre[b] - pre[b - ct[b]];
  }
}
void solve() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n + m; i++) {
    cin >> a[i];
    if (i <= n) cur[a[i]]++;
  }
  sort(a + 1, a + n + m + 1);
  make(n + m);
  for (int i = 1; i <= n + m; i++) {
    pre[i] = pre[i - 1] + a[i];
    if (cur[a[i]]) {
      ct[i]++;
      ans += a[i];
      cur[a[i]]--;
    }
  }
  set<pair<int, int>> second;
  for (int i = 2; i <= n + m; i++) {
    second.insert({a[i] - a[i - 1], i});
  }
  vector<pair<int, int>> v;
  vector<long long> res(q + 1);
  for (int i = 1; i <= q; i++) {
    int k;
    cin >> k;
    v.push_back({i, k});
  }
  sort(v.begin(), v.end());
  for (auto &[i, k] : v) {
    while (second.size() && second.begin()->first <= k) {
      merge(second.begin()->second - 1, second.begin()->second);
      second.erase(second.begin());
    }
    res[i] = ans;
  }
  for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(15);
  ;
  int test = 1;
  for (int i = 1; i <= test; i++) {
    solve();
  }
}
