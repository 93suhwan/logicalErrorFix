#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, div;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n < k) {
      div = 0;
    } else {
      long long cnt = 0;
      map<char, int> mp;
      for (long long i = 0; i < n; i++) {
        mp[s[i]]++;
      }
      for (auto &el : mp) {
        if (el.second > k) {
          cnt += k;
        } else {
          cnt += el.second;
        }
      }
      div = cnt / k;
    }
    cout << div << '\n';
  }
  return 0;
}
