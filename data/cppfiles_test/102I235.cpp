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
    long long lft1 = 1, lft2 = b;
    long long rgt1 = 1, rgt2 = a;
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
      if (c1 < 0) {
        lft1 = max(lft1, abs(c1));
      } else {
        lft2 = min(lft2, b - c1);
      }
      if (lft2 < lft1) {
        break;
      }
      if (c2 < 0) {
        rgt1 = max(rgt1, abs(c2));
      } else {
        rgt2 = min(rgt2, a - c2);
      }
      if (rgt2 < rgt1) break;
      ans1 = rgt2;
      ans2 = lft2;
    }
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
