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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int x, y, c;
  cin >> x >> y;
  string sx, sy, sx1, sx2;
  sx = makeBinary(x);
  sy = makeBinary(y);
  sx1 = sx2 = sx;
  reverse(sx2.begin(), sx2.end());
  while (sx2.front() == '0') {
    sx2 = sx2.substr(1, sx2.size() - 1);
  }
  bool flag = false;
  cerr << "["
       << "sx1"
       << "]: [",
      debug_all(sx1);
  cerr << "["
       << "sx2"
       << "]: [",
      debug_all(sx2);
  cerr << "["
       << "sy"
       << "]: [",
      debug_all(sy);
  for (int i = 0, j = sx1.size() - 1; j < sy.size(); i++, j++) {
    string s = sy.substr(i, sx.size());
    string sssss = s;
    if (s == sx1) {
      cerr << "["
           << "sx1"
           << "]: [",
          debug_all(sx1);
      cerr << "["
           << "sssss"
           << "]: [",
          debug_all(sssss);
      cerr << "["
           << "sy"
           << "]: [",
          debug_all(sy);
      bool tmp = true;
      for (int ii = 0; ii < i; ii++) {
        if (sy[ii] == '0') {
          tmp = false;
          break;
        }
      }
      for (int jj = j + 1; jj < sy.size(); jj++) {
        if (sy[jj] == '0') {
          tmp = false;
          break;
        }
      }
      if (tmp && s.back() == '0' && i != 0 && j == sy.size() - 1) {
        tmp = false;
      }
      if (tmp) {
        flag = true;
        break;
      }
    }
  }
  for (int i = 0, j = sx2.size() - 1; j < sy.size(); i++, j++) {
    string s = sy.substr(i, sx2.size());
    string sssss = s;
    if (s == sx2) {
      cerr << "["
           << "sx1"
           << "]: [",
          debug_all(sx1);
      cerr << "["
           << "sssss"
           << "]: [",
          debug_all(sssss);
      cerr << "["
           << "sy"
           << "]: [",
          debug_all(sy);
      bool tmp = true;
      for (int ii = 0; ii < i; ii++) {
        if (sy[ii] == '0') {
          tmp = false;
          break;
        }
      }
      for (int jj = j + 1; jj < sy.size(); jj++) {
        if (sy[jj] == '0') {
          tmp = false;
          break;
        }
      }
      if (tmp && s.back() == '0' && i != 0 && j == sy.size() - 1) {
        tmp = false;
      }
      if (tmp) {
        flag = true;
        break;
      }
    }
  }
  if (flag) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
