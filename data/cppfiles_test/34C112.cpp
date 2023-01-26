#include <bits/stdc++.h>
using namespace std;
template <class T>
bool cmn(T& a, T b) {
  return b < a ? a = b, true : false;
}
template <class T>
bool cmx(T& a, T b) {
  return a < b ? a = b, true : false;
}
const int N = 1e6 + 10, C = 1 << 13;
int dp[C][C];
int min_pref[C];
int a[N];
vector<int> pos[C];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  for (int i = 0; i < C; i++) {
    min_pref[i] = n;
    for (int j = 0; j < C; j++) {
      dp[i][j] = n;
    }
  }
  dp[0][0] = -1;
  min_pref[0] = -1;
  for (int x = 1; x <= 5000; x++) {
    for (int x0r = 0; x0r < C; x0r++) {
      int y = x0r ^ x;
      int mn_pref = min_pref[y];
      auto it = upper_bound((pos[x]).begin(), (pos[x]).end(), mn_pref);
      if (it != pos[x].end()) {
        dp[x][x0r] = *it;
      }
      cmn(min_pref[x0r], dp[x][x0r]);
    }
  }
  vector<int> ans;
  for (int x0r = 0; x0r < C; x0r++) {
    bool ok = false;
    for (int i = 0; i <= 5005; i++) {
      if (dp[i][x0r] != n) {
        ok = true;
        break;
      }
    }
    if (ok) ans.push_back(x0r);
  }
  cout << (int)(ans).size() << '\n';
  for (int i : ans) cout << i << ' ';
  return 0;
}
