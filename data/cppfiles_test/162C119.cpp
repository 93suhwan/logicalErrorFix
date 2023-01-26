#include <bits/stdc++.h>
using namespace std;
int dadsadasda;
const int INF = 0x3f3f3f3f;
const long long LLINF = 1e18;
const int MAXN = 2e5 + 69;
int N;
long long H[MAXN];
long long h[MAXN];
long long e[MAXN];
bool valid(int k) {
  for (int i = 0; i < N; i++) h[i] = H[i];
  for (int i = 0; i < N; i++) e[i] = 0;
  for (int i = N - 1; i >= 2; --i) {
    long long have = h[i] + e[i];
    if (have < k) return false;
    long long give = min(h[i], have - k) / 3;
    e[i - 2] += 2 * give;
    e[i - 1] += give;
  }
  return min(h[0] + e[0], h[1] + e[1]) >= k;
}
void solve() {
  dadsadasda = scanf("%d", &N);
  for (int i = 0; i < N; i++) dadsadasda = scanf("%lld", &H[i]);
  int lo = 1, hi = 1e9;
  while (lo < hi) {
    int mi = lo + (hi - lo + 1) / 2;
    if (valid(mi))
      lo = mi;
    else
      hi = mi - 1;
  }
  printf("%d\n", lo);
}
int main() {
  int t;
  dadsadasda = scanf("%d", &t);
  while (t--) solve();
  return 0;
}
