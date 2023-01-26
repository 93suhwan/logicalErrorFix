#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
p:
  while (t--) {
    int a;
    cin >> a;
    int s;
    cin >> s;
    vector<int> v;
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
      if (s > 0 && a == 0) {
        v.push_back(s);
        s = s / 10;
      }
    }
    if (a > 0 && s == 0) {
      cout << -1;
      cout << "\n";
      goto p;
    }
    int kk = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
      if (v[i] > 0) {
        kk = i;
        break;
      }
    }
    for (int i = kk; i >= 0; i--) {
      cout << v[i];
    }
    cout << "\n";
  }
  return 0;
}
