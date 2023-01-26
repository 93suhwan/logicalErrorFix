#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long const mod = 998244353;
long long const mod1 = 1013;
long long const MX = 2e6 + 100;
long long n, m, a[333][333], p[MX], c, id[MX];
long long tree[4000100];
void update(int i, int j, long long val, int k = 1, int l = 1, int r = n * m) {
  if (l > r || l > j || r < i) return;
  if (l >= i && r <= j) {
    tree[k] = val;
    return;
  }
  int mid = (l + r) / 2;
  update(i, j, val, k * 2, l, mid);
  update(i, j, val, k * 2 + 1, mid + 1, r);
  tree[k] = tree[k * 2] + tree[k * 2 + 1];
}
long long query(int i, int j, int k = 1, int l = 1, int r = n * m) {
  if (l > r || l > j || r < i) return 0;
  if (l >= i && r <= j) return tree[k];
  int mid = (l + r) / 2;
  return query(i, j, k * 2, l, mid) + query(i, j, k * 2 + 1, mid + 1, r);
}
int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long _t = 1;
  cin >> _t;
  while (_t--) {
    map<long long, long long> cmp;
    vector<long long> aa;
    c = 1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        aa.push_back(a[i][j]);
      }
    }
    sort(aa.begin(), aa.end());
    for (long long i : aa) {
      if (!cmp[i]) cmp[i] = c++;
      p[cmp[i]]++;
    }
    p[0] = 0;
    p[c] = 0;
    for (int i = c - 1; i >= 1; i--) p[i] += p[i + 1];
    long long ans = 0;
    for (int i = c - 1; i >= 1; i--) id[i] = m * n - p[i + 1];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        long long q = query(1, id[cmp[a[i][j]]]);
        ans += q;
        update(id[cmp[a[i][j]]], id[cmp[a[i][j]]], 1);
        id[cmp[a[i][j]]]--;
      }
    }
    cout << ans;
    cout << "\n";
    for (int i = 1; i < c; i++) p[i] = 0, id[i] = 0;
    for (int i = 1; i <= n * m; i++) update(i, i, 0);
  }
}
