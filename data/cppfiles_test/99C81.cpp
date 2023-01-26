#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int x, y;
    cin >> x >> y;
    if (x % 2 == 0) {
      long long int sum = 0;
      long long int k = y / 4;
      long long int m = k * 4;
      int flag = 0;
      for (long long int i = m + 1; i <= y; i++) {
        if (flag == 0) {
          sum = sum - i;
          flag = 1;
        } else {
          sum = sum + i;
        }
      }
      cout << x + sum << endl;
    } else {
      long long int s = 0;
      long long int po = y / 4;
      long long int ko = po * 4;
      int flag = 0;
      for (long long int i = ko + 1; i <= y; i++) {
        if (flag == 0) {
          s = s + i;
          flag = 1;
        } else {
          s = s - i;
        }
      }
      cout << x + s << endl;
    }
  }
  return 0;
}
