#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 10 != 3 && n % 3 != 0) {
      cout << n << endl;
      continue;
    } else {
      while (true) {
        if (n % 10 != 3 && n % 3 != 0) {
          cout << n << endl;
          break;
        } else
          n++;
      }
    }
  }
  return 0;
}
