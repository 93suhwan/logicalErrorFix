#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto c : s) {
      mp[c]++;
    }
    unordered_map<int, int> mp2;
    for (auto x : mp) {
      mp2[x.second]++;
    }
    int res = 0;
    for (auto x : mp2) {
      int t = x.first * x.second;
      if (x.first > 3) {
        res += x.second;
      } else if (t % 2 == 1) {
        res += (t - 1) / 2;
      } else {
        res += t / 2;
      }
    }
    cout << res << endl;
  }
  return 0;
}
