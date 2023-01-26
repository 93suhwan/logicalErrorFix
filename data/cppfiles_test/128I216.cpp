#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_case;
  cin >> test_case;
  while (test_case--) {
    int number, a, b, c;
    cin >> number;
    if (number / 2 == 0) {
      a = 2;
      b = number - 3;
      c = 1;
    } else {
      a = 3;
      b = number - 4;
      c = 1;
    }
    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}
