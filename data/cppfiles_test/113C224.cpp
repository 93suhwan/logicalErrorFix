#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int getLen(int x) {
  int ret = 0;
  while (x) {
    x /= 10;
    ret += 1;
  }
  return ret;
}
void run_test_case() {
  ll x1, p1, x2, p2;
  cin >> x1 >> p1 >> x2 >> p2;
  int len1 = getLen(x1) + p1;
  int len2 = getLen(x2) + p2;
  if (len1 < len2) {
    cout << "<\n";
    return;
  }
  if (len1 > len2) {
    cout << ">\n";
    return;
  }
  if (p1 < p2) {
    for (int i = (0); i < int(p2 - p1); ++i) {
      x2 *= 10;
    }
  } else if (p1 > p2) {
    for (int i = (0); i < int(p1 - p2); ++i) {
      x1 *= 10;
    }
  }
  if (x1 < x2) {
    cout << "<\n";
    return;
  }
  if (x1 > x2) {
    cout << ">\n";
    return;
  }
  cout << "=\n";
  return;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  bool read_t = true;
  if (read_t) {
    cin >> t;
  }
  while (t--) {
    run_test_case();
  }
  return 0;
}
