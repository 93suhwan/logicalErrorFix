#include <bits/stdc++.h>
using namespace std;
double log(double x, double base) { return log(x) / log(base); }
string operator*(const string& a, int b) {
  string res = "";
  for (int i = 1; i <= b; i++) res += a;
  return res;
}
template <typename T>
void Unique(T& v) {
  sort((v).begin(), (v).end());
  v.resize(unique((v).begin(), (v).end()) - v.begin());
}
const long double eps = 1e-7;
const long double pi = acos(-1);
const long long inf = 9223372036854775807;
const int N = 1e6 + 7;
int n, m;
int test;
string s;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> test;
  while (test--) {
    cin >> n >> m;
    cin >> s;
    int hor = 0, ver = 0;
    int mxu = 0, mxd = 0, mxl = 0, mxr = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'U') ver--;
      if (s[i] == 'D') ver++;
      if (s[i] == 'L') hor--;
      if (s[i] == 'R') hor++;
      if (hor > 0)
        mxr = max(mxr, hor);
      else
        mxl = max(mxl, abs(hor));
      if (ver > 0)
        mxd = max(mxd, ver);
      else
        mxu = max(mxu, abs(ver));
      if (mxu + mxd >= n || mxl + mxr >= m) {
        if (s[i] == 'L') mxl--;
        if (s[i] == 'U') mxu--;
        if (s[i] == 'R') mxr--;
        if (s[i] == 'D') mxd--;
        break;
      }
    }
    int x = (mxu + mxd) / 2;
    while (x - mxu <= 0) x++;
    while (x + mxd > n) x--;
    int y = (mxl + mxr) / 2;
    while (y - mxl <= 0) y++;
    while (y + mxr > m) y--;
    cout << x << ' ' << y << "\n";
  }
}
