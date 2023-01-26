#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long n = s.size();
    long long one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        zero++;
      else
        one++;
    }
    long long ans = 0;
    if (one == n && zero == 0)
      ans = 0;
    else if (one == 0 && zero == n)
      ans = 1;
    else {
      long long n_zero = 0, m_zero = 0;
      for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '0')
          n_zero++;
        else if (n_zero != 0) {
          m_zero = max(n_zero + 1, m_zero);
          n_zero = 0;
        }
      }
      long long temp = 2;
      ans = min(temp, zero);
      if (m_zero == n - one) ans = 1;
    }
    cout << ans << "\n";
  }
}
