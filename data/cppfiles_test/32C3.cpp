#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const long long INF = 1e18;
const long long MOD = 1000000007LL;
int ni() {
  int x;
  cin >> x;
  return x;
}
long long nl() {
  long long x;
  cin >> x;
  return x;
}
double nd() {
  double x;
  cin >> x;
  return x;
}
string next() {
  string x;
  cin >> x;
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int Q = ni();
  for (int q = 0; q < (Q); q++) {
    int N = ni();
    vector<long long> nums(N);
    for (int i = 0; i < (N); i++) nums[i] = nl();
    vector<long long> pref(N + 1);
    for (int i = 1; i <= N; i++) {
      pref[i] = pref[i - 1] + nums[i - 1];
    }
    vector<long long> dp(N + 1, INF);
    int ans = 0;
    for (int k = 1; k < 450; k++) {
      vector<long long> next(N + 1);
      for (int i = N - k; i >= 0; i--) {
        long long cur = 0;
        if (pref[i + k] - pref[i] < dp[i + k]) {
          cur = pref[i + k] - pref[i];
        }
        next[i] = max(next[i + 1], cur);
      }
      if (next[0] == 0) break;
      dp = next;
      ans = k;
    }
    cout << ans << '\n';
  }
}
