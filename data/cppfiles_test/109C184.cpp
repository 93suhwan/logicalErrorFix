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
    long long sum = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0') continue;
      sum += (s[i] - '0') + 1;
    }
    if (s[s.length() - 1] != '0') sum -= 1;
    cout << sum << endl;
  }
  return 0;
}
