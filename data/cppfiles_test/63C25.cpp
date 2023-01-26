#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const int M = 400005;
string s[N];
int n, minH[N], sum[N], f[1 << N], freq[N][M];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    int cur = 0;
    vector<pair<int, int>> vec;
    for (int j = 0; j < s[i].size(); ++j) {
      char c = s[i][j];
      if (c == '(')
        ++cur;
      else
        --cur;
      minH[i] = min(minH[i], cur);
      vec.emplace_back(cur, -j);
    }
    sum[i] = cur;
    sort(vec.begin(), vec.end());
    int bound = s[i].size();
    for (auto [val, pos] : vec) {
      pos = -pos, val = -val;
      if (pos < bound and val >= 0) ++freq[i][val];
      bound = min(bound, pos);
    }
  }
  for (int mask = (1 << n) - 1; mask >= 0; --mask) {
    int tot = 0;
    for (int i = 0; i < n; ++i)
      if (mask & 1 << i) tot += sum[i];
    if (tot < 0) continue;
    for (int i = 0; i < n; ++i)
      if (~mask & 1 << i) {
        int h = minH[i], cur = sum[i], here = 0;
        if (tot + h < 0) {
          f[mask] = max(f[mask], freq[i][tot]);
        } else {
          f[mask] = max(f[mask], freq[i][tot] + f[mask | 1 << i]);
        }
      }
  }
  cout << f[0] << '\n';
  return 0;
}
