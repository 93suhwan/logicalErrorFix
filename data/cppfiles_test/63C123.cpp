#include <bits/stdc++.h>
using namespace std;
long long int mul(long long int a, long long int b) {
  return ((a % int(1e9 + 7)) * (b % int(1e9 + 7))) % int(1e9 + 7);
}
long long int add(long long int a, long long int b) {
  return ((a % int(1e9 + 7)) + (b % int(1e9 + 7))) % int(1e9 + 7);
}
long long int sub(long long int a, long long int b) {
  long long int ans = ((a % int(1e9 + 7)) - (b % int(1e9 + 7))) % int(1e9 + 7);
  ans %= int(1e9 + 7);
  ans = (ans + int(1e9 + 7)) % int(1e9 + 7);
  return ans;
}
long long int mpow(long long int a, long long int b) {
  long long int ans = 1;
  long long int po = a;
  while (b != 0) {
    if (b % 2) {
      ans = ((ans % int(1e9 + 7)) * (po % int(1e9 + 7))) % int(1e9 + 7);
    }
    po = ((po % int(1e9 + 7)) * (po % int(1e9 + 7))) % int(1e9 + 7);
    b /= 2;
  }
  return ans;
}
class UnionFind {
 public:
  long long int *par, *siz;
  UnionFind(long long int n) {
    par = new long long int[n + 1];
    siz = new long long int[n + 1];
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      siz[i] = 1;
    }
  }
  long long int find(long long int x) {
    if (x != par[x]) {
      par[x] = find(par[x]);
    }
    return par[x];
  }
  void merge(long long int x, long long int y) {
    x = find(x), y = find(y);
    if (x != y) {
      if (siz[x] < siz[y]) swap(x, y);
      siz[x] += siz[y];
      par[y] = x;
    }
  }
};
void solve() {
  long long int n, m1, m2;
  cin >> n >> m1 >> m2;
  UnionFind uf1(n), uf2(n);
  for (long long int i = 0; i < m1; i++) {
    long long int a, b;
    cin >> a >> b;
    uf1.merge(a, b);
  }
  for (long long int i = 0; i < m2; i++) {
    long long int a, b;
    cin >> a >> b;
    uf2.merge(a, b);
  }
  vector<pair<long long int, long long int> > res;
  long long int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (uf1.find(i) != uf1.find(j) and uf2.find(i) != uf2.find(j)) {
        ans++;
        res.push_back({i, j});
        uf1.merge(i, j);
        uf2.merge(i, j);
      }
    }
  }
  cout << ans << '\n';
  for (auto it : res) {
    cout << it.first << ' ' << it.second << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  solve();
}
