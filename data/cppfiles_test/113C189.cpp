#include <bits/stdc++.h>
using namespace std;
istream& inp = cin;
template <typename T>
vector<T> readI(int size) {
  vector<T> result;
  for (int i = 0; i < size; ++i) {
    T x;
    inp >> x;
    result.push_back(x);
  }
  return result;
}
int64_t readI() {
  int64_t x;
  inp >> x;
  return x;
}
template <typename T>
T divup(T a, T b) {
  if (b < 0) {
    a = -a;
    b = -b;
  }
  if (a < 0) return -((-a) / b);
  if ((a % b) == 0)
    return a / b;
  else
    return 1 + a / b;
}
int32_t main() {
  assert(inp);
  inp.tie(NULL);
  const int n = readI();
  auto a = readI<int64_t>(n);
  sort(a.begin(), a.end());
  int64_t sum = 0;
  for (auto x : a) sum += x;
  const int m = readI();
  for (int t = 0; t < m; ++t) {
    int64_t x = readI();
    int64_t y = readI();
    auto it = upper_bound(a.begin(), a.end(), x);
    int64_t ans = x + y + 1;
    if (it != a.end()) {
      auto z{sum - *it};
      ans = min(ans, max(int64_t(0), y - z));
    }
    if (it != a.begin()) {
      --it;
      auto z{sum - *it};
      ans = min(ans, max(int64_t(0), y - z) + (x - *it));
    }
    cout << ans << "\n";
  }
  return 0;
}
