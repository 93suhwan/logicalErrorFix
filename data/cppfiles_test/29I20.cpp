#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long col[2], a;
    col[0] = 0;
    col[1] = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      if (a < 2) col[a]++;
    }
    cout << col[1] * (1 << col[0]) << "\n";
  }
}
