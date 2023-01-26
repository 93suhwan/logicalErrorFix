#include <bits/stdc++.h>
using namespace std;
const long long N = 2000007;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
long long dx[4] = {-1, 0, 1, 0};
long long dy[4] = {0, 1, 0, -1};
long long n, m, k, t, q, p;
long long a[N], vis[N], b[N];
string s[N];
bool cmp(long long a, long long b) { return a > b; }
signed main() {
  cin >> t;
  while (t--) {
    cin >> n;
    long long mp[100];
    for (long long i = 1; i <= n; i++) {
      cin >> s[i];
    }
    long long ans = 0;
    for (char op = 'a'; op <= 'z'; op++) {
      vector<long long> v;
      for (long long i = 1; i <= n; i++) {
        long long first = 0;
        for (auto j : s[i]) {
          if (j == op)
            first++;
          else
            first--;
        }
        v.push_back(first);
      }
      sort(v.begin(), v.end(), cmp);
      long long now = 0, res = 0;
      for (auto i : v) {
        res++;
        now += i;
        if (now <= 0) break;
      }
      if (now > 0) res++;
      ans = max(ans, res - 1);
    }
    cout << ans << "\n";
  }
  return 0;
}
