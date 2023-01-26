#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using vi = vector<int>;
using vl = vector<ll>;
const int MOD = 1e9 + 7;
using pi = pair<int, int>;
void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)(name).size()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
int main() {
  setIO();
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int r[n][5];
    int u = 0;
    for (int i = (0); i < (n); ++i) {
      int better = 0;
      int cnt = 0;
      for (int j = (0); j < (5); ++j) {
        cin >> r[i][j];
        if (r[i][j] <= r[u][j]) better++;
      }
      if (better >= 3) u = i;
    }
    bool ok = true;
    for (int i = (0); i < (n); ++i) {
      if (i == u) continue;
      int best = 0;
      for (int j = (0); j < (5); ++j) {
        if (r[i][j] < r[u][j]) best++;
      }
      if (best >= 3) {
        ok = 0;
        break;
      }
    }
    if (ok)
      cout << u + 1 << '\n';
    else
      cout << "-1\n";
  }
  return 0;
}
