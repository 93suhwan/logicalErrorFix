#include <bits/stdc++.h>
#pragma GCC optimize("O3", "Ofast", "no-stack-protector", "unroll-loops", \
                     "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
using namespace std;
const int MAXN = 1e5 + 100;
int A[MAXN];
const int MOD = 998244353;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
      A[i] = N - i + 1;
    }
    map<int, int> mp;
    int res = 0;
    for (int i = N; i >= 1; i--) {
      int sum = 0;
      while (mp.size()) {
        pair<int, int> pp = *(--mp.end());
        if (pp.first >= A[i]) {
          mp.erase(pp.first);
          sum += pp.second;
        } else {
          break;
        }
      }
      map<int, int> temp;
      for (auto x : mp) {
        if (A[i] % x.first == 0) {
          temp[x.first] += x.second;
          res += (long long)((long long)A[i] / (long long)x.first - 1) *
                 (long long)x.second % MOD * (long long)(i);
          res %= MOD;
        } else {
          temp[A[i] / (A[i] / x.first + 1)] += x.second;
          res += ((long long)A[i] / (long long)x.first) * (long long)x.second %
                 MOD * (long long)(i);
          res %= MOD;
        }
      }
      temp[A[i]] = sum + 1;
      mp = temp;
    }
    cout << res << '\n';
  }
  return 0;
}
