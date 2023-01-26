#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
    }
    int s = (n + 1) / 10;
    cout << s << endl;
  }
  return 0;
}
