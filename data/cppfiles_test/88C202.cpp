#include <bits/stdc++.h>
#pragma GCC optimize "O3"
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
  int32_t ntests;
  assert(inp);
  inp.tie(NULL);
  inp >> ntests;
  for (int test = 0; test < ntests; ++test) {
    const int n = readI();
    const int m = readI();
    auto a0 = readI<int>(n * m);
    vector<pair<int, int>> a;
    for (int i = 0; i < a0.size(); ++i) a.push_back({a0.at(i), i});
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.first < b.first || (a.first == b.first && a.second < b.second);
    });
    int64_t ans = 0;
    for (auto pit = a.begin(); pit != a.end(); ++pit) {
      auto p = *pit;
      auto it = lower_bound(
          a.begin(), a.end(), make_pair(p.first, 0),
          [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
      if (it == a.begin()) continue;
      --it;
      int worsepos = it - a.begin();
      int mypos = worsepos + (pit - it);
      int worsecol = worsepos % m;
      int myrow = mypos / m;
      if (myrow != (worsepos / m)) continue;
      ++it;
      for (int i = 0; i <= worsecol; ++i) {
        --it;
        if (it->second < p.second) ++ans;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
