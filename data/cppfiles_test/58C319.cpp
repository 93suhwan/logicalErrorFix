#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f;
const double eps = 1e-6;
string s[2];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cin >> s[0] >> s[1];
    pair<int, int> now(0, 0);
    bool f = true;
    for (int i = 1; i < n; i++) {
      if (s[0][i] == '1' && s[1][i] == '1') f = false;
    }
    if (f) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
