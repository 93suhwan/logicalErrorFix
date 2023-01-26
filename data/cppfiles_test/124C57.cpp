#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
const int A = 2010;
long long d[2 * A][A];
long long s[2 * A][A];
int main() {
  int ta;
  scanf("%d", &ta);
  char c[A];
  for (int ifa = 0; ifa < ta; ifa++) {
    int n;
    scanf("%d\n", &n);
    scanf("%s", c);
    string a(c);
    scanf("%s", c);
    string b(c);
    for (int j = 0; j < 2 * n + 1; j++)
      for (int i = 0; i < n + 1; i++) d[j][i] = 0;
    for (int j = 0; j < 2 * n + 1; j++)
      for (int i = 0; i < n + 1; i++) s[j][i] = 0;
    d[n][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < 2 * n + 1; k++) {
        d[k][i] %= mod;
        s[k][i] %= mod;
        for (int as = 0; as < 2; as++)
          for (int bs = 0; bs < 2; bs++) {
            if (a[i] != '?' && a[i] - '0' != as) continue;
            if (b[i] != '?' && b[i] - '0' != bs) continue;
            int dif = k - n + as - bs;
            if (abs(dif) > n) continue;
            d[n - dif][i + 1] += d[k][i];
            s[n - dif][i + 1] += s[k][i];
            s[n - dif][i + 1] += d[k][i] * abs(dif);
          }
      }
    }
    printf("%lld\n", s[n][n] % mod);
  }
}
