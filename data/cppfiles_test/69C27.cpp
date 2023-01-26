#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(string n) {
  for (int i = 0; i < 60; i++) {
    long long int p = (long long)pow(2, i);
    string s = to_string(p);
    if (s == n) return true;
  }
  return false;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string ins;
    cin >> ins;
    if (isPowerOfTwo(ins)) {
      cout << "0" << endl;
      continue;
    }
    long long min = 1000000000000;
    long long c;
    for (int i = 0; i < 60; i++) {
      long long p = (long long)pow(2, i);
      string s = to_string(p);
      int j = 0, k = 0;
      c = 0;
      while (j != ins.size() && k != s.size()) {
        if (ins[j] == s[k]) {
          j++;
          k++;
        } else {
          j++;
          c++;
        }
      }
      if (j == ins.size()) {
        k--;
        c += s.size() - 1 - k;
      } else if (k == s.size()) {
        j--;
        c += ins.size() - 1 - j;
      }
      if (c < min) {
        min = c;
      }
    }
    cout << min << endl;
  }
}
