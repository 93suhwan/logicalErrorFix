#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, m, k;
void solve() {
  scanf("%d%d%d", &n, &m, &k);
  vector<int> st(n + 1, false);
  int b = n / m;
  if (n % m) b++;
  int p = b * (n % m);
  vector<vector<int>> res;
  vector<int> cur;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < p; j++) {
      cur.push_back((p * i + j) % n + 1);
      if (cur.size() == b) {
        res.push_back(cur);
        cur.clear();
      }
    }
    for (int j = 0, idx = p * (i + 1); j < n - p; j++, idx++) {
      cur.push_back(idx % n + 1);
      if (cur.size() == n / m) {
        res.push_back(cur);
        cur.clear();
      }
    }
  }
  for (auto it : res) {
    printf("%d ", (int)it.size());
    for (int i : it) printf("%d ", i);
    puts("");
  }
  puts("");
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
