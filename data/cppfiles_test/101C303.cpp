#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, mx = 1e12;
    cin >> n;
    long long a[n + 2];
    string s;
    set<pair<long long, long long>> red, blue;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    char ch;
    for (long long i = 1; i <= n; i++) {
      cin >> ch;
      if (ch == 'R') {
        red.insert({-a[i], i});
      } else {
        blue.insert({a[i], i});
      }
    }
    red.insert({mx, mx});
    red.insert({-mx, mx});
    blue.insert({-mx, mx});
    blue.insert({mx, mx});
    bool flag = true;
    for (long long i = 1; i <= n; i++) {
      auto p1 = blue.upper_bound({i, 0});
      long long valu = p1->first;
      if (valu != mx) {
        blue.erase(blue.find({p1->first, p1->second}));
        continue;
      }
      auto p = red.lower_bound({-i, 0});
      long long val = abs(p->first);
      if (val != mx) {
        red.erase(red.find({p->first, p->second}));
        continue;
      }
      flag = false;
      break;
    }
    if (flag)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
