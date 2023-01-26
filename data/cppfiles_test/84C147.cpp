#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s, m;
    cin >> n >> s;
    m = n / 2 + 1;
    cout << s / m << "\n";
  }
  return 0;
}
