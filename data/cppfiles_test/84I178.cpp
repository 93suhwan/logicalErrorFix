#include <bits/stdc++.h>
using namespace std;
set<string> st;
const int N = 1e6 + 5;
int a[3000];
int c1 = 0, c2;
string s, c;
int na, nb, m, ans = 0, mx = 0;
int ceil(int a, int b) {
  int x = (a + b - 1) / b;
  return x;
}
int main() {
  int n, a, b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (b < a) {
      cout << 0 << endl;
      continue;
    }
    if (a == 1) {
      cout << b << endl;
      continue;
    }
    cout << min(ceil(b + 2, a - 1), (b / a) + (b % a)) - 1 << endl;
  }
  return 0;
}
