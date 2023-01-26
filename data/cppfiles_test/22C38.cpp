#include <bits/stdc++.h>
using namespace std;
int n, m, op, k, ans;
int x[200001];
int y[200001];
int ps[200001];
int last_a[200001];
int cnt_a[450][450];
void block_modify(int tm, int k, int v) {
  int z = x[k] + y[k];
  int l = (tm + x[k]) % z, r = (tm - 1);
  if (r < 0) {
    r += z;
  }
  r %= z;
  if (l <= r)
    for (int i = l; i <= r; i++) cnt_a[z][i] += v;
  else {
    for (int i = 0; i <= r; i++) cnt_a[z][i] += v;
    for (int i = l; i < z; i++) cnt_a[z][i] += v;
  }
}
int block_query(int tm) {
  int res = 0;
  for (int i = 2; i < 450; i++) {
    res += cnt_a[i][tm % i];
  }
  return res;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  int sqrm = sqrt(m);
  ans = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &op, &k);
    k--;
    if (x[k] + y[k] > sqrm) {
      if (op == 1) {
        for (int j = i + x[k]; j <= m; j += x[k] + y[k]) {
          ps[j] += 1;
          if (j + y[k] <= m) {
            ps[j + y[k]] -= 1;
          }
        }
        last_a[k] = i;
      } else {
        for (int j = last_a[k] + x[k]; j <= m; j += x[k] + y[k]) {
          ps[j] -= 1;
          if (j + y[k] <= m) {
            ps[j + y[k]] += 1;
          }
          if (j < i && j + y[k] >= i) ans--;
        }
      }
    } else {
      if (op == 1) {
        block_modify(i, k, 1);
        last_a[k] = i;
      } else {
        block_modify(last_a[k], k, -1);
      }
    }
    ans += ps[i];
    std::printf("%d\n", ans + block_query(i));
  }
}
