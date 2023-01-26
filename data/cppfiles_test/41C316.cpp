#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<vector<long long>> cost(n + 1, vector<long long>(6));
  for (int i = n - 1; i >= 0; i--) {
    cost[i][0] = (s[i] == 'a' ? 0 : 1) + cost[i + 1][3];
    cost[i][1] = (s[i] == 'a' ? 0 : 1) + cost[i + 1][5];
    cost[i][2] = (s[i] == 'b' ? 0 : 1) + cost[i + 1][1];
    cost[i][3] = (s[i] == 'b' ? 0 : 1) + cost[i + 1][4];
    cost[i][4] = (s[i] == 'c' ? 0 : 1) + cost[i + 1][0];
    cost[i][5] = (s[i] == 'c' ? 0 : 1) + cost[i + 1][2];
  }
  while (m--) {
    long long l, r;
    cin >> l >> r;
    l--, r--;
    long long d = (r + 1 - l) % 3;
    long long res = n;
    res = min(res, cost[l][0] - (d == 0   ? cost[r + 1][0]
                                 : d == 1 ? cost[r + 1][3]
                                          : cost[r + 1][4]));
    res = min(res, cost[l][1] - (d == 0   ? cost[r + 1][1]
                                 : d == 1 ? cost[r + 1][5]
                                          : cost[r + 1][2]));
    res = min(res, cost[l][2] - (d == 0   ? cost[r + 1][2]
                                 : d == 1 ? cost[r + 1][1]
                                          : cost[r + 1][5]));
    res = min(res, cost[l][3] - (d == 0   ? cost[r + 1][3]
                                 : d == 1 ? cost[r + 1][4]
                                          : cost[r + 1][0]));
    res = min(res, cost[l][4] - (d == 0   ? cost[r + 1][4]
                                 : d == 1 ? cost[r + 1][0]
                                          : cost[r + 1][3]));
    res = min(res, cost[l][5] - (d == 0   ? cost[r + 1][5]
                                 : d == 1 ? cost[r + 1][2]
                                          : cost[r + 1][1]));
    cout << res << endl;
  }
  return 0;
}
