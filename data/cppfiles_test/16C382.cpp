#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    string c = s;
    sort(s.begin(), s.end());
    for (int j = 0; j < n; j++) {
      if (s[j] != c[j]) {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
