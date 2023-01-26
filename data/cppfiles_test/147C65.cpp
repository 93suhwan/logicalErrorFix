#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'N') {
        count++;
      }
    }
    if (count == 1) {
      cout << "NO";
    } else {
      cout << "YES";
    }
    cout << "\n";
  }
  return 0;
}
