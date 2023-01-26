#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string s;
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  long long int odd = 0, even = 0;
  for (long long int i = 0; i < n; i++) {
    long long int a;
    cin >> a;
    if (a % 2 == 0) {
      even++;
      s[i] = '0';
    } else {
      odd++;
      s[i] = '1';
    }
  }
  long long int diff = abs(even - odd);
  if (diff > 1) {
    cout << "-1" << endl;
  } else {
    long long int cnt = 0;
    if (even > odd) {
      if (s[0] == '0')
        cnt = 0;
      else
        cnt = 1;
      for (long long int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) cnt++;
      }
    } else if (odd > even) {
      if (s[0] == 1)
        cnt = 0;
      else
        cnt = 1;
      for (long long int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) cnt++;
      }
    } else {
      cnt = 0;
      for (long long int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) cnt++;
      }
    }
    cout << cnt << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
