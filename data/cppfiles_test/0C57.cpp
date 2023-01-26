#include <bits/stdc++.h>
using namespace std;
struct sp {
  string s1;
  int id;
};
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  sp s[n];
  for (int k = 0; k < n; k++) {
    string x = "";
    for (int i = 0; i < m; i++) {
      char c;
      cin >> c;
      if (i % 2 == 1) {
        x += (char)('Z' + 'A' - c);
      } else {
        x += c;
      }
    }
    s[k] = {x, k + 1};
  }
  sort(s, s + n, [](sp x, sp y) { return x.s1 < y.s1; });
  for (int p = 0; p < n; p++) cout << s[p].id << " ";
  cout << "\n";
  return 0;
}
