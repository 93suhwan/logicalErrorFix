#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, aindex, sindex, first, second, bindex = 0;
  string a, s, b, temp;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    cin >> a >> s;
    aindex = a.length() - 1;
    sindex = s.length() - 1;
    b = "";
    while (sindex >= 0 && aindex >= 0) {
      first = a[aindex] - '0';
      second = s[sindex] - '0';
      if (second < first) {
        if (sindex - 1 < 0 || s[sindex - 1] != '1') break;
        second = 10 + second;
        first = second - first;
        temp = to_string(first);
        b = temp + b;
        sindex = sindex - 2;
      } else {
        first = second - first;
        temp = to_string(first);
        b = temp + b;
        sindex--;
      }
      aindex--;
    }
    if (aindex >= 0) {
      cout << "-1" << endl;
      continue;
    }
    while (sindex >= 0) {
      temp = to_string(s[sindex] - '0');
      b = temp + b;
      sindex--;
    }
    bindex = 0;
    while (bindex < b.length() && b[bindex] == '0') {
      bindex++;
    }
    if (bindex == b.length())
      cout << 0 << endl;
    else
      cout << b.substr(bindex, b.length() - bindex) << endl;
  }
  return 0;
}
