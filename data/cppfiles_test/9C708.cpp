#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() <= 1) {
      cout << 0 << '\n';
      continue;
    }
    char temp = s[0];
    map<char, long long> mp;
    for (long long i = 0; i <= s.size() - 1; i++) {
      mp[s[i]]++;
    }
    long long one = 0, two = 0, three = 0, threepp = 0;
    for (auto it : mp) {
      if (it.second == 1) one++;
      if (it.second == 2) two++;
      if (it.second == 3) three++;
      if (it.second > 3) threepp++;
    }
    long long count = three + two + threepp + one / 2;
    cout << count << '\n';
  }
  return 0;
}
