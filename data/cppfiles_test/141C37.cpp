#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
p:
  while (t--) {
    long long a;
    cin >> a;
    long long s;
    cin >> s;
    vector<long long> v;
    while (s > 0) {
      if (a % 10 > s % 10) {
        if (s % 100 > a % 10) {
          if ((s % 100 - a % 10) < 10)
            v.push_back(s % 100 - a % 10);
          else {
            cout << -1;
            cout << "\n";
            goto p;
          }
          s = s / 100;
          a = a / 10;
        } else {
          cout << -1;
          cout << "\n";
          goto p;
        }
      } else {
        v.push_back(s % 10 - a % 10);
        s = s / 10;
        a = a / 10;
      }
      if (a > s) {
        cout << -1 << "\n";
        goto p;
      }
    }
    long long kk = 0;
    for (long long i = v.size() - 1; i >= 0; i--) {
      if (v[i] > 0) {
        kk = i;
        break;
      }
    }
    for (long long i = kk; i >= 0; i--) {
      cout << v[i];
    }
    cout << "\n";
  }
  return 0;
}
