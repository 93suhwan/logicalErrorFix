#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<array<int, 6>> cost(n + 1);
  int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i - 1] != (char)('a' + ((i + 2) % 3))) a++;
    if (s[i - 1] != (char)('a' + ((i) % 3))) b++;
    if (s[i - 1] != (char)('a' + ((i + 1) % 3))) c++;
    if (s[i - 1] != (char)('a' + ((4 - i) % 3))) d++;
    if (s[i - 1] != (char)('a' + ((5 - i) % 3))) e++;
    if (s[i - 1] != (char)('a' + ((6 - i) % 3))) f++;
    cost[i][0] = a;
    cost[i][1] = b;
    cost[i][2] = c;
    cost[i][3] = d;
    cost[i][4] = e;
    cost[i][5] = f;
  }
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 0 << "\n";
      continue;
    }
    --l;
    int mi = INT_MAX;
    for (int i = 0; i < 6; ++i) {
      mi = min(mi, cost[r][i] - cost[l][i]);
    }
    cout << mi << "\n";
  }
}
