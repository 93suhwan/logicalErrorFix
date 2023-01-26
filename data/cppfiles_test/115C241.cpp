#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2 * 1e5 + 10, maxm = 2 * 1e5 + 10, mod = 1e9 + 7;
const long long inf32 = 0x3f3f3f3f;
const long long inf64 = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1), eps = 1e-6;
mt19937 rnd(time(0));
long long T;
long long n, m;
long long a[maxn];
long long b[maxn];
long long check(long long x) {
  long long res = 0;
  long long t = 0, cnt = 0;
  for (long long i = 1; i <= n; i++) {
    if (a[i] + x > a[i + 1]) {
      res += a[i + 1] - a[i];
      t += a[i + 1] - a[i];
    } else {
      res += x;
      cnt++;
    }
  }
  if (res >= m) {
    return (m - t + cnt - 1) / cnt;
  }
  return -1;
}
long long solve() {
  for (long long i = 1; i < n; i++) {
    b[i] = a[i + 1] - a[i];
  }
  b[n] = inf64;
  priority_queue<long long, vector<long long>, greater<long long>> q;
  for (long long i = 1; i <= n; i++) {
    q.push(b[i]);
  }
  while (q.size()) {
    long long now = q.top();
    if (check(now) != -1) {
      return check(now);
    }
    while (q.top() == now) {
      q.pop();
    }
  }
  return -1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    a[n + 1] = inf64 + inf32;
    if (n >= m) {
      cout << 1 << "\n";
      continue;
    }
    cout << solve() << "\n";
  }
  return 0;
}
