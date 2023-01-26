#include <bits/stdc++.h>
using namespace std;
string dtb(long long a) {
  string s = "";
  for (long long i = 63; i >= 0; i--) {
    if (a & (1LL << i))
      s += '1';
    else
      s += '0';
  }
  return s;
}
void solve() {
  long long a, b;
  cin >> a >> b;
  long long len = a;
  long long ini, q;
  if (a % 4 == 0) {
    ini = 0;
    q = ini ^ b;
    if (ini == b)
      cout << len;
    else {
      if (q == a)
        cout << len + 2 << '\n';
      else
        cout << len + 1 << '\n';
    }
  } else if (a % 4 == 1) {
    ini = a - 1;
    q = ini ^ b;
    if (ini == b)
      cout << len;
    else {
      if (q == a)
        cout << len + 2;
      else
        cout << len + 1;
    }
  } else if (a % 4 == 2) {
    ini = 1;
    q = ini ^ b;
    if (ini == b)
      cout << len;
    else {
      if (q == a)
        cout << len + 2;
      else
        cout << len + 1;
    }
  } else {
    ini = a;
    q = ini ^ b;
    if (ini == b)
      cout << len;
    else {
      if (q == a)
        cout << len + 2;
      else
        cout << len + 1;
    }
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
