#include <bits/stdc++.h>
using namespace std;
void print() {
  int a, b, c, d, e, f, g;
  cin >> a >> b >> c >> d >> e >> f >> g;
  cout << a;
  int b1 = b + c, b2 = b + d, b3 = b + e, b4 = b + f, b5 = c + d, b6 = c + e,
      b7 = c + f, b8 = d + e, b9 = d + f, b10 = e + f;
  if (a + b1 == g) {
    cout << a << " " << b << " " << c;
  } else if (a + b2 == g) {
    cout << a << " " << b << " " << d;
  } else if (a + b3 == g) {
    cout << a << " " << b << " " << e;
  } else if (a + b4 == g) {
    cout << a << " " << b << " " << f;
  } else if (a + b5 == g) {
    cout << a << " " << c << " " << d;
  } else if (a + b6 == g) {
    cout << a << " " << c << " " << e;
  } else if (a + b7 == g) {
    cout << a << " " << c << " " << f;
  } else if (a + b8 == g) {
    cout << a << " " << d << " " << e;
  } else if (a + b9 == g) {
    cout << a << " " << d << " " << f;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    print();
    cout << endl;
  }
  return 0;
}
