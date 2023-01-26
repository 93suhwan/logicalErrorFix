#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, i, flag = 0, d = 0, j, k, c = 0, l, a, b, ans = 0;
    char h;
    vector<long long> v;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> h;
      c = h - 48;
      if (c == 1) {
        ans = 1;
      } else if (c & 1 || c == 2) {
        v.push_back(c);
      } else {
        d = 1;
        l = c;
      }
    }
    if (ans == 1) {
      cout << ans << endl;
      cout << ans << endl;
    } else if (d == 1) {
      cout << 1 << endl;
      cout << l << endl;
    } else {
      if (v.size() == 2) {
        cout << 2 << endl;
        cout << v[0] << v[1] << endl;
      } else {
        for (i = 0; i < v.size() - 1; i++) {
          for (j = i + 1; j < v.size(); j++) {
            b = v[i] * 10 + v[j];
            for (k = 2; k < 10; k++) {
              if (b % k == 0) {
                flag = 1;
                cout << 2 << endl;
                cout << b << endl;
                break;
              }
            }
            if (flag) break;
          }
        }
      }
    }
  }
}
