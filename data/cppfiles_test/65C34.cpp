#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n, t, L, R, mn = N, a[N], b[N], w[N], type[N], ans[N];
long long SUM;
void solve(int l, int r, int x) {
  int cnt = r - l, mv = 0;
  if ((cnt & 1) == 0) cnt--, mv = 1;
  for (int i = R; i < R + cnt; i += 2) ans[l++] = i;
  for (int i = R + 1; i < R + cnt; i += 2) ans[l++] = i;
  R += cnt;
  if (mv) {
    ans[l++] = L--;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    w[i] = (c == 'R');
  }
  L = 0, R = 1;
  int i = 0;
  while (i < n) {
    int p = i;
    while (p < n && w[p] == w[i]) p++;
    solve(i, p, w[i]);
    i = p;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) mn = min(mn, ans[i]);
  for (int i = 0; i < n; i++) ans[i] -= mn;
  cout << endl;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      type[i] = w[i];
    } else {
      type[i] = type[0] ^ ((ans[i] - ans[0]) & 1);
    }
    cout << a[ans[i]] << " " << (type[i] == 0 ? 'L' : 'R') << endl;
  }
}
