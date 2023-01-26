#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 5;
long long test, f[N], h[N], d[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i <= 9; i++)
    for (int j = 0; j < i; j++)
      if (i + j >= 10)
        f[(i + j) % 10] += 2;
      else
        h[i + j] += 2;
  for (int i = 0; i <= 9; i++)
    if (i + i >= 10)
      f[(i + i) % 10]++;
    else
      h[i + i]++;
  cin >> test;
  while (test--) {
    string str = "";
    cin >> str;
    long long n = str.size() - 1;
    reverse(str.begin(), str.end());
    d[0][0] = h[str[0] - '0'];
    d[0][1] = f[str[0] - '0'];
    if (str.size() > 1) {
      d[1][0] = h[str[1] - '0'];
      d[1][1] = f[str[1] - '0'];
    }
    for (int i = 2; i <= n; i++) {
      int pos = str[i] - '0';
      if (pos == 0) {
        d[i][0] = (h[pos] * d[i - 2][0]);
        d[i][1] = h[pos - 1 + 10] % 10 * d[i - 2][1] + f[pos] * d[i - 2][0];
      } else {
        d[i][0] = h[(pos - 1 + 10) % 10] * d[i - 2][1] + h[pos] * d[i - 2][0];
        d[i][1] = f[(pos - 1 + 10) % 10] * d[i - 2][1] + f[pos] * d[i - 2][0];
      }
    }
    long long res = d[n][0];
    if (n >= 1) res *= d[n - 1][0];
    cout << res - 2 << '\n';
  }
}
