#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
bool mycomp(pair<long long int, long long int> p1,
            pair<long long int, long long int> p2) {
  if (p1.first == p2.first) {
    return p1.second > p2.second;
  } else {
    return p1.first < p2.first;
  }
}
long long int highestPowerof2(long long int x) {
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return x ^ (x >> 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int N = 4e5;
  long long int dp[N + 1];
  dp[0] = 0;
  for (int i = 1; i <= N; i++) {
    long long int x = i ^ (dp[i - 1]);
    dp[i] = x;
  }
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n == 0 || n == 1) {
      cout << 0 << endl;
      continue;
    }
    string s = to_string(n);
    string s1 = string(s.rbegin(), s.rend());
    long long int val = 1;
    long long int n1 = 0, n2 = 0;
    n = s1.size();
    for (int i = 0; i < n; i += 2) {
      long long int x = s1[i] - '0';
      n1 += (x * val);
      val *= 10;
    }
    val = 1;
    for (int i = 1; i < n; i += 2) {
      long long int x = s1[i] - '0';
      n2 += (x * val);
      val *= 10;
    }
    long long int ans1 = n1 + 1;
    long long int ans2 = n2 + 1;
    long long int ans = ans1 * ans2;
    cout << ans - 2 << endl;
  }
}
