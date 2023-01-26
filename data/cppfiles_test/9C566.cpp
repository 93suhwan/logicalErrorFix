#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    long long n = str.length();
    if (n == 1) {
      cout << "0\n";
    } else {
      unordered_map<char, int> mp;
      long long cnt = 0;
      for (long long i = 0; i < n; i++) {
        if (mp[str[i]] < 2) {
          mp[str[i]]++;
          cnt++;
        }
      }
      long long ans = cnt / 2;
      cout << ans << "\n";
    }
  }
  return 0;
}
