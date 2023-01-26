#include <bits/stdc++.h>
using namespace std;
const int H = 400;
int re[H + 5][505], x[200100], y[200100], add[200100], a[200100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int i, j, N, M;
  cin >> N >> M;
  for (i = 1; i <= N; i++) cin >> x[i] >> y[i];
  int now = 0;
  for (i = 1; i <= M; i++) {
    int op, k, zz = 0;
    cin >> op >> k;
    if (op == 1) {
      if (x[k] + y[k] >= H) {
        zz = 3;
        for (j = i + x[k]; j <= N; j += (x[k] + y[k])) add[j]++;
      } else {
        zz = 1;
        re[x[k] + y[k]][(i + x[k]) % (x[k] + y[k])]++;
      }
      a[k] = i;
    } else {
      if (x[k] + y[k] >= H) {
        zz = 4;
        for (j = a[k] + x[k]; j <= N; j += (x[k] + y[k])) add[j]--;
      } else {
        zz = 2;
        re[x[k] + y[k]][(a[k] + x[k]) % (x[k] + y[k])]--;
      }
    }
    now += add[i];
    for (j = 2; j < H; j++) {
      now += re[j][i % j];
    }
    if (zz == 1) re[x[k] + y[k]][(i) % (x[k] + y[k])]--;
    if (zz == 2) re[x[k] + y[k]][(a[k]) % (x[k] + y[k])]++;
    if (zz == 3)
      for (j = i + (x[k] + y[k]); j <= N; j += (x[k] + y[k])) add[j]--;
    if (zz == 4)
      for (j = a[k] + (x[k] + y[k]); j <= N; j += (x[k] + y[k])) add[j]++;
    cout << now << "\n";
  }
}
