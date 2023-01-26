#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const long long inf = 3e18;
const long long MAXN = 1e5 + 10;
const long long R = 1 << 19;
const long long mod = 1e9 + 7;
const long long LOGN = 21;
vector<long long> P(1e6 + 10, -1);
void init() {
  for (long long i = 2; i < (long long)P.size(); ++i) {
    if (P[i] == -1) {
      P[i] = i;
      for (long long j = i * i; j < (long long)P.size(); j += i)
        if (P[j] == -1) P[j] = i;
    }
  }
}
long long ok(long long n) {
  for (long long i = 2; i < (long long)P.size(); ++i) {
    if (P[i] == -1) {
      P[i] = i;
      for (long long j = i * i; j < (long long)P.size(); j += i)
        if (P[j] == -1) P[j] = i;
    }
  }
  long long cur = 0;
  for (long long i = (n - 1) / 2 + 1; i <= n; ++i) {
    long long x = i;
    while (P[x] != -1) {
      cur ^= P[x];
      x /= P[x];
    }
  }
  return cur == 0;
}
long long ok2(long long n) {
  long long cur = 0;
  for (long long i = 1; i <= n; ++i) {
    long long x = i;
    while (P[x] != -1) {
      cur ^= P[x];
      x /= P[x];
    }
  }
  cur ^= 2;
  return cur == 0;
}
void solve() {
  init();
  long long n;
  cin >> n;
  vector<long long> cur(n + 1, 1);
  if (n % 2 != 0 && (n / 2) % 2 == 0 && ok2(n / 2)) {
    cur[n] = 0;
    cur[1] = 1;
  } else {
    if (n % 2 != 0 && (n / 2) % 2 != 0 && ok(n)) {
      cur[2] = 0;
      cur[1] = 1;
    } else {
      if (n % 2 == 1) {
        cur[n] = 0;
        --n;
      }
      n /= 2;
      cur[n] = 0;
      if (n % 2 != 0) cur[2] = 0;
      cur[1] = 1;
    }
  }
  vector<long long> ans;
  for (long long i = 1; i < (long long)cur.size(); ++i)
    if (cur[i]) ans.push_back(i);
  cout << (long long)ans.size() << "\n";
  for (auto x : ans) cout << x << " ";
  cout << "\n";
}
void solve2() {
  cout << "======"
       << "\n";
  long long n;
  cin >> n;
  long long ans = 0;
  for (long long i = 1; i < (1 << (n)); ++i) {
    vector<long long> cur;
    long long cnt = 0;
    for (long long j = 0; j < n; ++j)
      if ((1 << j) & i) {
        cur.push_back(j + 1);
        ++cnt;
      }
    long long x = 1;
    for (auto y : cur)
      for (long long j = 1; j <= y; ++j) x *= j;
    long long k = sqrt(x);
    while (k * k < x) k++;
    if (k * k == x) ans = max(ans, cnt);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
