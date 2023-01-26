#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    int mx = (b - a) * 2;
    if (a > mx || b > mx || c > mx)
      cout << "-1\n";
    else {
      if (c > mx / 2)
        cout << c - mx / 2 << "\n";
      else
        cout << c + mx / 2 << "\n";
    }
  }
  return 0;
}
