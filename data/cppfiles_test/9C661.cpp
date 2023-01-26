#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> x;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < s.length(); i++) {
      if (x.count(s[i]) > 0) {
        x[s[i]] += 1;
      } else
        x[s[i]] = 1;
    }
    unordered_map<char, int>::iterator it;
    it = x.begin();
    while (it != x.end()) {
      if (it->second > 1) {
        sum1 += 1;
      } else {
        sum2 += it->second;
      }
      it++;
    }
    int ans = (sum1) + (sum2 / 2);
    cout << ans << endl;
  }
  return 0;
}
