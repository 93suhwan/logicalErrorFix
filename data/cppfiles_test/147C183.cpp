#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int cnt = 0;
    for (auto u : s)
      if (u == 'N') cnt++;
    (cnt != 1) ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}
