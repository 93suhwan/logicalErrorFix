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
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != '0') {
        a += (s[i] - '0') + 1;
      }
    }
    a += (s[n - 1] - '0');
    cout << a << "\n";
  }
  return 0;
}
