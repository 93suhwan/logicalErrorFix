#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const int INF = 1005000000;
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
int inverse(int a, int b) {
  for (int i = 0; i < b; i++) {
    if ((a * i) % b == 1) {
      return i;
    }
  }
}
int mul(int n) {
  if (n < 0)
    return -1;
  else
    return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int Q = ni();
  for (int q = 0; q < (Q); q++) {
    int N = ni();
    vector<int> nums(N);
    for (int i = 0; i < (N); i++) nums[i] = ni();
    vector<int> pref(N + 1);
    for (int i = 1; i <= N; i++) {
      pref[i] = pref[i - 1] + nums[i - 1];
    }
    int lo = 1;
    int hi = 450;
    while (lo < hi) {
      int K = (lo + hi + 1) / 2;
      if (K * (K + 1) / 2 > N) {
        hi = K - 1;
        continue;
      }
      vector<int> dp(N + 1);
      for (int j = K; j >= 1; j--) {
        vector<int> next(N + 1, INF);
        for (int i = j; i <= N; i++) {
          int cur = INF;
          if (pref[i] - pref[i - j] > dp[i - j]) cur = pref[i] - pref[i - j];
          next[i] = min(next[i - 1], cur);
        }
        dp = next;
      }
      if (dp[N] < INF)
        lo = K;
      else
        hi = K - 1;
    }
    cout << lo << '\n';
  }
}
