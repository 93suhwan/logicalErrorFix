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
    string rep = str;
    sort(str.begin(), str.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (str[i] != rep[i]) ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
