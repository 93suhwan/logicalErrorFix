#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const long long mod = 998244353;
long long POW(long long base, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = ans * base % mod;
    base = base * base % mod;
    p >>= 1;
  }
  return ans;
}
long long inv(long long num) { return POW(num, mod - 2); }
long long J[maxn];
long long C(int n, int m) { return J[n] * inv(J[m] * J[n - m] % mod) % mod; }
int D[maxn][2];
int n;
int main() {
  cin >> n;
  J[0] = 1;
  for (int i = 1; i <= 2 * n; ++i) J[i] = J[i - 1] * i % mod;
  int sum = 0;
  int haa = 0;
  int B = 0, W = 0;
  int aa = 0;
  int bw = 0, wb = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      char ch;
      cin >> ch;
      if (ch == '?') {
        D[i][j] = -1;
        ++sum;
      } else if (ch == 'B') {
        D[i][j] = 0;
        ++B;
      } else {
        D[i][j] = 1;
        ++W;
      }
    }
    if (D[i][0] == D[i][1] && D[i][0] != -1) haa = 1;
    if (D[i][0] == -1 && D[i][1] == -1) ++aa;
    if (D[i][0] != -1 && D[i][1] == -1)
      D[i][1] = 1 ^ D[i][0];
    else if (D[i][1] != -1 && D[i][0] == -1)
      D[i][0] = 1 ^ D[i][1];
    if (D[i][0] == 0 && D[i][1] == 1) bw = 1;
    if (D[i][0] == 1 && D[i][1] == 0) wb = 1;
  }
  if (sum == 0 || B > n || W > n) {
    cout << "0\n";
    return 0;
  }
  sum = C(sum, n - B);
  if (haa) {
    cout << sum << endl;
    return 0;
  }
  if (aa) sum = (sum - POW(2, aa) + wb + bw + mod) % mod;
  cout << sum << endl;
}
