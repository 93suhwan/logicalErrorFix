#include <bits/stdc++.h>
using namespace std;
vector<int> L[2000010];
int a[2000010], b[2000010], v[2000010], aib[2000010], w[2000010],
    sp_left[2000010], sp_right[2000010], poz[2000010];
int t, n, m, i, j, el;
void solve(int st, int dr, int x, int y) {
  if (st > dr) return;
  int mid = (st + dr) >> 1;
  sp_left[x - 1] = sp_right[y + 1] = 0;
  for (int i = x; i <= y; i++) sp_left[i] = sp_left[i - 1] + (a[i] > b[mid]);
  for (int i = y; i >= x; i--) sp_right[i] = sp_right[i + 1] + (a[i] < b[mid]);
  int mini = 2000000000;
  for (int i = x; i <= y; i++) {
    if (sp_left[i - 1] + sp_right[i] < mini) {
      mini = sp_left[i - 1] + sp_right[i];
      poz[mid] = i;
    }
  }
  solve(st, mid - 1, x, poz[mid]);
  solve(mid + 1, dr, poz[mid], y);
}
void update(int p, int val) {
  for (; p <= el; p += (p & -p)) aib[p] += val;
}
int query(int p) {
  int sol = 0;
  for (; p; p -= (p & -p)) sol += aib[p];
  return sol;
}
int cautare_binara(int v[], int n, int val) {
  int st = 1, dr = n;
  while (st <= dr) {
    int mid = (st + dr) >> 1;
    if (v[mid] == val) return mid;
    if (v[mid] < val)
      st = mid + 1;
    else
      dr = mid - 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> t;
  for (; t--;) {
    cin >> n >> m;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + m + 1);
    solve(1, m, 1, n + 1);
    for (i = 1; i <= n + 1; i++) L[i].clear();
    for (i = 1; i <= m; i++) L[poz[i]].push_back(i);
    int k = 0;
    for (i = 1; i <= n + 1; i++) {
      for (auto it : L[i]) v[++k] = b[it];
      if (i <= n) v[++k] = a[i];
    }
    el = 0;
    for (i = 1; i <= k; i++) w[++el] = v[i];
    sort(w + 1, w + el + 1);
    int el2 = 1;
    for (i = 2; i <= el; i++)
      if (w[i] != w[i - 1]) w[++el2] = w[i];
    el = el2;
    for (i = 1; i <= k; i++) v[i] = cautare_binara(w, el, v[i]);
    for (i = 1; i <= el; i++) aib[i] = 0;
    long long sol = 0;
    for (i = 1; i <= k; i++) {
      sol += query(el) - query(v[i]);
      update(v[i], 1);
    }
    cout << sol << "\n";
  }
  return 0;
}
