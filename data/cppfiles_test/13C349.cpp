#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (auto& c : s) {
      x += (c == 'B');
      y += (c == 'A' || c == 'C');
    }
    cout << (x == y ? "YES\n" : "NO\n");
  }
}
