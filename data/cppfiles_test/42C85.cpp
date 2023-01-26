#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void modadd(int &a, int x) { a = a + x >= mod ? a + x - mod : a + x; }
struct fenwick_tree {
  int n;
  vector<int> f;
  fenwick_tree(int n = 0) : n(n), f(n + 1) {}
  void changeValue(int i, int d) {
    for (i++; i <= n; i += i & -i) modadd(f[i], d);
  }
  int getSum(int i) {
    int s = 0;
    for (i++; i; i -= i & -i) modadd(s, f[i]);
    return s;
  }
};
int n, t, a[200100], b[200100], s[200100], e[400100];
bool r[200100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  for (int i = 0; i < 2 * n; i++) e[i] = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i], a[i]--, b[i]--;
    e[a[i]] = i;
  }
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> s[i], s[i]--;
    r[s[i]] = true;
  }
  int res = 0;
  fenwick_tree f(2 * n + 1);
  int cl = -1;
  for (int j = 2 * n - 1; j >= 0; j--) {
    if (e[j] == -1) continue;
    int i = e[j];
    int v = f.getSum(b[i]);
    modadd(v, 1);
    if (b[i] <= cl || r[i]) modadd(res, v), cl = max(cl, b[i]);
    f.changeValue(b[i] + 1, v);
  }
  cout << res << "\n";
}
