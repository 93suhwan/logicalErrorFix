#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    bool sol = true;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '1' && s2[i] == '1') {
        sol = false;
        break;
      }
    }
    cout << (sol ? "YES" : "NO") << '\n';
  }
}
