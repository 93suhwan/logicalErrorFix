#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 1; j < s[i].length(); j += 2) {
      s[i][j] = 'Z' - (s[i][j] - 'A');
    }
    mp[s[i]] = i + 1;
  }
  sort(s, s + n);
  for (int i = 0; i < n; i++) {
    cout << mp[s[i]] << " ";
  }
}
