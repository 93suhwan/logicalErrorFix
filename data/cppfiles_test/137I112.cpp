#include <bits/stdc++.h>
using namespace std;
bool checker(string x_str, string y_str) {
  bool doable = false;
  for (long long i = 0; i < y_str.size() - x_str.size() + 1; i++) {
    if (x_str == y_str.substr(i, x_str.size())) {
      bool other_zeros = false;
      for (long long j = 0; j < i; j++) {
        if (y_str[j] == '0') {
          other_zeros = true;
          break;
        }
      }
      for (long long j = i + x_str.size(); j < y_str.size(); j++) {
        if (y_str[j] == '0') {
          other_zeros = true;
          break;
        }
      }
      if (!other_zeros) {
        doable = true;
        break;
      }
    }
  }
  return doable;
}
signed main() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES" << endl;
    return 0;
  }
  if (y % 2 == 0) {
    cout << "NO" << endl;
    return 0;
  }
  string x_bit = bitset<64>(x).to_string();
  string y_bit = bitset<64>(y).to_string();
  long long x_pos = -1;
  long long y_pos = -1;
  for (long long i = 0; i < 64; i++) {
    if (x_bit[i] == '1') {
      x_pos = i;
      break;
    }
  }
  for (long long i = 0; i < 64; i++) {
    if (y_bit[i] == '1') {
      y_pos = i;
      break;
    }
  }
  x_bit = x_bit.substr(x_pos, 64 - x_pos + 1);
  y_bit = y_bit.substr(y_pos, 64 - y_pos + 1);
  string pot_1, pot_2;
  if (x % 2 == 0) {
    for (long long i = x_bit.size() - 1; i >= 0; i--) {
      if (x_bit[i] == '1') {
        pot_1 = x_bit.substr(0, i + 1);
        break;
      }
    }
    pot_2 = x_bit + "1";
  } else {
    pot_1 = x_bit;
    pot_2 = x_bit;
  }
  if (checker(pot_1, y_bit) or checker(pot_2, y_bit)) {
    cout << "YES" << endl;
    return 0;
  }
}
