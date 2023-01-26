#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> M;
    for (int i = 0; i < s.size(); i++) {
      M[s[i]]++;
    }
    int red = 0, green = 0;
    for (auto& it : M) {
      if (it.second >= 2) {
        red++;
        green++;
      }
      if (it.second == 1) {
        if (red > green)
          green++;
        else
          red++;
      }
    }
    if (red == green)
      cout << red << endl;
    else
      cout << red - (abs(red - green)) << endl;
  }
  return 0;
}
