#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-12;
const int INF = 1e9 + 10;
template <typename T>
using MinPQ = priority_queue<T, vector<T>, greater<T>>;
int n;
vector<int> a;
void Solve() {
  scanf("%d", &n);
  a.resize(n + 1);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int ans = 0;
  deque<int> f;
  f.push_back(0);
  for (int i = 1; i <= n; ++i) {
    int j = i - a[i];
    int pre = (j >= 0) ? f[j] : -1;
    f.push_front(0);
    if (j >= 0) {
      f[j] = pre + 1;
      ans = max(ans, f[j]);
    }
  }
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; ++i) {
    Solve();
  }
  return 0;
}
