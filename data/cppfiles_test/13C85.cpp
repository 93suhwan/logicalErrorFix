#include <bits/stdc++.h>
using namespace std;
const long long mod = (1e9) + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto x : s) {
      if (x == 'B')
        a++;
      else
        b++;
    }
    if (a == b)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
