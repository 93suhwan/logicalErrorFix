#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int T, n, k;
long long inf = 1e18;
vector<int> v;
void _clear() { v.clear(); }
long long po(long long x, long long os) {
  if (os == 0) return 1;
  long long z = po(x, os / 2);
  if (os & 1) return z * z * x;
  return z * z;
}
long long calc(int k) {
  long long ret = 0;
  long long num = 0;
  for (int i = 0; i <= n - 2; i++) {
    long long moves = min(1LL * v[i + 1] / v[i] - 1, 1LL * k - num);
    ret += moves * v[i];
    num += moves;
  }
  ret += (k - num) * v.back();
  return ret;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    _clear();
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      v.push_back(po(10, x));
    }
    sort(v.begin(), v.end());
    printf("%lld\n", calc(k + 1));
  }
}
