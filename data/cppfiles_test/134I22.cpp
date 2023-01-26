#include <bits/stdc++.h>
using namespace std;
long long p1[150], p2[150];
long long m_gcd(long long a, long long b) {
  return b == 0 ? a : m_gcd(b, a % b);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
      if (i & 1)
        cin >> p1[cnt1++];
      else
        cin >> p2[cnt2++];
    }
    int mgcd1 = p1[0];
    for (int i = 0; i < cnt1; i++) mgcd1 = m_gcd(mgcd1, p1[i]);
    int flag = 1;
    for (int i = 0; i < cnt2; i++)
      if (p2[i] % mgcd1 == 0) {
        flag = 0;
        break;
      }
    if (flag)
      cout << mgcd1 << '\n';
    else {
      int mgcd2 = p2[0];
      for (int i = 0; i < cnt2; i++) mgcd2 = m_gcd(mgcd2, p2[i]);
      flag = 1;
      for (int i = 0; i < cnt1; i++)
        if (p1[i] % mgcd2 == 0) {
          flag = 0;
          break;
        }
      if (flag)
        cout << mgcd2 << '\n';
      else
        cout << 0 << '\n';
    }
  }
  return 0;
}
