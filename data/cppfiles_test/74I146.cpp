#include <bits/stdc++.h>
std::vector<int> solve(int a[], int n) {
  static int len[1 << 15];
  len[0] = 0;
  for (int i = 0; i < (int)(1 << 15); ++i)
    if (i) len[i] = len[i ^ (i & -i)] + 1;
  int n0 = n >> 1, n1 = n - n0;
  std::map<int, std::pair<int, int> > map[30][30];
  for (int mask = 0; mask < (int)(1 << n0); ++mask) {
    int rest = ((1 << n0) - 1) ^ mask;
    for (int mask0 = rest;; mask0 = (mask0 - 1) & rest) {
      int sum = 0;
      for (int i = 0; i < (int)(n0); ++i)
        if (mask >> i & 1)
          sum += a[i];
        else if (mask0 >> i & 1)
          sum -= a[i];
      map[len[mask]][len[mask0]][sum] = {mask, mask0};
      if (!mask0) break;
    }
  }
  int MASK = -1, MASK0 = -1;
  for (int mask = 0; mask < (int)(1 << n1); ++mask) {
    int rest = ((1 << n1) - 1) ^ mask;
    for (int mask0 = rest;; mask0 = (mask0 - 1) & rest) {
      int sum = 0;
      for (int i = 0; i < (int)(n1); ++i)
        if (mask >> i & 1)
          sum += a[i + n0];
        else if (mask0 >> i & 1)
          sum -= a[i + n0];
      for (int x = std::max(1, std::max(len[mask], len[mask0])); x <= n; ++x) {
        if (map[x - len[mask]][x - len[mask0]].find(-sum) !=
            map[x - len[mask]][x - len[mask0]].end()) {
          MASK = mask << n0 | map[x - len[mask]][x - len[mask0]][-sum].first;
          MASK0 = mask0 << n0 | map[x - len[mask]][x - len[mask0]][-sum].second;
          goto FOUND;
        }
      }
      if (!mask0) break;
    }
  }
  return {};
FOUND : {}
  std::vector<int> e0, e1;
  for (int i = 0; i < (int)(n); ++i)
    if (MASK >> i & 1)
      e0.push_back(i);
    else if (MASK0 >> i & 1)
      e1.push_back(i);
  std::vector<int> e;
  for (int i = 0; i < (int)(e0.size()); ++i)
    e.push_back(e0[i]), e.push_back(e1[i]);
  std::vector<int> A;
  for (int i = 0; i < (int)(e.size()); ++i)
    if (i == 0)
      A.push_back(0);
    else
      A.push_back(a[e[i - 1]] - A.back());
  std::sort(e.begin(), e.end());
  for (int i = 0; i < (int)(n); ++i) {
    auto it = std::lower_bound(e.begin(), e.end(), i);
    if (it == e.end() || *it != i) A.push_back(a[i]);
  }
  return A;
}
const int mxn = 1005;
int n, a[mxn];
inline void fail() {
  puts("NO");
  exit(0);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", &a[i]);
  if (n == 2) {
    if (a[0] != a[1]) fail();
    puts("YES");
    printf("%d %d\n", 0, a[0]);
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < (int)(n); ++i)
    if (a[i] % 2 == 0) ++cnt;
  if (cnt) {
    std::vector<int> vec;
    for (int i = 0; i < (int)(n); ++i)
      if (a[i] % 2 == 0) vec.push_back(i);
    if ((int)vec.size() <= 2) {
      vec = {vec[0]};
      for (int i = 0; i < (int)(n); ++i)
        if (a[i] % 2 == 1) vec.push_back(i);
    }
    if ((int)vec.size() < 3) fail();
    std::sort(vec.begin(), vec.end());
    int sum = (a[vec[0]] + a[vec[1]] + a[vec[2]]) / 2;
    int x = sum - a[vec[1]];
    int y = sum - a[vec[2]];
    int z = sum - a[vec[0]];
    puts("YES");
    printf("%d %d %d", x, y, z);
    for (int i = 0; i < (int)(n); ++i) {
      auto it = std::lower_bound(vec.begin(), vec.end(), i);
      if (it == vec.end() || *it != i) printf(" %d", a[i] - x);
    }
    printf("\n");
    return 0;
  }
  auto vec = solve(a, std::min(n, 27));
  if (vec.empty()) fail();
  for (int i = std::min(n, 27); i < n; ++i) vec.push_back(a[i] - vec[0]);
  puts("YES");
  for (int i = 0; i < (int)(n); ++i) printf("%d ", vec[i]);
  puts("");
  return 0;
}
