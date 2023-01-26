#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if (a % 2 == 0) {
      if (b % 4 == 0)
        cout << a << endl;
      else {
        long long int x = a - 1 - 4 * (b / 4);
        if (b % 4 == 1)
          cout << x << endl;
        else if (b % 4 == 2)
          cout << x + b << endl;
        else
          cout << x + 2 * b - 1 << endl;
      }
    } else {
      if (b % 4 == 0)
        cout << a << endl;
      else {
        long long int x = a + 1 + 4 * (b / 4);
        if (b % 4 == 1)
          cout << x << endl;
        else if (b % 4 == 2)
          cout << x - b << endl;
        else
          cout << x - 2 * b + 1 << endl;
      }
    }
  }
}
