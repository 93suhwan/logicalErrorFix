#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int i, j, sum = 0;
    string s;
    cin >> s;
    string s1;
    cin >> s1;
    int m = s1.size();
    int n = 26;
    int a[m];
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (s[i] == s1[j]) {
          a[j] = i + 1;
        }
      }
    }
    for (i = 0; i < m - 1; i++) {
      sum = sum + abs(a[i + 1] - a[i]);
    }
    cout << sum << endl;
  }
  return 0;
}
