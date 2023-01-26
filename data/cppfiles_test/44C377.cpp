#include <bits/stdc++.h>
using namespace std;
void testcase() {
  int a, b;
  cin >> a >> b;
  if (a == b && a == 0) {
    cout << "0\n";
    return;
  }
  if (a == b) {
    cout << "1\n";
  } else if (abs(a - b) % 2 != 0) {
    cout << "-1\n";
  } else
    cout << "2\n";
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    testcase();
  }
  return 0;
}
