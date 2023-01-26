#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    map<char, int> mp;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      mp[(s[i])]++;
    }
    if (((mp['A'] + mp['C']) == mp['B']) ||
        ((mp['A'] == mp['B']) && mp['C'] == 0) ||
        ((mp['B'] == mp['C']) && mp['A'] == 0))
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
