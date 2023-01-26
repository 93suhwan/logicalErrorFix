#include <bits/stdc++.h>
using namespace std;
long long n, k;
int bi[20];
int ok(long long p) {
  int f[10] = {0}, op = 0;
  for (long long o = p; o; o /= 10) f[(int)(o % 10)] = 1;
  for (int i = 0; i < 10; i++) op += f[i];
  return op;
}
int f[20];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    int r = 0;
    if (ok(n) <= k) {
      cout << n << endl;
      continue;
    }
    for (int i = n; i; i /= 10) bi[r++] = i % 10;
    int sp = 0;
    for (long long i = n; i; i /= 10, sp++) {
      long long rr = i % 10, p = i / 10;
      int ss = -1;
      for (int j = rr + 1; j < 10; j++)
        if (ok(p * 10 + j) <= k) {
          ss = j;
          break;
        }
      if (ss > -1) {
        long long io = p * 10 + ss;
        memset(f, 0, sizeof(f));
        int sq = -1;
        for (int j = sp + 1; j < r; j++) f[bi[j]] = 1;
        if (sq == -1) sq = ss;
        for (int j = 0; j < 10; j++)
          if (f[j]) {
            sq = j;
            break;
          }
        if (ok(io) < k) sq = 0;
        for (int j = 0; j < sp; j++) io = io * 10 + sq;
        cout << io << endl;
        break;
      }
    }
  }
}
