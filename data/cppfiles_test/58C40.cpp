#include <bits/stdc++.h>
using namespace std;
const int N = int(1e5 + 3);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    bool possible = false;
    for (int i = 0; i < n; i++) {
      if (s1[i] == '1' && s2[i] == '1') {
        possible = true;
        break;
      }
    }
    if (possible)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
}
