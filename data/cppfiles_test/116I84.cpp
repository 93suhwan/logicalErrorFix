#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, k, dp[300001], nxt[300000], prv[300000];
vector<int> arr[300000];
vector<pair<int, int>> trns;
map<int, int> chns;
bool bad = false;
int mul(int x, int y) { return ((long long)x * y) % mod; }
int main() {
  cin >> n >> m >> k;
  memset(nxt, -1, sizeof(nxt));
  memset(prv, -1, sizeof(prv));
  for (int i = 0, sz; i < n; i++) {
    cin >> sz;
    arr[i].resize(sz);
    for (int j = 0; j < sz; j++) {
      cin >> arr[i][j];
    }
    for (int j = 0; j < sz - 1; j++) {
      if (prv[arr[i][j + 1] - 1] != -1 &&
          prv[arr[i][j + 1] - 1] != arr[i][j] - 1) {
        bad = true;
      }
      if (nxt[arr[i][j] - 1] != -1 && prv[arr[i][j] - 1] != arr[i][j + 1] - 1) {
        bad = true;
      }
      prv[arr[i][j + 1] - 1] = arr[i][j] - 1;
      nxt[arr[i][j] - 1] = arr[i][j + 1] - 1;
    }
  }
  if (bad) {
    cout << 0 << endl;
  } else {
    for (int i = 0; i < k; i++) {
      if (prv[i] == -1) {
        int chn = 1, cur = i;
        while (nxt[cur] != -1) {
          cur = nxt[cur];
          ++chn;
        }
        ++chns[chn];
      }
    }
    for (auto it : chns) {
      trns.push_back(it);
    }
    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
      for (auto j : trns) {
        if (i >= j.first) {
          dp[i] = (dp[i] + mul(dp[i - j.first], j.second)) % mod;
        }
      }
    }
    cout << dp[m] << endl;
  }
}
