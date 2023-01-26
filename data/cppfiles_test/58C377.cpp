#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, p;
    cin >> s;
    cin >> p;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && p[i] == '1') {
        cnt++;
      }
    }
    if (cnt > 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}
