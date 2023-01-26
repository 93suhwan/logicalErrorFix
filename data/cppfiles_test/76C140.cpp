#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
const int NMAX = 2e5 + 5;
long long dp[NMAX], sum[NMAX], m;
int n;
int main() {
  fast();
  cin >> n >> m;
  dp[1] = 1;
  sum[1] = 1;
  for (int i = 2; i <= n; i++) {
    vector<pair<int, int>> ans;
    vector<int> aux;
    int k = i;
    for (int j = 1; j * j <= k; j++) {
      aux.push_back(k / j);
    }
    int p = sqrt(k);
    if (p != aux.back()) {
      aux.push_back(p);
    }
    while (aux.back() > 1) {
      aux.push_back(aux.back() - 1);
    }
    reverse(aux.begin(), aux.end());
    for (int j = 0; j < (int)aux.size(); j++) {
      ans.push_back({aux[j], 0});
    }
    for (int j = 0; j < (int)ans.size() - 1; j++) {
      ans[j].second = ans[(int)ans.size() - 1 - j].first -
                      ans[(int)ans.size() - 2 - j].first;
    }
    ans[ans.size() - 1].second = 1;
    dp[i] = sum[i - 1];
    for (int j = 0; j < (int)ans.size() - 1; j++) {
      dp[i] = (dp[i] + 1LL * dp[ans[j].first] * ans[j].second) % m;
    }
    sum[i] = sum[i - 1] + dp[i];
    dp[i] %= m;
  }
  cout << dp[n];
  return 0;
}
