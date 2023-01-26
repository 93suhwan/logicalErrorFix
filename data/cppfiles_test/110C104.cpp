#include <bits/stdc++.h>
using namespace std;
long long modInverse(long long a, long long b) {
  return 1 < a ? b - modInverse(b % a, a) * b / a : 1;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
void solve() {
  long long n;
  cin >> n;
  vector<long long> g[n];
  priority_queue<long long> left, right;
  long long cnt[n];
  memset(cnt, 0, sizeof cnt);
  for (int k = 0; k < n; k++) {
    long long m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      long long x;
      cin >> x;
      x--;
      g[x].push_back(k);
    }
    cnt[k] = m;
    if (m == 0) {
      left.push(k);
    }
  }
  if (left.empty()) {
    cout << "-1\n";
    return;
  }
  long long ans = 0;
  while (1) {
    if (right.empty()) {
      if (left.empty()) break;
      while (!left.empty()) {
        long long x = left.top();
        left.pop();
        right.push(-x);
      }
      ans++;
    }
    long long me = -right.top();
    right.pop();
    for (long long u : g[me]) {
      if (cnt[u] == 0) {
        cout << "-1\n";
        return;
      }
      cnt[u]--;
      if (cnt[u] == 0) {
        if (u > me)
          right.push(-u);
        else
          left.push(u);
      }
    }
  }
  for (int k = 0; k < n; k++) {
    if (cnt[k] > 0) {
      cout << "-1\n";
      return;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
