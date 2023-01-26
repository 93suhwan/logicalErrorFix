#include <bits/stdc++.h>
using namespace std;
template <class Num>
Num mabs(Num x) {
  if (x < 0) return -x;
  return x;
}
struct Fenwick {
  vector<int> tree;
  int N;
  Fenwick(int _n) {
    N = _n;
    tree.resize(N + 5, 0);
  }
  void upd(int node, int val) {
    for (int i = node; i < N; i += i & -i) {
      tree[i] += val;
    }
  }
  int get(int node) {
    int ret = 0;
    if (node <= 0) return 0;
    for (int i = node; i > 0; i -= i & -i) ret += tree[i];
    return ret;
  }
};
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = (0); i < (n); i++) {
    cin >> a[i];
  }
  auto b = a;
  sort(b.begin(), b.end());
  auto it = unique(b.begin(), b.end());
  b.resize(distance(b.begin(), it));
  map<int, int> mapa;
  for (int i = 0; i < n; i++) {
    mapa[b[i]] = i + 1;
  }
  Fenwick pref(n + 5);
  long long ans = 0ll;
  for (int i = 0; i < n; i++) {
    int cur = mapa[a[i]];
    int poc = pref.get(cur - 1);
    int kraj = pref.get(n + 2) - pref.get(cur);
    if (poc <= kraj)
      ans += (long long)poc;
    else
      ans += (long long)kraj;
    pref.upd(cur, 1);
  }
  cout << ans << "\n";
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
