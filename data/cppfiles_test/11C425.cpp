#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
int n, a[MAX_N][5], b[MAX_N];
bool cmp(int x, int y) { return x > y; }
int get(int p) {
  for (int i = 0; i < n; i++) {
    b[i] = a[i][p] * 2;
    for (int j = 0; j < 5; j++) b[i] -= a[i][j];
  }
  sort(b, b + n, cmp);
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += b[i];
    if (s <= 0) return i;
  }
  return n;
}
void solve() {
  int res = 0;
  for (int i = 0; i < 5; i++) {
    res = max(res, get(i));
  }
  printf("%d\n", res);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      fill(a[i], a[i] + 5, 0);
      for (auto c : s) a[i][c - 'a']++;
    }
    solve();
  }
  return 0;
}
