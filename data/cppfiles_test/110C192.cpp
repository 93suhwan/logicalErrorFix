#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 7;
const int MAXN = 3e5 + 7;
const long long MOD = 998244353;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long fpow(long long a, long long b) {
  if (a == 0) return 0;
  long long ans = 1;
  for (; b; b >>= 1, a = ((a * a) % MOD))
    if (b & 1) ans = ((ans * a) % MOD);
  return ans;
}
int gcdint(int a, int b) { return b ? gcd(b, a % b) : a; }
int fpowint(int a, int b) {
  if (a == 0) return 0;
  int ans = 1;
  for (; b; b >>= 1, a = a * a)
    if (b & 1) ans = ans * a;
  return ans;
}
void solve(int ca) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      p;
  int n, t, u;
  scanf("%d", &n);
  int a[n + 1];
  vector<int> v[n + 1];
  int ans = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    a[i] = t;
    if (t == 0) p.push({1, i}), cnt++;
    while (t--) {
      scanf("%d", &u);
      v[u].push_back(i);
    }
  }
  while (!p.empty()) {
    int now = p.top().first;
    int pos = p.top().second;
    ans = now;
    p.pop();
    for (int c : v[pos]) {
      a[c]--;
      if (a[c] == 0) {
        cnt++;
        if (c > pos)
          p.push({now, c});
        else
          p.push({now + 1, c});
      }
    }
  }
  if (cnt < n) ans = -1;
  printf("%d\n", ans);
}
int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) solve(i);
}
