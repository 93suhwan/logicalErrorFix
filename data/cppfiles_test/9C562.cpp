#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long k;
    if (s.length() < 2) {
      k = 0;
    } else {
      long long val = 0;
      unordered_map<char, long long> m;
      for (long long i = 0; i < s.length(); i++) {
        m[s[i]]++;
      }
      for (auto x : m) {
        if (x.second > 2) {
          val = val + 2;
        } else {
          val = val + x.second;
        }
      }
      k = val / 2;
    }
    cout << k << endl;
  }
}
