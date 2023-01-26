#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int test_case = 1, i, j, m, e, r, a, b, ss, d, dd, k, l, t, A, B;
  cin >> test_case;
  while (test_case--) {
    cin >> a >> b;
    e = a + b;
    if (e % 2)
      cout << "-1";
    else {
      if (e == 0) cout << "0";
      if (a == b)
        cout << "1";
      else
        cout << "2";
    }
    cout << "\n";
    ;
  }
  return 0;
}
