#include <bits/stdc++.h>
long long solve() {
  long long w, h, k, max_bases[4], temp, max = 0;
  std::cin >> w >> h;
  for (int i = 0; i < 4; i++) {
    std::cin >> k;
    std::cin >> max_bases[i];
    for (int j = 0; j < k - 1; j++) std::cin >> temp;
    max_bases[i] -= temp;
    max_bases[i] *= -1;
  }
  for (int i = 0; i < 4; i++) {
    if (i < 2) max = ((max_bases[i] * h) > max) ? max_bases[i] * h : max;
    if (i >= 2) max = ((max_bases[i] * w) > max) ? max_bases[i] * w : max;
  }
  return max;
}
int main() {
  int t;
  long long ans;
  std::cin >> t;
  while (t--) {
    ans = solve();
    std::cout << ans << '\n';
  }
  return 0;
}
