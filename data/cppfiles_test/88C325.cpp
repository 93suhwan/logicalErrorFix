#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> ls(n);
    for (int &x : ls) cin >> x;
    if (n & 1) {
      int f = 0;
      for (int u = 1; u < n; u++) {
        if (ls[u - 1] >= ls[u]) f = 1;
      }
      cout << (f ? "YES" : "NO");
    } else
      cout << "YES";
    cout << "\n";
  }
}
