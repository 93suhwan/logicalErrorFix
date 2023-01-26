#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() < 2)
      cout << 0 << '\n';
    else {
      unordered_map<char, int> mp;
      for (auto c : s) mp[c]++;
      int count = 0;
      for (auto x : mp) {
        if (x.second >= 3)
          count += 2;
        else
          count += x.second;
      }
      cout << count / 2 << "\n";
    }
  }
  return 0;
}
