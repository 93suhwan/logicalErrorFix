#include <bits/stdc++.h>
template <typename T>
bool chkmin(T &a, T b) {
  return (b < a) ? a = b, 1 : 0;
}
template <typename T>
bool chkmax(T &a, T b) {
  return (b > a) ? a = b, 1 : 0;
}
long long ksm(long long a, long long b) {
  if (b == 0) return 1;
  long long ns = ksm(a, b >> 1);
  ns = ns * ns % 1000000007;
  if (b & 1) ns = ns * a % 1000000007;
  return ns;
}
using namespace std;
const int maxn = 1005;
int x[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  long long ans = 0;
  for (int i = 1; i <= n; i += 2) {
    long long sum = 0, lb = 0;
    for (int j = i + 1; j <= n; j++) {
      if (j % 2 == 0) {
        long long dif = -sum;
        long long l = -lb;
        l = std::max(l, 1ll);
        l = std::max(l, 1 + dif);
        long long r = x[i];
        r = std::min(r, x[j] + dif);
        if (r >= l) ans += r - l + 1;
      }
      if (j % 2)
        sum += x[j];
      else
        sum -= x[j];
      lb = std::min(lb, sum);
    }
  }
  cout << ans << endl;
  return (0 - 0);
}
