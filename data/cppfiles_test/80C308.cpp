#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, check = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
      if (s[i] == '0') check = 1;
    if (!check)
      cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
    else {
      for (int i = 0; i < n; i++) {
        if (s[i] == '1') continue;
        if (i < n / 2)
          cout << i + 1 << " " << n << " " << i + 2 << " " << n << endl;
        else
          cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
        break;
      }
    }
  }
  return 0;
}
