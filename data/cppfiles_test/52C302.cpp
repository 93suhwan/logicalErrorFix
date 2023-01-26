#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 10;
const int mod = 1e9 + 7;
const int base = 3;
long long sum[maxn];
string f(long long k) {
  string x = "";
  while (k) {
    x += (k % 2) + '0';
    k >>= 1;
  }
  return x;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, k;
    scanf("%lld%lld", &n, &k);
    string tmp = f(k);
    long long ans = 0;
    long long tmpp = 1;
    for (auto ch : tmp) {
      if (ch == '1') ans += tmpp, ans %= mod;
      tmpp *= n;
      tmpp %= mod;
    }
    printf("%lld\n", ans);
  }
}
