#include <bits/stdc++.h>
using namespace std;
template <typename T>
using matrix = vector<vector<T>>;
const long long INFL = (1LL << 62) - 1;
const int INF = (1 << 30) - 1;
const double EPS = 1e-7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  matrix<int> go(n);
  vector<int> open(n), close(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    go[i].resize(s.size() + 1);
    int closect = 0, openct = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '(') {
        openct++;
      } else {
        if (openct)
          openct--;
        else
          closect++;
      }
      if (openct == 0) go[i][closect]++;
    }
    close[i] = closect;
    open[i] = openct;
  }
  int resp = 0;
  vector<int> dp(1 << n, -INF);
  dp[0] = 0;
  vector<int> state = {0};
  for (int i = 0; i < n; i++) {
    vector<int> newstate;
    for (int j = 0; j < n; j++) {
      for (int s : state) {
        if ((1 << j) & s) continue;
        int ns = s | (1 << j), total = 0;
        for (int k = 0; k < n; k++) {
          if ((1 << k) & s) total += open[k] - close[k];
        }
        if (total < 0) continue;
        if (close[j] > total) {
          resp = max(resp, dp[s] + go[j][total]);
        } else {
          dp[ns] =
              max(dp[ns], dp[s] + (total < go[j].size() ? go[j][total] : 0));
          newstate.push_back(ns);
        }
      }
    }
    sort(newstate.begin(), newstate.end());
    newstate.erase(unique(newstate.begin(), newstate.end()), newstate.end());
    state = newstate;
  }
  for (int i = 0; i < (1 << n); i++) resp = max(resp, dp[i]);
  cout << resp << '\n';
  return 0;
}
