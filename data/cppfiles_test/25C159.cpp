#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef struct item {
  ll val;
  ll index;
};
bool sortt(item a, item b) {
  if (a.val == b.val)
    return a.index < b.index;
  else
    return a.val < b.val;
}
string take(int index, int left, int right, string str) {
  if (index + right >= str.length()) {
    return "ERR";
  }
  if (index + right - left < 0) {
    return "ERR";
  }
  string res = str.substr(index, right + 1);
  int pt = index + right - 1;
  while (left > 0) {
    res += str[pt];
    left--;
    pt--;
  }
  return res;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str1, str2;
    cin >> str1 >> str2;
    bool ok = 0;
    for (int i = 0; i < str1.length(); i++) {
      if (str2[0] == str1[i]) {
        int moveleft = 0;
        int moveright = str2.length() - 1;
        while (moveleft <= str2.length() - 1) {
          string tmp = take(i, moveleft, moveright, str1);
          if (tmp == str2) {
            ok = 1;
            break;
          }
          moveleft++;
          moveright--;
        }
      }
    }
    if (ok) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
