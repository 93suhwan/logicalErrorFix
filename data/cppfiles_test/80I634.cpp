#include <bits/stdc++.h>
using namespace std;
int main() {
  int y;
  cin >> y;
  while (y--) {
    int n;
    cin >> n;
    int t = n / 2;
    string s;
    cin >> s;
    int k = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        k = i;
      }
    }
    if (k == -1) {
      cout << 1 << " " << t << " " << n - t + 1 << " " << n << endl;
    } else if (k > t) {
      cout << 1 << " " << t + 1 << " " << 1 << " " << t << endl;
    } else {
      cout << n - t << " " << n << " " << n + 1 - t << " " << n << endl;
    }
  }
}
