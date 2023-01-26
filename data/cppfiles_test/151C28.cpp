#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int fa[500010];
vector<pair<int, pair<int, int>>> q;
stack<int> out;
void solve() {
  for (int i = 0; i < 500010; i++) fa[i] = i;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 1) {
      cin >> y;
      q.push_back({1, {y, 0}});
    } else {
      cin >> x >> y;
      q.push_back({2, {x, y}});
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (q[i].first == 1)
      out.push(fa[q[i].second.first]);
    else
      fa[q[i].second.first] = fa[q[i].second.second];
  }
  while (!out.empty()) {
    cout << out.top() << " ";
    out.pop();
  }
  cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  solve();
  return 0;
}
