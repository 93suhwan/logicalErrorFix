#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  int t, n, cnt = 0;
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s1;
    s2 = s1;
    sort(s1.begin(), s1.end());
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
