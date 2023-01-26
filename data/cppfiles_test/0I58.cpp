#include <bits/stdc++.h>
using namespace std;
void sxseven();
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sxseven();
  return 0;
}
const int N = 1e6 + 5;
int m, k;
string s[N];
int a[N];
bool cmp0(int x, int y) { return s[x][k] < s[y][k]; }
bool cmp1(int x, int y) { return s[x][k] > s[y][k]; }
void js(int l, int r, int op, int kk) {
  if (l >= r) return;
  k = kk;
  if (op == 0) {
    sort(a + l, a + r + 1, cmp0);
  } else {
    sort(a + l, a + r + 1, cmp1);
  }
  if (kk == m - 1) return;
  int cnt = 1;
  for (int i = l + 1; i <= r; ++i) {
    if (s[a[i]][kk] == s[a[i - 1]][kk]) {
      cnt++;
    } else {
      if (cnt > 1) {
        js(i - cnt, i - 1, 1 - op, kk + 1);
      }
      cnt = 1;
    }
  }
}
void sxseven() {
  int n;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    a[i] = i;
  }
  js(1, n, 0, 0);
  for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
}
