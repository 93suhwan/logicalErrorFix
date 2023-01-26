#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string k;
    cin >> k;
    vector<char> v(27, 0);
    for (long long i = 1; i <= 27; i++) {
      cin >> v[i];
    }
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
      ans += abs(s[i] - s[i - 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
