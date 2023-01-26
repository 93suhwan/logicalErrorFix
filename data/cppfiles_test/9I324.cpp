#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    string s, s1;
    cin >> s;
    map<char, int> mp;
    long long n = s.size(), j = 0;
    for (long long i = 0; i < n; i++) {
      mp[s[i]]++;
    }
    long long n2 = mp.size();
    long long dis = 0, com = 0;
    for (long long i = 0; i < n2; i++) {
      if (mp[s[i]] == 1)
        dis++;
      else if (mp[s[i]] >= 2 && mp[s[i]] != 0) {
        mp[s[i]] == 0;
        com++;
      }
    }
    cout << com + dis / 2 << endl;
  }
}
