#include <bits/stdc++.h>
const long long MXN = 1e5 + 7;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
using namespace std;
int t;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    bool ok = 0;
    vector<int> v;
    while (b > 0) {
      if (b % 10 >= a % 10) {
        v.push_back((b % 10) - (a % 10));
        b /= 10;
        a /= 10;
      } else {
        if ((b % 100) - (a % 10) >= 10) {
          ok = 1;
          break;
        }
        v.push_back((b % 100) - (a % 10));
        b /= 100;
        a /= 10;
      }
      if (a > b) {
        ok = 1;
        break;
      }
    }
    if (ok == 1) {
      cout << -1 << '\n';
      continue;
    }
    int id = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
      if (v[i] != 0) {
        id = i;
        break;
      }
    }
    for (int i = id; i >= 0; i--) {
      cout << v[i];
    }
    cout << '\n';
  }
}
