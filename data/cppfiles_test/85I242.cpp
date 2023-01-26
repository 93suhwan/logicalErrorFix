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
      long long temp = 2;
      ans = min(temp, zero);
    }
    cout << ans << "\n";
  }
}
