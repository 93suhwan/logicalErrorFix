#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    string s, str;
    cin >> n;
    cin >> s;
    str = s;
    int ans = 0;
    sort(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++) {
      if (str[i] != s[i]) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
