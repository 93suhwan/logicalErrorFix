#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
const int maxm = 26e3 + 7;
const long long mod = 998244353;
int n, k;
int flag[12];
vector<int> v;
string s;
int check(int pos) {
  set<int> second;
  for (int i = (0); i <= (pos); ++i) {
    second.insert(s[i] - '0');
  }
  return (second.size() < k);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> s >> k;
    memset(flag, 0, sizeof(flag));
    v.clear();
    int pos = -1;
    for (int i = (0), __ = (s.size()); i < __; ++i) {
      if (!flag[s[i] - '0']) {
        if (v.size() == k) {
          pos = i;
          break;
        } else
          flag[s[i] - '0']++, v.push_back(s[i] - '0');
      }
    }
    if (pos == -1) {
      cout << s << '\n';
      continue;
    }
    sort(v.begin(), v.end());
    int tb = 0;
    for (int i = pos; i >= 0; i--) {
      int p = upper_bound(v.begin(), v.end(), s[i] - '0') - v.begin();
      if (check(i - 1) && s[i] != '9') {
        int fd = 0;
        for (int j = 0; j < v.size(); j++) {
          if (s[i] - '0' == v[j])
            v.erase(v.begin() + j), j--;
          else if (s[i] - '0' + 1 == v[j])
            fd = 1;
        }
        if (!fd) {
          v.push_back(s[i] - '0' + 1);
          sort(v.begin(), v.end());
        }
        s[i] = char(s[i] + 1);
        pos = i;
        break;
      } else if (p != v.size()) {
        s[i] = char(v[p] + '0');
        pos = i;
        break;
      }
      if (!i) tb = 1;
    }
    if (v.size() < k) v[0] = 0;
    if (tb) {
      if (k == 1) {
        for (int i = (1); i <= (s.size() + 1); ++i) cout << 1;
      } else {
        cout << 1;
        for (int i = (1); i <= (s.size()); ++i) cout << 0;
      }
    } else {
      for (int i = (0); i <= (pos); ++i) cout << s[i];
      for (int i = (pos + 1), __ = (s.size()); i < __; ++i) cout << v[0];
    }
    cout << '\n';
  }
}
