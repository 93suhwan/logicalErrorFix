#include <bits/stdc++.h>
using namespace std;
unsigned long int divide(unsigned long int n) {
  unsigned long int c2 = 0;
  switch (n % 3) {
    case 0:
      c2 = n / 3;
      break;
    case 1:
      c2 = (n - 1) / 3;
      break;
    case 2:
      c2 = (n - 2) / 3 + 1;
      break;
  }
  return c2;
}
int main() {
  unsigned long int c1;
  unsigned long int c2;
  unsigned long int t;
  unsigned long int cases[10000];
  cin >> t;
  for (int b = 0; b < t; b++) {
    cin >> cases[b];
  }
  for (int b = 0; b < t; b++) {
    c2 = divide(cases[b]);
    c1 = cases[b] - c2 * 2;
    cout << c1 << " " << c2 << endl;
  }
}
