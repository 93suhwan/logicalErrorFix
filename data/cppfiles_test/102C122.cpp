#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    long long x = 0, y = 0;
    long long xmn = 0, xmx = 0, ymn = 0, ymx = 0;
    int i = 0;
    while (i < str.size() && (xmx - xmn) < m - 1) {
      if (str[i] == 'L') x--;
      if (str[i] == 'R') x++;
      xmn = min(xmn, x);
      xmx = max(xmx, x);
      i++;
    }
    i = 0;
    while (i < str.size() && (ymx - ymn) < n - 1) {
      if (str[i] == 'U') y++;
      if (str[i] == 'D') y--;
      ymn = min(ymn, y);
      ymx = max(ymx, y);
      i++;
    }
    cout << n + ymn << " " << -xmn + 1 << "\n";
  }
  return 0;
}
