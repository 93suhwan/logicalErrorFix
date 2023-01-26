#include <bits/stdc++.h>
using namespace std;
long long intersect_len(pair<long long, long long> A,
                        pair<long long, long long> B) {
  const auto &[la, ra] = A;
  const auto &[lb, rb] = B;
  if (ra < lb || rb < la) {
    return 0;
  }
  return min(ra, rb) - max(la, lb) + 1;
}
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> c(n + 1);
  for (int i = 0; i < (int)(n); i++) {
    cin >> c[i + 1];
  }
  long long res = 0;
  for (int l = 1; l <= n; l += 2) {
    long long mn = 0, tot = 0;
    for (int r = l + 1; r <= n; r += 2) {
      if (c[l] >= -mn) {
        res += intersect_len({max(1ll, -mn), c[l]}, {1 - tot, c[r] - tot});
      }
      tot -= c[r];
      mn = min(mn, tot);
      if (r + 1 <= n) {
        tot += c[r + 1];
      }
    }
  }
  cout << res << "\n";
  return 0;
}
