#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, a[N], b[N];
vector<int> fs[N];
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    if (fs[i].size()) continue;
    for (int j = i; j <= n; j += i) {
      int k = j;
      while (k % i == 0) fs[j].push_back(i), k /= i;
    }
  }
  for (int i = 2; i <= n; i += 2) {
    for (auto x : fs[i]) a[x] ^= 1;
    b[i] ^= 1;
  }
  for (int i = 1; i <= n; ++i)
    if (a[i]) b[i] ^= 1;
  vector<int> res;
  if (!b[2]) res.push_back(1);
  for (int i = 2; i <= n; ++i) {
    if (b[i] && !b[i - 1]) res.push_back(i - 1);
    if (b[i] && !b[i + 1]) res.push_back(i);
  }
  cout << res.size() << '\n';
  for (auto x : res) cout << x << ' ';
  cout << '\n';
}
