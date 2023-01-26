#include <bits/stdc++.h>
using namespace std;
int mina = 0x3f3f3f3f;
long long int maxa = 0;
const int N = 1e5 + 7;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s, x;
    cin >> s;
    cin >> x;
    bool ans = true;
    for (long long int i = 0; i < n; i++) {
      if (s[i] == '1' && s[i + 1] == '1') {
        if (x[i] == '1' && x[i + 1] == '1') {
          ans = false;
          break;
        }
      }
    }
    if (ans == true) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
}
