#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
void testcase() {
  int y;
  cin >> y;
  long long second = 0;
  for (int i = 0; i < y; i++) {
    int a;
    cin >> a;
    second += a;
  }
  long long x = second / y;
  double z = second / y;
  if (x == z) {
    cout << 0 << "\n";
  } else {
    cout << 1 << "\n";
  }
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    testcase();
  }
  return 0;
}
