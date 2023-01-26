#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, s;
    cin >> n >> s;
    if (n == 1) {
      cout << s << endl;
      continue;
    }
    int md = n / 2;
    if (n % 2 == 0) --md;
    cout << s / (n - md) << endl;
  }
  return 0;
}
