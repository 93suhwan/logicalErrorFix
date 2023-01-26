#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int N = 5001;
const int maxxor = (1 << 13);
int f[N][maxxor];
vector<int> a[N];
int cnp(int l, int r, int pos, int id) {
  if (l > r) return N * 2;
  int mid = (l + r) / 2;
  if (a[id][mid] > pos) return min(a[id][mid], cnp(l, mid - 1, pos, id));
  return cnp(mid + 1, r, pos, id);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[x].push_back(i);
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < maxxor; j++) f[i][j] = oo;
  f[0][0] = 0;
  int id;
  vector<int> res;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < maxxor; j++) {
      f[i][j] = f[i - 1][j];
      if (a[i].size() == 0) {
        if (i == N - 1 && f[i][j] != oo) res.push_back(j);
        continue;
      }
      int pos = f[i - 1][j ^ i];
      id = cnp(0, a[i].size() - 1, pos, i);
      if (id != N * 2) f[i][j] = min(f[i][j], id);
      if (i == N - 1 && f[i][j] != oo) res.push_back(j);
    }
  cout << res.size() << endl;
  for (int xnew : res) cout << xnew << " ";
  return 0;
}
