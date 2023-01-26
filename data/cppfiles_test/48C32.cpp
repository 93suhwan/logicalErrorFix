#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int maxn = 5e5 + 5;
void File() {
  freopen(
      "j4f"
      ".inp",
      "r", stdin);
  freopen(
      "j4f"
      ".out",
      "w", stdout);
}
int n;
pair<int, int> a[maxn];
pair<int, int> p[maxn];
int pos[maxn];
void Swap(int u, int v) {
  swap(pos[a[u].second], pos[a[v].second]);
  swap(a[u], a[v]);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    p[i] = a[i];
    pos[i] = i;
  }
  if (n == 1) {
    cout << "YES\n";
    return;
  }
  sort(p + 1, p + 1 + n);
  for (int i = 1; i < n; i++)
    if (p[i].first == p[i + 1].first) {
      cout << "YES\n";
      return;
    }
  for (int i = 1; i <= n - 2; i++) {
    if (a[i] == p[i]) continue;
    int u = pos[p[i].second], v = i + 1;
    if (v == u) v++;
    Swap(i, u);
    Swap(u, v);
  }
  if (a[n - 1].first <= a[n].first)
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) solve();
  return 0;
}
