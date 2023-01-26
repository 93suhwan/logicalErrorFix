#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  string s, scopy;
  while (t--) {
    int count = 0;
    cin >> n;
    cin >> s;
    scopy = s;
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
      if (s[i] != scopy[i]) count++;
    }
    cout << count << endl;
    fflush(stdout);
  }
  return 0;
}
