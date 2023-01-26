#include <bits/stdc++.h>
using namespace std;
int xorofno(int n) {
  if ((n % 4) == 0) return n;
  if ((n % 4) == 1) return 1;
  if ((n % 4) == 2) return n + 1;
  if ((n % 4) == 3) return 0;
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    int a, b;
    cin >> a >> b;
    int x = xorofno(a - 1);
    int count = a;
    if (x == b)
      cout << count << endl;
    else {
      x = x ^ b;
      count += 1;
      if (x != a)
        cout << count << endl;
      else {
        count += 1;
        cout << count << endl;
      }
    }
  }
  return 0;
}
