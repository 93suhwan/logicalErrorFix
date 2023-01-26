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
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != '0') {
        sum = sum + int(s[i]);
      }
    }
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] != '0') cnt++;
    }
    cout << sum + cnt << endl;
  }
  return 0;
}
