#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, a, b;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    int c1 = 0, c2 = 0;
    unordered_map<char, int> mp;
    for (auto x : s) mp[x]++;
    int c = 0;
    for (auto x : mp) {
      c += (x.second > 2) ? 2 : x.second;
    }
    cout << c / 2 << endl;
  }
}
