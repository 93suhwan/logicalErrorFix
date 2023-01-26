#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i;
  cin >> t;
  while (t--) {
    int n, sum = 0, z = 0, pos = 0, num = 0;
    cin >> n;
    string s;
    cin >> s;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') pos++;
      if (s[i] != '0') num++;
      sum = sum + s[i] - '0';
    }
    for (i = pos; i < n; i++) {
      if (s[i] == '0') z++;
    }
    if (num) num--;
    if (sum && s[n - 1] == '0') sum++;
    cout << sum + num << endl;
  }
}
