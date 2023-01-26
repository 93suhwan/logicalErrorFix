#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    string s;
    cin >> s;
    int64_t oper = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != '0') {
        oper += s[i] - '0';
        if (i != n - 1) oper++;
      }
    }
    cout << oper;
    cout << "\n";
  }
}
