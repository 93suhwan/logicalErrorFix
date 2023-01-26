#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main() {
  int t, n;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    string s, t;
    if (n & 1) {
      if (n == 1)
        cout << "a" << '\n';
      else {
        s = string(n / 2, 'a') + "bc" + string(n / 2 - 1, 'a');
        cout << s << '\n';
      }
    } else {
      s = string(n / 2, 'a') + "b" + string(n / 2 - 1, 'a');
      cout << s << '\n';
    }
  }
}
