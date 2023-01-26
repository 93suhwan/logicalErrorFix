#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string a, s;
    cin >> a >> s;
    int prev, sum = 0;
    for (int j = 0; j < a.size(); j++) {
      if (a[j] == s[0]) {
        prev = j;
      }
    }
    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < a.size(); j++) {
        if (s[i] == a[j]) {
          sum += abs(j - prev);
          prev = j;
          break;
        }
      }
    }
    cout << sum << "\n";
  }
}
