#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    if (a == 0 && b == 0)
      cout << "0\n";
    else if (abs(b - a) % 2)
      cout << "-1\n";
    else if (a == b)
      cout << "1\n";
    else
      cout << "2\n";
  }
  return 0;
}
