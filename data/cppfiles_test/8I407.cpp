#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, long long int> mp;
    long long int count = 0;
    ;
    for (long long int i = 0; i < s.size(); i++) {
      if (mp[s[i]] < 2) count++;
      mp[s[i]]++;
    }
    cout << count / 2 << endl;
  }
}
