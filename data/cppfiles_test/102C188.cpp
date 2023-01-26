#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq1, pq2;
long long mod = 1000000007;
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 != 0) res = (res * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, a, b;
  string s;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cin >> s;
    long long x = a;
    long long y = b;
    long long l = s.length();
    long long c1 = 0, c2 = 0;
    long long ans1 = x, ans2 = y;
    long long mn1 = 0, mx1 = 0;
    long long mn2 = 0, mx2 = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] == 'R')
        c1++;
      else if (s[i] == 'L')
        c1--;
      else if (s[i] == 'D')
        c2++;
      else {
        c2--;
      }
      mn1 = min(mn1, c1);
      mx1 = max(mx1, c1);
      if (abs(mn1) + abs(mx1) >= b) {
        break;
      }
      mn2 = min(mn2, c2);
      mx2 = max(mx2, c2);
      if (abs(mn2) + abs(mx2) >= a) {
        break;
      }
      ans2 = b - mx1;
      ans1 = a - mx2;
    }
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
