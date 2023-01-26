#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
long long GCD(long long a, long long b) { return (a) ? GCD(b % a, a) : b; }
long long LCM(long long a, long long b) { return a * b / GCD(a, b); }
long long fastpow(long long b, long long p) {
  if (!p) return 1;
  long long ret = fastpow(b, p >> 1);
  ret *= ret;
  if (p & 1) ret *= b;
  return ret;
}
long long a[1010];
vector<int> b[1010];
int vis[1010];
long long ans = 0;
int n;
void abbas(int x, long long kam) {
  if (x >= n) {
    ans += kam * (kam - 1) / 2;
    return;
  }
  vis[x] = 1;
  if (b[x].size() && b[x].back() < 0 && b[x].back() != -10000) {
    abbas(-b[x].back() + 1, kam + 1);
  } else {
    if (b[x].size() && b[x].back() == -10000) kam++;
    ans += max(0LL, kam * (kam - 1) / 2);
  }
  for (int i = 0; i < b[x].size(); i++) {
    if (b[x][i] > 0) abbas(b[x][i] + 1, 1);
  }
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n % 2) n--;
  memset(vis, 0, sizeof(vis));
  long long cum = 0;
  long long x;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      cum += a[i];
    } else {
      ans += min(cum, a[i]);
      cum -= min(cum, a[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
    } else {
      x = a[i];
      for (int j = i - 1; j >= 0 && x > 0; j -= 2) {
        if (x > a[j] && a[j])
          x -= a[j], a[j] = 0, b[j].push_back(-10000);
        else if (x == a[j] && a[j])
          x -= a[j], a[j] = 0, b[j].push_back(-i);
        else if (a[j]) {
          a[j] -= x, b[j].push_back(i);
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i += 2)
    if (!vis[i]) abbas(i, 0);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int TT = 1;
  for (int tc = 1; tc <= TT; tc++) {
    solve();
  }
}
