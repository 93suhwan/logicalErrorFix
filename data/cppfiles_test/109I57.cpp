#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n - 2; i++) {
      if (s[i] != '0') {
        a += (s[i] - '0');
        b++;
      }
    }
    if (s[n - 1] != '0') {
      a += (s[n - 1] - '0');
      if (s[n - 2] != '0') {
        b += (s[n - 2] - '0') + 1;
      }
    } else {
      if (s[n - 2] != '0') {
        b += (s[n - 2] - '0') + 1;
      }
    }
    cout << a + b << "\n";
  }
  return 0;
}
