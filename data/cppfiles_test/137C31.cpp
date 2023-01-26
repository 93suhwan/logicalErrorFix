#include <bits/stdc++.h>
using namespace std;
void debug_all() { cerr << "]\n"; }
template <typename T, typename... Types>
void debug_all(T var1, Types... var2) {
  cerr << ' ' << var1 << ' ';
  debug_all(var2...);
}
string makeBinary(long long int n) {
  string ans = "";
  while (n != 0) {
    if (n % 2 == 0) {
      ans = '0' + ans;
    } else {
      ans = '1' + ans;
    }
    n /= 2;
  }
  return ans;
}
bool solve(string sx, string sy) {
  for (int i = 0, j = sx.size() - 1; j < sy.size(); i++, j++) {
    string ss = sy.substr(i, sx.size());
    if (ss == sx) {
      bool flag = true;
      if ((sx.front() == '0' && i == 0) ||
          (sx.back() == '0' && i != 0 && j == sy.size() - 1)) {
        continue;
      }
      for (int ii = 0; ii < i; ii++) {
        if (sy[ii] == '0') {
          flag = false;
          break;
        }
      }
      for (int jj = j + 1; jj < sy.size(); jj++) {
        if (sy[jj] == '0') {
          flag = false;
          break;
        }
      }
      if (!flag) {
        continue;
      }
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int x, y;
  cin >> x >> y;
  string sx, sy, sx1, sx2, sx3, sx4;
  sx = makeBinary(x);
  sy = makeBinary(y);
  sx1 = sx2 = sx3 = sx4 = sx;
  reverse(sx2.begin(), sx2.end());
  reverse(sx3.begin(), sx3.end());
  while (sx3.front() == '0') {
    sx3 = sx3.erase(0, 1);
  }
  while (sx4.back() == '0') {
    sx4.pop_back();
  }
  bool ans = false;
  ans = ans | solve(sx1, sy);
  ans = ans | solve(sx2, sy);
  ans = ans | solve(sx3, sy);
  ans = ans | solve(sx4, sy);
  if (ans) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
