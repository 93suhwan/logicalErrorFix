#include <bits/stdc++.h>
using namespace std;
const int maxp = 22;
const long double EPS = 1e-18;
const long long INF = 2e18;
const int MOD = 1e9 + 7;
const int N = 3e5 + 1;
void yesno(bool a) {
  if (a) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
long long power(long long x, long long n, long long m) {
  if (n == 0) return 1;
  long long u = power(x, n / 2, m);
  u = (u * u) % m;
  if (n % 2) u = (u * x) % m;
  return u;
}
vector<vector<int> > a(N);
int ans;
bool dfs(int s, int e) {
  int cnt[2] = {};
  for (auto x : a[s]) {
    if (x == e) continue;
    cnt[dfs(x, s)]++;
  }
  if (cnt[0] + cnt[1] == 0) {
    ans++;
    return true;
  }
  ans -= cnt[0];
  if (!cnt[1]) {
    ans++;
    return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ans = 0;
    int i;
    for (i = 1; i <= n; i++) {
      a[i].clear();
    }
    for (i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      a[x].push_back(y);
      a[y].push_back(x);
    }
    dfs(1, 1);
    cout << ans << '\n';
  }
}
