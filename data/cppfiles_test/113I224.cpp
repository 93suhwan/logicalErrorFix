#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    ll n, p, h, k;
    cin >> n >> p >> h >> k;
    string num = to_string(n);
    string num2 = to_string(h);
    if (num.size() + p > num2.size() + k) {
      cout << ">\n";
    } else if (num.size() + p < num2.size() + k) {
      cout << "<\n";
    } else {
      bool f = 1;
      for (int i = 0; i < min(num.size(), num2.size()); i++) {
        if ((num[i] - '0') > ((num2[i] - '0'))) {
          cout << ">\n";
          f = 0;
          break;
        } else if ((num[i] - '0') < ((num2[i] - '0'))) {
          cout << "<\n";
          f = 0;
          break;
        }
      }
      if (f) cout << "=\n";
    }
  }
  return 0;
}
