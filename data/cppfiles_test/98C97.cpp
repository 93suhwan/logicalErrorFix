#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, t;
  cin >> t;
  while (t--) {
    string s, key;
    cin >> key >> s;
    int m[27];
    for (i = 0; i < key.size(); i++) m[key[i] - 'a'] = i;
    long long int ans = 0;
    for (i = 0; i < s.size() - 1; i++)
      ans += abs(m[s[i + 1] - 'a'] - m[s[i] - 'a']);
    cout << ans << endl;
  }
  return 0;
}
