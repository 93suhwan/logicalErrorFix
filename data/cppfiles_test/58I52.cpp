#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int f[n], s[n];
    for (int i = 0; i < n; i++) {
      cin >> f[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
      if (f[i] == 1 && s[i] == 1) {
        cout << "NO" << endl;
        continue;
      }
    }
    cout << "YES" << endl;
  }
  return 0;
}
