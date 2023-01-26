#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, maxn = 3e5 + 10, maxd = 20, inf = 1e18 + 5;
void Solve() {
  int n;
  cin >> n;
  vector<int> a(n), b;
  for (int i = (0); i < n; i++) {
    cin >> a[i];
  }
  b = a;
  sort(a.begin(), a.end());
  vector<pair<int, int> > p;
  for (int i = (n - 1); i >= 0; i--) {
    int id;
    for (int j = (i); j >= 0; j--) {
      if (a[i] == b[j]) id = j;
    }
    if (i == id) continue;
    p.push_back({id + 1, i + 1});
    int lst = b[id];
    for (int j = (i); j >= id; j--) {
      int k = b[j];
      b[j] = lst;
      lst = k;
    }
  }
  cout << (int)(p).size() << '\n';
  for (pair<int, int> c : p)
    cout << c.first << ' ' << c.second << ' ' << 1 << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t-- > 0) Solve();
  return 0;
}
