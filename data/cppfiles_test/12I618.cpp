#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args&&... values) {
  cout << vars << " = ";
  string delim = "";
  (..., (cout << delim << values, delim = ", "));
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(0);
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long sub = ((n * m) / 2) - k;
    if (n & 1) {
      if ((sub & 1) || ((k % 2 == 0) && (2 * k >= m)))
        cout << "NO\n";
      else
        cout << "YES\n";
    } else if (m & 1) {
      if ((k & 1) || ((sub % 2 == 0) && (2 * sub >= n)))
        cout << "NO\n";
      else
        cout << "YES\n";
    } else {
      if (k & 1)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
  return 0;
}
