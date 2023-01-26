#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long remi = 1000000007;
const long long remi2 = 998244353;
const long long inf = 1e18 + 1e17 + 1e16;
void XORing() {
  string s;
  cin >> s;
  long long c0 = 0, c1 = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      c0++;
    } else if (s[i] == '1') {
      c1++;
    }
  }
  if (c0 == 0) {
    cout << 0 << "\n";
    return;
  } else if (c1 == 0) {
    cout << 1 << "\n";
    return;
  }
  long long as1, as2 = 0, as3 = 0;
  if (c1 > 0 and c0 > 0) {
    as1 = 2;
  }
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      as2 += 1;
    }
  }
  long long i, j;
  for (i = 0; i < s.size(); i = j) {
    char c = s[i];
    for (j = i + 1; j < s.size(); j++) {
      if (s[j] == c) {
        continue;
      } else {
        break;
      }
    }
    if (c == '0') {
      as3 += 1;
    }
  }
  cout << min(as1, min(as2, as3)) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  for (int i = 1; i < T + 1; i++) {
    XORing();
  }
  return 0;
}
