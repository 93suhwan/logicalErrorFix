#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
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
