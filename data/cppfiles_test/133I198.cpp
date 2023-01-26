#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  for (int cs = 1; cs <= tt; cs++) {
    string a[1005];
    long long n, m, i, j, k, l;
    string b;
    cin >> n;
    n -= 2;
    if (n == 1) {
      cin >> b;
      cout << 'a' << b << '\n';
    } else if (n == 2) {
      cin >> b;
      cout << b;
      cin >> b;
      cout << b << '\n';
    } else if (n == 3) {
      cin >> b;
      cout << b;
      cin >> b;
      cout << b[0];
      cin >> b;
      cout << b << '\n';
    } else {
      for (i = 0; i < n; i++) {
        cin >> b;
        if (i >= (n - 2))
          cout << b;
        else
          cout << b[0];
      }
      cout << '\n';
    }
  }
  return 0;
}
