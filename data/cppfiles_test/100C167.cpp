#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
long long shu[200010];
long long fact[200010];
long long infact[200010];
long long qmi(long long a, long long b) {
  long long ans = 1;
  long long base = a;
  while (b) {
    if (b & 1) ans = base * ans % p;
    base = base * base % p;
    b >>= 1;
  }
  return ans;
}
long long ni(long long a) { return qmi(a, p - 2); }
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int T;
  cin >> T;
  fact[0] = 1;
  infact[0] = 1;
  for (int i = 1; i <= 200005; i++) {
    fact[i] = fact[i - 1] * i % p;
  }
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> shu[i];
    sort(shu, shu + n);
    int t = shu[n - 1] - shu[n - 2];
    if (t == 1) {
      long long s = count(shu, shu + n, shu[n - 2]);
      s++;
      infact[s] = ni(fact[s]);
      long long tt = ((fact[s] - fact[s - 1]) % p + p) % p;
      printf("%lld\n", fact[n] * tt % p * infact[s] % p);
    }
    if (t >= 2) printf("0\n");
    if (t == 0) printf("%lld\n", fact[n]);
  }
}
