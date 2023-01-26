#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
const int maxn = 200010, mod = 998244353;
int i, j, k, n, m, T, w[11];
long long ksm(long long sum, int num) {
  long long ans = 1;
  while (num) {
    if (num & 1) ans = ans * sum % mod;
    sum = sum * sum % mod;
    num >>= 1;
  }
  return ans;
}
long long ans = 0, jc[maxn];
string Ss;
int main() {
  cin >> n;
  int X = 0, Y = 0, S = 0;
  for (i = 1; i <= n; i++) {
    cin >> Ss;
    if (Ss == "??") w[0]++, S += 2;
    if (Ss == "W?") w[1]++, X++, S++;
    if (Ss == "B?") w[2]++, Y++, S++;
    if (Ss == "?W") w[3]++, X++, S++;
    if (Ss == "?B") w[4]++, Y++, S++;
    if (Ss == "WB") w[5]++;
    if (Ss == "BW") w[6]++;
    if (Ss == "BB") w[7]++, Y += 2;
    if (Ss == "WW") w[8]++, X += 2;
  }
  jc[0] = 1;
  for (i = 1; i < maxn; i++) jc[i] = jc[i - 1] * i % mod;
  long long sum = jc[S] * ksm(jc[(X + Y + S) / 2 - X], mod - 2) % mod *
                  ksm(jc[S - ((X + Y + S) / 2 - X)], mod - 2) % mod;
  if (!(w[7] + w[8])) {
    sum -= ksm(2, w[0]);
    sum += mod;
    sum %= mod;
    if (!w[5] && !w[1] && !w[4]) sum++;
    if (!w[6] && !w[2] && !w[3]) sum++;
    sum %= mod;
  }
  cout << sum << endl;
  return 0;
}
