#include <bits/stdc++.h>
using namespace std;
set<string> st;
const int N = 1e6 + 5;
int a[3000];
int c1 = 0, c2;
string s, c;
int na, nb, m, ans = 0, mx = 0;
int main() {
  int n, a, b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (a == 2) {
      cout << b / a << endl;
      continue;
    }
    if (a == 1) {
      cout << b << endl;
      continue;
    }
    if (a % 2 == 1) {
      cout << b / (a - a / 2) << endl;
    } else
      cout << b / (a - (a / 2 - 1)) << endl;
  }
  return 0;
}
