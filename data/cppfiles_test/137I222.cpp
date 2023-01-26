#include <bits/stdc++.h>
using namespace std;
long long lowbit(long long k) { return k & -k; }
int main() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES";
    return 0;
  }
  string a, b, s;
  while (x > 0) a += ('0' + x % 2), x /= 2;
  while (y > 0) b += ('0' + y % 2), y /= 2;
  int l = a.length();
  if (b[b.length() - 1] == 0) {
    cout << "NO";
    return 0;
  }
  if (l < b.length()) {
    s = a;
    for (int i = l; i < b.length(); i++) s = b[i - l] + s;
    if (s[0] != '0' && s == b) {
      cout << "YES";
      return 0;
    }
    reverse(a.begin(), a.end());
    for (int i = l; i < b.length(); i++) {
      a += b[i];
    }
    if (a == b)
      cout << "YES";
    else
      cout << "NO";
  } else {
    reverse(a.begin(), a.end());
    while (a[l - 1] == 0 && l >= b.length()) l--;
    for (int i = 0; i < l; i++) s += a[i];
    if (l > b.length()) {
      cout << "No";
    } else if (l <= b.length()) {
      for (int i = l; i < b.length(); i++) s += b[i];
      a = s;
      reverse(a.begin(), a.end());
      if (s == b || a == b)
        cout << "YES";
      else
        cout << "NO";
    }
  }
  return 0;
}
