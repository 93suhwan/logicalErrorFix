#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b, long long int mod) {
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b = b / 2;
  }
  return ans;
}
bool isprime(long long int n) {
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  for (int p = 1; p <= t; p++) {
    long long int n, q, count1 = 0, count2 = 0;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<long long int> dp(n + 1);
    long long int ans = 0;
    for (long long int i = 1; i <= n; i++) {
      if (s[i - 1] == '+') {
        if (i % 2)
          ans++;
        else
          ans--;
      } else {
        if (i % 2)
          ans--;
        else
          ans++;
      }
      dp[i] = ans;
    }
    while (q--) {
      long long int a, b;
      cin >> a >> b;
      if ((b - a + 1) % 2 == 1) {
        cout << 1 << endl;
      } else if (dp[a - 1] == dp[b]) {
        cout << 0 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }
}
