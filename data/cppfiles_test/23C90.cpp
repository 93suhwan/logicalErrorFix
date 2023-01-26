#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 4000;
int n, ntake;
int a[MAXN];
bool taken[MAXN];
long long cur[MAXN];
long long solve() {
  for (int i = (0); i < (n); ++i) taken[i] = false;
  for (int i = (0); i < (n); ++i) cur[i] = (long long)(ntake - 1) * a[i];
  long long ret = 0;
  for (int i = (0); i < (ntake); ++i) {
    int best = -1;
    for (int j = (0); j < (n); ++j)
      if (!taken[j] && (best == -1 || cur[j] > cur[best])) best = j;
    ret += cur[best];
    taken[best] = true;
    {
      int lo = a[best];
      for (int j = best - 1; j >= 0; --j) {
        lo = min(lo, a[j]);
        cur[j] -= (long long)2 * lo;
      }
    }
    {
      int lo = a[best];
      for (int j = best + 1; j < n; ++j) {
        lo = min(lo, a[j]);
        cur[j] -= (long long)2 * lo;
      }
    }
  }
  return ret;
}
void run() {
  scanf("%d%d", &n, &ntake);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  printf("%lld\n", solve());
}
int main() {
  run();
  return 0;
}
