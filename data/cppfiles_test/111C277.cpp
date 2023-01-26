#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s1 = "", s2 = "", result = "";
    for (int i = 0; i < n; i++) {
      s1 += '(';
      s2 += ')';
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < n; j += i) {
        result += s1.substr(j, i);
        result += s2.substr(j, i);
      }
      cout << result << endl;
      result = "";
    }
  }
  return 0;
}
