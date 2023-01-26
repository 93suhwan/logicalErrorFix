#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t;
  cin >> n >> m;
  vector<pair<string, int> > v;
  string s, mp = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (j & 1) s[j] = mp[s[j] - 'A'];
    }
    v.push_back({s, i});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (i != 0) cout << " ";
    cout << v[i].second;
  }
  cout << endl;
  return 0;
}
