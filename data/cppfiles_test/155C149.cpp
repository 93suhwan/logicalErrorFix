#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int p[n], q[n];
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      q[i] = p[i];
    }
    int ct = 0;
    string s;
    cin >> s;
    int c0 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        ct++;
      else
        c0++;
    }
    if (ct == n || c0 == n) {
      for (auto i : p) cout << i << ' ';
      cout << endl;
      continue;
    }
    sort(q, q + n);
    set<int> st1, st2;
    int f = ct;
    ct = (n - ct);
    int i = 0;
    while (ct--) {
      st1.insert(q[i++]);
    }
    int j = i;
    while (j < n && f--) {
      st2.insert(q[j++]);
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        auto f = st1.lower_bound(p[i]);
        if (f != st1.end()) {
          cout << *f << ' ';
          st1.erase(f);
        } else {
          auto it = --st1.end();
          cout << *it << ' ';
          st1.erase(it);
        }
      } else {
        auto f = st2.lower_bound(p[i]);
        if (f != st2.end()) {
          cout << *f << ' ';
          st2.erase(f);
        } else {
          auto it = --st2.end();
          cout << *it << ' ';
          st1.erase(it);
        }
      }
    }
    cout << endl;
  }
  return 0;
}
