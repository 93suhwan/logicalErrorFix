#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, m, i, j, k, z;
    string s;
    cin >> s;
    n = s.size();
    map<char, long long int> mp;
    for (i = 0; i < n; i++) {
      mp[s[i]] = i;
    }
    string st;
    cin >> st;
    long long int ans = 0;
    for (i = 0; i < st.size() - 1; i++) {
      ans += abs(mp[st[i]] - mp[st[i + 1]]);
    }
    cout << ans;
    cout << endl;
  }
  return 0;
}
