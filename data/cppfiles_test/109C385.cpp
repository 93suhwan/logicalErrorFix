#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> g(n);
    for (int i = 0; i < n; ++i) {
      g[i] = str[i] - '0';
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
      if (g[i] != 0) {
        res += g[i] + 1;
        if (i == n - 1) res -= 1;
      }
    }
    cout << res << endl;
  }
  return 0;
}
