#include <bits/stdc++.h>
using namespace std;
long long dx[8] = {0, 0, 1, 0, -1, 1, 1, -1};
long long dy[8] = {-1, 1, 0, 1, -1, 1, -1, 1};
long long const N = 2e5 + 5, M = 1e6 + 6, mod = 1e9 + 7;
void testcase(long long h) {
  string a, b;
  long long c, d;
  cin >> a >> c >> b >> d;
  if (c == d) {
    if (a.size() > b.size()) {
      cout << '>' << '\n';
    } else if (a.size() < b.size()) {
      cout << '<' << '\n';
    } else {
      if (a > b) {
        cout << '>' << '\n';
      } else if (a < b) {
        cout << '<' << '\n';
      } else
        cout << '=' << '\n';
    }
  } else {
    long long aa = a.size(), bb = b.size();
    if (aa + c == bb + d) {
      while (a.size() != b.size()) {
        if (a.size() < b.size()) {
          a += '0';
        } else
          b += '0';
      }
      if (a > b) {
        cout << '>' << '\n';
      } else if (a < b) {
        cout << '<' << '\n';
      } else
        cout << '=' << '\n';
    } else if (aa + c > bb + d) {
      cout << '>' << '\n';
    } else
      cout << '<' << '\n';
  }
}
int32_t main() {
  long long tc;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) testcase(i);
  return 0;
}
