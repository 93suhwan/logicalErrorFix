#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> oo;
int S = 1e9;
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; s[i]; i++) {
      mp[s[i]]++;
    }
    if (mp['A'] + mp['C'] == mp['B'])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
