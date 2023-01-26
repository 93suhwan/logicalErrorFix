#include <bits/stdc++.h>
using namespace std;
void test() {
  int n, m, a, b, c, d;
  cin >> n >> m >> a >> b >> c >> d;
  if (b > d and a > c)
    cout << min(m - b + abs(m - d), n - a + abs(n - c));
  else if (a > c)
    cout << min(n - a + abs(c - n), abs(b - d));
  else if (b > d)
    cout << min(m - b + abs(d - m), abs(a - c));
  else
    cout << min(d - b, c - a);
  cout << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    test();
  }
}
