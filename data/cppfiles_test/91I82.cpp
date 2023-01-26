#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int dp[100002];
int l[100002];
int solven2(int n, vector<int> as);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int testid = 0; testid < tests; testid++) {
    vector<int> as;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      as.push_back(k);
    }
    map<int, int> lvals;
    int sol = 0;
    for (int i = n - 1; i >= 0; i--) {
      map<int, int> newmap;
      for (auto rv : lvals) {
        int r = rv.first;
        int numSub = rv.second;
        int newOperationsFromr = INT_MAX;
        if (as[i] <= r) {
          newmap[as[i]] += numSub;
          newOperationsFromr = 0;
        } else {
          int lval = -1;
          newOperationsFromr = (as[i] - 1) / r;
          if (as[i] % r == 0)
            lval = r;
          else {
            lval = min(as[i] / (newOperationsFromr + 1), r - 1);
          }
          newmap[lval] += numSub;
        }
        long long tmp =
            (((i + 1) * numSub) % 998244353) * (newOperationsFromr % 998244353);
        tmp %= 998244353;
        sol += int(tmp);
        sol %= 998244353;
      }
      newmap[as[i]]++;
      lvals = newmap;
    }
    cout << sol << "\n";
  }
}
int solven2(int n, vector<int> as) {
  if (n == 1) {
    return 0;
  }
  long long res = 0;
  for (int i = 1; i < n; i++) {
    if (as[i - 1] <= as[i]) {
      dp[i - 1] = 0;
      l[i - 1] = as[i - 1];
    } else {
      dp[i - 1] = (as[i - 1] - 1) / as[i];
      int lval = -1;
      if (as[i - 1] % as[i] == 0)
        lval = as[i];
      else {
        lval = min(as[i - 1] / (dp[i - 1] + 1), as[i] - 1);
      }
      l[i - 1] = lval;
    }
    res += dp[i - 1];
    res = res % 998244353;
  }
  for (int i = 2; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      if (as[j] <= l[j + 1]) {
        dp[j] = dp[j + 1];
        l[j] = as[j];
      } else {
        int newDivs = (as[j] - 1) / l[j + 1];
        dp[j] = dp[j + 1] + newDivs;
        int lval = -1;
        if (as[j] % l[j + 1] == 0)
          lval = l[j + 1];
        else {
          lval = min(as[j] / (newDivs + 1), l[j + 1] - 1);
        }
        l[j] = lval;
      }
      res += dp[j];
      res = res % 998244353;
    }
  }
  return res;
}
