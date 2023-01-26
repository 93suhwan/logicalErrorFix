#include <bits/stdc++.h>
using namespace std;
int q[500001];
int x[500001];
int y[500001];
int p[500001];
int r[500001];
int main() {
  int cnt;
  int r_cnt = 0;
  cin >> cnt;
  for (int i = 0; i < cnt; i++) {
    cin >> q[i] >> x[i];
    if (q[i] == 2) cin >> y[i];
  }
  for (int i = 0; i < 500001; i++) p[i] = i;
  for (int i = cnt - 1; i >= 0; i--) {
    if (q[i] == 1) {
      r[r_cnt++] = p[x[i]];
    } else {
      p[x[i]] = p[y[i]];
    }
  }
  for (int i = r_cnt - 1; i >= 0; i--) cout << r[i] << ' ';
  return 0;
}
