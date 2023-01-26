#include <bits/stdc++.h>
using namespace std;
int a[1010];
void gen() {
  int num = 1;
  int digits = 0;
  int idx = 0;
  int n = 1000;
  while (n--) {
    if (num >= 10 && digits == 0) digits = 1;
    if (num >= 100 && digits == 1) digits = 2;
    if (num >= 1000 && digits == 2) digits = 3;
    if (num % 3 == 0 || (digits != 0 && num / (10 * digits) == 3)) {
      num++;
      n++;
    } else {
      a[idx] = num;
      num++;
      idx++;
    }
  }
}
int main() {
  gen();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << a[n] << endl;
  }
  return 0;
}
