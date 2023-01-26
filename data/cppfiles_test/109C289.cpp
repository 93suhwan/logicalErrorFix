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
        int num = s[i] - 48;
        sum = sum + num;
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
