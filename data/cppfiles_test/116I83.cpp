#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> c(n);
  vector<vector<int>> A(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    A[i].resize(c[i]);
    for (int j = 0; j < c[i]; j++) {
      cin >> A[i][j];
      A[i][j]--;
    }
  }
  vector<vector<int>> E1(k), E2(k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c[i] - 1; j++) {
      E1[A[i][j]].push_back(A[i][j + 1]);
      E2[A[i][j + 1]].push_back(A[i][j]);
    }
  }
  bool ok = true;
  for (int i = 0; i < k; i++) {
    sort(E1[i].begin(), E1[i].end());
    E1[i].erase(unique(E1[i].begin(), E1[i].end()), E1[i].end());
    sort(E2[i].begin(), E2[i].end());
    E2[i].erase(unique(E2[i].begin(), E2[i].end()), E2[i].end());
    if (E1[i].size() > 1 || E2[i].size() > 1) {
      ok = false;
    }
  }
  if (!ok) {
    cout << 0 << endl;
  } else {
    vector<bool> used(k, false);
    vector<int> S;
    for (int i = 0; i < k; i++) {
      if (!used[i] && E2[i].empty()) {
        used[i] = true;
        int v = i;
        int cnt = 1;
        while (true) {
          if (E1[v].empty()) {
            break;
          }
          int w = E1[v][0];
          used[w] = true;
          cnt++;
          v = w;
        }
        S.push_back(cnt);
      }
    }
    for (int i = 0; i < k; i++) {
      if (!used[i]) {
        ok = false;
      }
    }
    if (!ok) {
      cout << 0 << endl;
    } else {
      int cnt = S.size();
      map<int, int> mp;
      for (int i = 0; i < cnt; i++) {
        mp[S[i]]++;
      }
      int cnt2 = 0;
      vector<int> a, b;
      for (auto P : mp) {
        a.push_back(P.first);
        b.push_back(P.second);
        cnt2++;
      }
      vector<long long> dp(m + 1, 0);
      dp[0] = 1;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < cnt2; j++) {
          if (i + a[j] <= m) {
            dp[i + a[j]] += dp[i] * b[j];
            dp[i + a[j]] %= MOD;
          }
        }
      }
      cout << dp[m] << endl;
    }
  }
}
