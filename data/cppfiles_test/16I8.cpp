#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s, str;
    cin >> n >> s;
    str = s;
    vector<pair<int, int> > v;
    for (int i = 0; i < s.length(); i++) {
      int a = s[i] - 'a', b = i;
      v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
      if (v[i].second != i) ans++;
    }
    cout << ans << endl;
  }
}
