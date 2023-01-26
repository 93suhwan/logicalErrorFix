#include <bits/stdc++.h>
using namespace std;
inline long long Qpow(long long a, long long b, long long mod) {
  long long s = 1;
  while (b) {
    if (b & 1) {
      s = (s * a) % mod;
    }
    a = a * a % mod;
    b >>= 1;
  }
  return s;
}
inline long long Qinv(long long a, long long mod) {
  return Qpow(a, mod - 2, mod);
}
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;
char s[100005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    int ans = 10000000;
    int num = 0;
    for (char i = 'a'; i <= 'z'; i++) {
      int l = 1, r = n;
      num = 0;
      while (l <= r) {
        if (s[l] == s[r]) {
          l++;
          r--;
        } else {
          if (s[r] == i) {
            r--;
            num++;
          } else if (s[l] == i) {
            l++;
            num++;
          } else {
            num = 10000000;
            break;
          }
        }
      }
      ans = min(ans, num);
    }
    if (ans > 100005)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
