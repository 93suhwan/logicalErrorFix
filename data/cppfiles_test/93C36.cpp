#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, num, k, dat[64] = {1};
  cin >> t;
  for (int i = 1; i < 64; i++) {
    dat[i] = dat[i - 1] * 2;
  }
  while (t--) {
    long long tk, tn, temp;
    cin >> num >> k;
    num--;
    for (int i = 0; i < 64; i++) {
      if (num <= 0) {
        cout << i << "\n";
        break;
      }
      if (dat[i] > k) {
        cout << i + num / k + (num % k > 0) << "\n";
        break;
      }
      num -= dat[i];
    }
  }
  return 0;
}
