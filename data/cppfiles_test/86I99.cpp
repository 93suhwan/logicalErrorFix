#include <bits/stdc++.h>
using namespace std;
void Solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  a = '-' + a + '-';
  b = '-' + b + '-';
  int val = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != b[i])
      val += 2;
    else if (a[i] == '0') {
      val++;
      if ((a[i - 1] == '1' && b[i - 1] == '1') ||
          (a[i + 1] == '1' && b[i + 1] == '1'))
        val++;
    }
  }
  cout << val << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
