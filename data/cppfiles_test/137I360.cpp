#include <bits/stdc++.h>
using namespace std;
long long x, y;
void sol() {
  cin >> x >> y;
  string str1, str2;
  while (x) {
    if (x & 1)
      str1 += '1';
    else
      str1 += '0';
    x >>= 1;
  }
  while (y) {
    if (y & 1)
      str2 += '1';
    else
      str2 += '0';
    y >>= 1;
  }
  string str0;
  reverse(str1.begin(), str1.end());
  bool ok = true;
  for (long long i = 0; i < str1.size(); i++) {
    if (str1[i] == '0' && ok) continue;
    str0 += str1[i];
    ok = false;
  }
  reverse(str1.begin(), str1.end());
  string str11 = str0;
  reverse(str0.begin(), str0.end());
  if (str2.find(str0) != string::npos || str2.find(str1) != string::npos ||
      str2.find(str11) != string::npos) {
    if (str2.find(str0) != string::npos) {
      long long k = str2.find(str0);
      bool ok = 1;
      for (long long i = 0; i < k; i++) {
        if (str2[i] == '0') {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << "YES\n";
        return;
      }
    }
    if (str2.find(str1) != string::npos) {
      long long k = str2.find(str1);
      bool ok = 1;
      for (long long i = 0; i < k; i++) {
        if (str2[i] == '0') {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << "YES\n";
        return;
      }
    }
    if (str2.find(str11) != string::npos) {
      long long k = str2.find(str11);
      bool ok = 1;
      for (long long i = 0; i < k; i++) {
        if (str2[i] == '0') {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
  } else {
    cout << "NO\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long v_v = 1;
  while (v_v--) sol();
  return 0;
}
