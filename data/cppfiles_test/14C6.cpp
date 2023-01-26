#include <bits/stdc++.h>
using namespace std;
void err() { cout << endl; }
template <class T, class... Ts>
void err(const T &arg, const Ts &...args) {
  cout << arg << " ";
  err(args...);
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
const int maxn = 1e6 + 40;
pair<int, int> a[maxn], tmp[maxn];
struct node {
  int l, r, d;
  node(int l = 0, int r = 0, int d = 0) : l(l), r(r), d(d) {}
};
void run() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].first, a[i].second = i;
  for (int i = 1; i <= n; ++i) tmp[i] = a[i];
  sort(tmp + 1, tmp + 1 + n);
  for (int i = 1; i <= n; ++i) a[tmp[i].second].second = i;
  vector<node> v;
  for (int i = 1; i <= n; ++i) {
    if (a[i].second != i) {
      for (int j = i + 1; j <= n; ++j)
        if (a[j].second == i) {
          v.push_back({i, n, j - i});
          for (int k = i; k < j; ++k) tmp[k - i + 1] = a[k];
          for (int k = j; k <= n; ++k) a[k - j + i] = a[k];
          for (int k = n - j + i + 1; k <= n; ++k) a[k] = tmp[k - n - i + j];
          break;
        }
    }
  }
  cout << v.size() << '\n';
  for (auto it : v) cout << it.l << ' ' << it.r << ' ' << it.d << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) run();
  return 0;
}
