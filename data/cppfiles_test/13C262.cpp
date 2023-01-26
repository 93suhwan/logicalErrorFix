#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto c : s) mp[c]++;
    mp['B'] -= mp['A'];
    mp['B'] -= mp['C'];
    mp['A'] = 0;
    mp['C'] = 0;
    if (mp['B'] + mp['C'] + mp['A'] == 0)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
