#include <bits/stdc++.h>
using namespace std;
const int kMax = 1 << 13;
vector<int> g[kMax];
int r[kMax];
bitset<kMax> vis;
void TestCase() {
  int n;
  cin >> n;
  for (int x = 1; x < kMax; ++x) {
    g[x].emplace_back(0);
    r[x] = kMax;
  }
  vis[0] = true;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    for (int sxor : g[x]) {
      int new_xor = sxor ^ x;
      vis[new_xor] = true;
      while (x < r[new_xor]) {
        --r[new_xor];
        if (x < r[new_xor]) {
          g[r[new_xor]].emplace_back(new_xor);
        }
      }
    }
    g[x].clear();
  }
  cout << vis.count() << '\n';
  for (int x = 0; x < kMax; ++x) {
    if (vis[x]) {
      cout << x << ' ';
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests = 1;
  for (int tc = 1; tc <= tests; ++tc) {
    TestCase();
  }
  return 0;
}
