#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    a = max(b / 2 + 1, a);
    cout << b % a << endl;
  }
  return 0;
}
