#include <bits/stdc++.h>
using namespace std;
const int N = 200005, P = 1e9 + 7;
int n, q;
int a[N], l, r, d, inv2;
int s1[N], s2[N];
int qm(int x) { return x > P ? x - P : x; }
int pow_(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % P;
    b >>= 1;
    a = 1ll * a * a % P;
  }
  return ans;
}
int pwsum(int x) {
  return 1ll * x * (x + 1) % P * 1ll * (x * 2 + 1) % P * pow_(6, P - 2) % P;
}
int cal(int f, int d, int len) {
  long long ans = 1ll * f * f % P * len % P;
  ans = qm(ans + (1ll * d * d) % P * pwsum(len - 1) % P);
  ans = qm(ans + 1ll * len * (len - 1) % P * inv2 % P * f % P * d % P * 2 % P);
  return (int)ans;
}
int sum(int l, int r) {
  return s1[r] - s1[l - 1] < 0 ? s1[r] - s1[l - 1] + P : s1[r] - s1[l - 1];
}
int sum2(int l, int r) {
  return s2[r] - s2[l - 1] < 0 ? s2[r] - s2[l - 1] + P : s2[r] - s2[l - 1];
}
int main() {
  inv2 = pow_(2, P - 2);
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i] += 114514;
    s1[i] = qm(s1[i - 1] + a[i]);
    s2[i] = qm(s2[i - 1] + 1ll * a[i] * a[i] % P);
  }
  while (q--) {
    scanf("%d%d%d", &l, &r, &d);
    int len = (r - l + 1);
    long long f =
        (sum(l, r) - 1ll * (len - 1) * len % P * 1ll * inv2 % P * 1ll * d % P +
         P) %
        P;
    f = f * pow_(len, P - 2) % P;
    int s = cal(f, d, len);
    if (s == sum2(l, r)) {
      puts("Yes");
    } else
      puts("No");
  }
}
