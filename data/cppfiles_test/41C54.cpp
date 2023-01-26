#include <bits/stdc++.h>
using namespace std;
const int Max = 1e3 + 1;
void nos() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int n, k;
int a[Max][Max];
int mcolor;
void read() { cin >> n >> k; }
void paint(int left, int right, int color) {
  if (left >= right) return;
  mcolor = max(color, mcolor);
  int len = right - left + 1;
  int split = len / k;
  int lenplus = len % k;
  vector<pair<int, int> > splits;
  int start = left;
  int i;
  for (i = 1; i <= lenplus; i++)
    splits.push_back({start, start + split}), start += split + 1;
  for (; i <= k; i++)
    splits.push_back({start, start + split - 1}), start += split;
  for (auto imp : splits) {
    for (int k = imp.first; k <= imp.second; k++)
      for (int j = imp.second + 1; j <= right; j++) a[k][j] = color;
    paint(imp.first, imp.second, color + 1);
  }
}
void solve() {
  paint(1, n, 1);
  int i, j;
  cout << mcolor << '\n';
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) cout << a[i][j] << ' ';
}
void restart() {}
int32_t main() {
  nos();
  read();
  solve();
  restart();
  return 0;
}
