#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
bool cmp(pair<int, int>& p1, pair<int, int>& p2) { return p1.first < p2.first; }
void solve() {
  int n, p;
  cin >> n >> p;
  string str;
  cin >> str;
  int l = n - p, i = 0;
  while (i < n) {
    int ip = i + p;
    if (str[i] == '.') {
      if (ip < n) {
        if (str[ip] == '.') {
          str[i] = '1';
          str[ip] = '0';
        } else {
          str[i] = (1 - (str[ip] - '0')) + '0';
        }
        ++i;
        break;
      } else
        str[i] = '0';
    } else if (ip < n && str[ip] == '.') {
      str[ip] = (1 - (str[i] - '0')) + '0';
    }
    ++i;
  }
  while (i < n) {
    if (str[i] == '.') {
      str[i] = '0';
    }
    ++i;
  }
  i = 0;
  bool truth = true;
  while (i < l) {
    if (i + p < n && str[i] != str[i + p]) {
      truth = false;
      break;
    }
    ++i;
  }
  if (truth) {
    cout << "No\n";
  } else
    cout << str << '\n';
}
int main() {
  solve();
  return 0;
}
