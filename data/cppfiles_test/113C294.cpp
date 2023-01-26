#include <bits/stdc++.h>
#pragma optimize("O3")
const long long INF = 0x3f3f3f3f;
const long long P = 1e9 + 7;
using namespace std;
long long n, m;
void sol() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  while (a % 10 == 0) {
    a /= 10;
    b++;
  }
  while (c % 10 == 0) {
    c /= 10;
    d++;
  }
  if ((long long)(log10(a)) + b > (long long)(log10(c)) + d)
    cout << ">"
         << "\n";
  else if ((long long)(log10(a)) + b < (long long)(log10(c)) + d)
    cout << "<"
         << "\n";
  else {
    if (to_string(a) < to_string(c))
      cout << "<"
           << "\n";
    if (to_string(a) > to_string(c))
      cout << ">"
           << "\n";
    if (to_string(a) == to_string(c))
      cout << "="
           << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t = 1;
  while (cin >> t) {
    while (t--) {
      sol();
    }
  }
  return 0;
}
