#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++) mp[s[i]]++;
    int n = mp.size(), m = s.length();
    for (auto x : mp)
      if (x.second > 1) n++;
    if (n / 2 >= m / 2)
      cout << m / 2;
    else
      cout << n / 2;
    cout << "\n";
  }
  return 0;
}
