#include <bits/stdc++.h>
using namespace std;
int T, N, a[200001], b[200001], c[200001], ans[200001];
vector<pair<pair<int, int>, int>> val[2000001];
int get() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int main() {
  T = get();
  while (T--) {
    N = get();
    for (int i = 1; i <= N; i++)
      a[i] = get(), b[i] = get(), c[i] = get(),
      val[a[i] + b[i] - c[i]].push_back({{a[i], b[i]}, i});
    int cnt = 0;
    for (int i = 1; i <= N; i++)
      if (!val[a[i] + b[i] - c[i]].empty()) {
        auto tmp = val[a[i] + b[i] - c[i]];
        val[a[i] + b[i] - c[i]].clear();
        vector<pair<pair<int, int>, int>> seg;
        for (auto j : tmp)
          seg.push_back({{min(j.first.first, c[j.second]) - j.first.first,
                          max(c[j.second] - j.first.second, 0) - j.first.first},
                         j.second});
        sort(seg.begin(), seg.end());
        int pre = -1e9;
        for (auto j : seg) {
          if (j.first.second > pre) pre = j.first.first, cnt++;
          ans[j.second] = pre + a[j.second];
        }
      }
    cout << cnt << '\n';
    for (int i = 1; i <= N; i++) cout << ans[i] << ' ' << c[i] - ans[i] << '\n';
  }
  return 0;
}
