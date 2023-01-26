#include <bits/stdc++.h>
using namespace std;
long long deg(long long a, long long b, long long m) {
  if (b == 0)
    return 1;
  else if (b == 1)
    return a % m;
  else {
    long long b0 = b >> 1;
    long long b1 = b - 2 * b0;
    long long t = deg(a, b0, m);
    return ((t * t) % m * deg(a, b1, m)) % m;
  }
}
vector<vector<long long>> bin(501, vector<long long>(501, 0));
int main() {
  int n, x;
  cin >> n >> x;
  int m = 998244353;
  bin[0][0] = 1;
  for (int i = 1; i < 501; i++) {
    bin[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];
      bin[i][j] %= m;
    }
  }
  vector<vector<long long>> matr(n + 1, vector<long long>(x + 1, 0));
  matr[0][0]++;
  for (int j = 1; j < x + 1; j++) {
    for (int i = 2; i < n + 1; i++) {
      if (j > i - 1)
        for (int i0 = 0; i0 <= i; i0++) {
          matr[i][j] += matr[i0][j - (i - 1)] * deg(i - 1, i - i0, m) % m *
                        bin[i][i - i0] % m;
        }
      else
        matr[i][j] = (deg(j, i, m) - deg(j - 1, i, m) + m) % m;
    }
  }
  long long ans = 0;
  for (int j = 1; j < x + 1; j++) {
    ans += matr[n][j];
    ans %= m;
  }
  cout << ans;
}
