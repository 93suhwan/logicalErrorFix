#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int N, K, ans;
void divide(int st, int dr, int col) {
  if (st == dr) return;
  ans = max(ans, col);
  int new_sz = (dr - st + 1) / K;
  if ((dr - st + 1) % K != 0) new_sz++;
  for (int i = st; i <= dr; i += new_sz) {
    for (int j = i; j < min(i + new_sz, dr + 1); j++)
      for (int it = i + new_sz; it <= dr; it++) a[j][it] = col;
    divide(i, min(i + new_sz - 1, dr), col + 1);
  }
}
int main() {
  int ct = 1;
  cin >> N >> K;
  divide(1, N, ct);
  cout << ans << '\n';
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++) cout << a[i][j] << " ";
  return 0;
}
