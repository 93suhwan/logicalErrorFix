#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string a;
    cin >> a;
    a += "1";
    int ceros = 0;
    bool f = 1;
    for (char i : a) {
      if (i == '1')
        f = 1;
      else if (i == '0' && f) {
        ceros++;
        f = 0;
      }
    }
    cout << min(2, ceros) << "\n";
  }
  return 0;
}
