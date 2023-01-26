#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 6010;
const int INF = 100000000;
int f[MAXN][4][4][4];
int x[MAXN], y[MAXN];
int Gcd(int a, int b) {
  while (b != 0) {
    int t = a % b;
    a = b;
    b = t;
  }
  return a;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int dx = x[j] - x[i], dy = y[j] - y[i];
      int len = Gcd(abs(dx), abs(dy));
      ++f[i][(dx + INF) % 4][(dy + INF) % 4][len % 4];
    }
  }
  LL odd = 0, even = 0;
  for (int s = 0; s < n; ++s) {
    for (int a = 0; a < 4; ++a) {
      for (int b = 0; b < 4; ++b) {
        for (int c = a; c < 4; ++c) {
          for (int d = 0; d < 4; ++d) {
            if (c == a && d < b) continue;
            if (a == c && b == d) {
              for (int p = 0; p < 4; ++p) {
                for (int q = p; q < 4; ++q) {
                  if ((p + q) & 1) continue;
                  int m4 = (p + q) % 4;
                  int area = abs(a * d - c * b) % 4;
                  if (area != m4) continue;
                  LL add = 0;
                  if (p == q) {
                    add = f[s][a][b][p] * (f[s][a][b][p] - 1) / 2;
                  } else {
                    add = f[s][a][b][p] * f[s][a][b][q];
                  }
                  if (p & 1) {
                    odd += add;
                  } else {
                    even += add;
                  }
                }
              }
            } else if ((a - c) % 2 == 0 && (b - d) % 2 == 0) {
              for (int p = 0; p < 4; ++p) {
                for (int q = 0; q < 4; ++q) {
                  if ((p + q) & 1) continue;
                  int m4 = (p + q + 2) % 4;
                  int area = abs(a * d - c * b) % 4;
                  if (area != m4) continue;
                  LL add = f[s][a][b][p] * f[s][c][d][q];
                  if (p & 1) {
                    odd += add;
                  } else {
                    even += add;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << odd + even / 3 << endl;
  return 0;
}
