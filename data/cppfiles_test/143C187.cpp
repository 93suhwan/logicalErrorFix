#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  std::cout.tie(0);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> cnt(n + 1);
  for (long long(i) = 0; (i) < (n); (i)++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  vector<long long> ans(n + 1);
  vector<long long> add;
  long long i = 0;
  for (; i < n + 1; i++) {
    ans[i] = cnt[i];
    if (cnt[i] == 0) break;
    for (long long j = 0; j < cnt[i] - 1; j++) add.push_back(i);
  }
  i++;
  for (; i < n + 1; i++) {
    if (ans[i - 1] == -1) {
      ans[i] = -1;
      continue;
    }
    ans[i] = ans[i - 1] + cnt[i] - cnt[i - 1];
    if (cnt[i - 1] == 0) {
      if (add.empty()) {
        ans[i] = -1;
        continue;
      }
      ans[i] += (i - add.back() - 1);
      add.pop_back();
    }
    for (long long j = 0; j < cnt[i] - 1; j++) add.push_back(i);
  }
  for (auto x : ans) cout << x << " ";
  cout << '\n';
}
signed main() {
  fast();
  long long t = 1;
  cin >> t;
  for (long long(i) = 0; (i) < (t); (i)++) {
    solve();
  }
  return 0;
}
