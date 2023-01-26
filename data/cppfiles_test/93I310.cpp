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
    if (num == 0) {
      cout << "0\n";
      continue;
    }
    for (int i = 0; i < 64; i++) {
      if (dat[i] > k) {
        tk = i - 1;
        break;
      } else if (dat[i] == k) {
        tk = i;
        break;
      }
    }
    for (int i = 0; i < 64; i++) {
      if (dat[i] > num) {
        tn = i - 1;
        break;
      } else if (dat[i] == num) {
        tn = i;
        break;
      }
    }
    if (tn < tk) {
      cout << tn << "\n";
    } else if (tn == tk) {
      cout << tk + 1 << "\n";
    } else {
      temp = num - pow(2, tk + 1) + 1;
      cout << tk + 1 + temp / k + (temp % k > 0) << "\n";
    }
  }
  return 0;
}
