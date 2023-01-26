#include <bits/stdc++.h>
using namespace std;
set<int> s;
set<int> s2;
int main() {
  int ttt;
  cin >> ttt;
  while (ttt--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] = abs(a[i]);
    }
    sort(a, a + n);
    bool good = false;
    s.clear();
    s.insert(0);
    for (int i = 0; i < n; ++i) {
      s2.clear();
      for (auto it = s.begin(); it != s.end(); ++it) s2.insert((*it) + a[i]);
      for (auto it = s2.begin(); it != s2.end(); ++it) {
        if (s.find(*it) != s.end())
          good = true;
        else
          s.insert(*it);
      }
    }
    if (good)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
  return 0;
}
