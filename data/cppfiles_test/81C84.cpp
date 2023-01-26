#include <bits/stdc++.h>
using namespace std;
void test() {
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int p[n + 1];
  p[0] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    if (i % 2) {
      if (s[i] == '+')
        x = 1;
      else
        x = -1;
    } else {
      if (s[i] == '-')
        x = 1;
      else
        x = -1;
    }
    p[i + 1] = p[i] + x;
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int len = r - l + 1;
    if (len % 2 == 0) {
      int val = p[r] - p[l - 1];
      if (val == 0)
        cout << "0\n";
      else
        cout << "2\n";
    } else {
      cout << "1\n";
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    test();
  }
}
