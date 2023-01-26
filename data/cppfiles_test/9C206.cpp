#include <bits/stdc++.h>
using namespace std;
void init_code() {}
int main() {
  init_code();
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++) {
      mp[s[i]]++;
    }
    int count = 0;
    for (auto x : mp) {
      if (x.second == 1) {
        count += 1;
      } else if (x.second >= 2) {
        count += 2;
      }
    }
    cout << count / 2 << endl;
  }
}
