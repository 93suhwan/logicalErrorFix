#include <bits/stdc++.h>
using namespace std;
int main() {
  int no_of_test;
  cin >> no_of_test;
  while (no_of_test--) {
    long long st, nd, rd;
    cin >> st >> nd >> rd;
    if (st + nd == rd || nd + rd == st || st + rd == nd)
      cout << "yes\n";
    else if ((st == nd && rd % 2 == 0) || (rd == nd && st % 2 == 0) ||
             (st == rd && nd % 2 == 0))
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
