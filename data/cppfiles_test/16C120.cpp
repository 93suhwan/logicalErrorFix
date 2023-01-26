#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e6 + 5;
int a[N], b[N];
char s[N];
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    priority_queue<pair<int, int>> q;
    for (int i = 1, x; i <= n; ++i) {
      scanf("%d", &x);
      if (x > 0) q.push({x, i});
    }
    vector<pair<int, int>> ret;
    while (q.size() > 1) {
      auto a = q.top();
      q.pop();
      auto b = q.top();
      q.pop();
      if (a.first > 1) q.push({a.first - 1, a.second});
      if (b.first > 1) q.push({b.first - 1, b.second});
      ret.push_back({a.second, b.second});
    }
    printf("%d\n", (int)ret.size());
    for (auto pr : ret) printf("%d %d\n", pr.first, pr.second);
  }
}
