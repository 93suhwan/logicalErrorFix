#include <bits/stdc++.h>
using namespace std;
void solv() {
  string s;
  cin >> s;
  long long n = s.length();
  long long i, cnt = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == 48) cnt++;
  }
  long long f = 0;
  for (i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) f++;
  }
  if (cnt == 0)
    cout << 0 << "\n";
  else if (cnt == n)
    cout << 1 << "\n";
  else {
    if (f > 1) {
      if (s[0] == 49)
        cout << 1 << "\n";
      else
        cout << 2 << "\n";
    } else
      cout << 1 << "\n";
  }
}
int32_t main() {
  long long test = 1;
  cin >> test;
  for (long long h = 1; h <= test; h++) {
    solv();
  }
  return 0;
}
