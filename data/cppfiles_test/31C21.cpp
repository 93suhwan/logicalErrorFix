#include <bits/stdc++.h>
int main() {
  unsigned short k;
  unsigned long n;
  std::vector<long> f, minv, maxv;
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> k;
  minv.assign(1UL << k, 1L << k);
  maxv.assign(1UL << k, -1L << k);
  while (n--) {
    unsigned long a;
    std::cin >> a;
    minv[a] = 0;
    maxv[a] = 0;
  }
  f.assign(1UL << k, 1L << k);
  for (unsigned short i = 0; i < k; ++i) {
    for (unsigned long x = 0; x < (1UL << k); ++x) {
      if (x & (1UL << i)) continue;
      const unsigned long y = x | (1UL << i);
      f[x] = std::min(f[x], f[y]);
      f[y] = f[x];
      f[x] = std::min(f[x], minv[y] + (1L << i) - maxv[x]);
      f[y] = std::min(f[y], minv[x] + (1L << i) - maxv[y]);
      const auto minvx = minv[x], maxvx = maxv[x], minvy = minv[y],
                 maxvy = maxv[y];
      minv[x] = std::min(minvx, minvy + (1L << i));
      minv[y] = std::min(minvy, minvx + (1L << i));
      maxv[x] = std::max(maxvx, maxvy + (1L << i));
      maxv[y] = std::max(maxvy, maxvx + (1L << i));
    }
  }
  for (unsigned long i = 0; i < (1UL << k); ++i) {
    if (i) std::cout.put(' ');
    std::cout << f[i];
  }
  std::cout.put('\n');
  return 0;
}
