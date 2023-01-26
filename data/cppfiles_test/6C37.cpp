#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
vector<int> p;
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
int a[100010], b[100010], c[100010], h[100010];
long long f[100010];
vector<int> m[100010], d[100010];
void calc(int x) {}
int main() {
  a[1] = 1;
  for (int i = 2; i <= 100000; i++) {
    if (a[i]) continue;
    p.push_back(i);
    for (int j = i + i; j <= 100000; j += i) {
      a[j] = 1;
      d[j].push_back(i);
    }
  }
  for (int i = 1; i <= 100000; i++) {
    h[i] = i;
  }
  for (int i = 1; i <= 100000; i++) {
    for (int j = i; j <= 100000; j += i) {
      m[j].push_back(i);
      if (!a[i]) h[j] = h[j] / i * (i - 1);
    }
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    vector<int> w;
    for (int j = i; j <= n; j += i) {
      for (int k = 0; k < m[b[j]].size(); k++) {
        int x = m[b[j]][k];
        if (!c[x]++) w.push_back(x);
      }
    }
    for (int j = 0; j < w.size(); j++) {
      int x = w[j];
      f[i] = (f[i] + 1ll * h[x] * c[x] * c[x]) % mod;
    }
    for (int j = 0; j < w.size(); j++) {
      c[w[j]] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans = (ans + f[i] * h[i]) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
