#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 99;
int n, m, p, t, cnt, a[N], b[N], c[N];
vector<int> v[N];
map<int, int> T;
long long ans;
int Fen[N];
void update(int x, int val) {
  while (x < N) {
    Fen[x] += val;
    x += (x & -x);
  }
}
int query(int x) {
  int res = 0;
  while (x > 0) {
    res += Fen[x];
    x -= (x & -x);
  }
  return res;
}
void Add(int x) {
  ans += query(cnt) - query(x);
  update(x, 1);
}
void make() {
  cnt = 1;
  sort(c, c + n + m);
  for (int i = 0; i < n + m; i++) {
    if (i == 0 || c[i] != c[i - 1]) {
      T[c[i]] = cnt++;
    }
  }
  for (int i = 1; i < n + 1; i++) a[i] = T[a[i]];
  for (int i = 1; i < n + 1; i++) b[i] = T[b[i]];
  sort(b + 1, b + 1 + m);
}
void solve(int L, int R, int l, int r) {
  if (R <= L) return;
  cout << L << " " << R << " " << l << " " << r << endl;
  int Mid = (L + R) / 2, x = b[Mid], ans = 0, mn = N, mid = 0;
  for (int i = l; i < r; i++) {
    if (a[i] < x) ans--;
    if (a[i] > x) ans++;
    if (ans < mn) {
      mn = ans, mid = i;
    }
  }
  v[mid].push_back(x);
  solve(L, Mid, l, mid + 1);
  solve(Mid + 1, R, mid, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    ans = p = 0;
    cin >> n >> m;
    for (int i = 1; i < n + 1; i++) {
      cin >> a[i];
      c[p++] = a[i];
    }
    for (int i = 1; i < m + 1; i++) {
      cin >> b[i];
      c[p++] = b[i];
    }
    make();
    solve(1, m + 1, 0, n + 1);
    for (int i = 0; i < n + 1; i++) {
      if (i) Add(a[i]);
      sort(v[i].begin(), v[i].end());
      for (int j = 0; j < v[i].size(); j++) {
        Add(v[i][j]);
      }
      v[i].clear();
    }
    cout << ans << endl;
    T.clear();
    fill(Fen, Fen + cnt + 9, 0);
  }
}
