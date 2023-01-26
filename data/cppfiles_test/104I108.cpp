#include <bits/stdc++.h>
using namespace std;
int a[200005];
int p[200005];
int n, m;
pair<int, int> t[200005];
int len;
vector<int> ans;
void solve(int x) {
  ans.emplace_back(x);
  int val = a[x] ^ a[x + 1] ^ a[x + 2];
  a[x] = a[x + 1] = a[x + 2] = val;
}
void print() {
  cout << "YES\n";
  cout << ans.size() << '\n';
  if (ans.empty()) return;
  for (auto u : ans) cout << u << ' ';
  cout << '\n';
}
void solve() {
  cin >> n;
  ans.clear();
  m = len = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int pis = 1;
  while (pis <= n && a[pis]) pis++;
  if (pis + 1 <= n && a[pis + 1]) {
    solve(pis - 1);
  }
  pis = n;
  while (pis && a[pis]) pis--;
  if (pis - 1 >= 1 && a[pis - 1]) {
    solve(pis - 1);
  }
  for (int i = 1; i <= n; i++)
    if (a[i]) p[++m] = i;
  if ((m & 1) || n == m) {
    cout << "NO\n";
    return;
  }
  int l = 1;
  p[m + 1] = 1e9;
  for (int i = 2; i <= m + 1; i++) {
    if (p[i] > p[i - 1] + 1) {
      if ((i - l) & 1) {
        t[++len] = make_pair(p[l], p[i - 1]);
      } else {
        if (p[l] > 1) {
          for (int j = l; j < i; j += 2) solve(p[j] - 1);
        } else {
          for (int j = i - 2; j >= l; j -= 2) solve(p[j]);
        }
      }
      l = i;
    }
  }
  if (len == 2 && t[1].first == 1 && t[2].second == n) {
    cout << "NO\n";
    return;
  }
  for (int i = 1; i <= len; i += 2) {
    if (t[i + 1].second < n) {
      for (int j = t[i + 1].second - 1; j >= t[i + 1].first; j -= 2) solve(j);
      int pos = t[i + 1].first;
      while (pos - t[i].second + 1 > 3) {
        solve(pos - 2);
        solve(pos - 1);
        pos -= 2;
      }
      solve(t[i].second);
      for (int j = t[i].second - 1; j >= t[i].first; j -= 2) {
        solve(j);
      }
    } else {
      for (int j = t[i].first; j < t[i].second; j += 2) solve(t[i].first - 1);
      int pos = t[i].second;
      while (t[i + 1].first - pos + 1 > 3) {
        solve(pos);
        solve(pos - 1);
        pos += 2;
      }
      solve(t[i + 1].first - 2);
      for (int j = t[i + 1].first + 1; j <= t[i + 1].second; j += 2)
        solve(j - 1);
    }
  }
  print();
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
