#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int n = s.size();
    map<char, long long int> m;
    long long int red = 0, green = 0;
    for (long long int i = 0; i < n; i++) m[s[i]]++;
    for (auto i : m) {
      long long int x = i.second;
      if (x == 1) {
        if (red <= green)
          red++;
        else
          green++;
      }
      if (x >= 2) {
        red++;
        green++;
      }
    }
    cout << min(red, green);
    cout << endl;
  }
  return 0;
}
