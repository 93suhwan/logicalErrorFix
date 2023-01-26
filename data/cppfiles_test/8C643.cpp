#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int test;
  cin >> test;
  while (test--) {
    cin >> n;
    int c2_1 = (n / 3);
    int c1_1 = ceil((double)n - (2 * c2_1));
    int abs_1 = abs(c2_1 - c1_1);
    int c1_2 = c2_1;
    int c2_2 = ceil((double)(n - c1_2) / 2);
    int abs_2 = abs(c2_2 - c1_2);
    if (abs_1 >= abs_2) {
      if ((c1_2 + 2 * c2_2) != n)
        cout << c2_2 << " " << c1_2 << endl;
      else
        cout << c1_2 << " " << c2_2 << endl;
    } else {
      if ((c1_1 + 2 * c2_1) != n)
        cout << c2_1 << " " << c1_1 << endl;
      else
        cout << c1_1 << " " << c2_1 << endl;
    }
  }
  return 0;
}
