#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    int x = n / 2 - 1;
    for (int i = 0; i < x; i++) s += 'a';
    s += 'b';
    for (int i = 0; i < x + 1; i++) s += 'a';
    if (n % 2 == 1) s += 'c';
    cout << s << "\n";
  }
  return 0;
}
