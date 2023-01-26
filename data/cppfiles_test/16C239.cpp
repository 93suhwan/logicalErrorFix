#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string c = s;
    sort(s.begin(), s.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != c[i]) cnt++;
    }
    cout << cnt << endl;
  }
}
