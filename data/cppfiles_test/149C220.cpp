#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long x, k;
    string s;
    cin >> n >> k >> x >> s;
    vector<long long> base;
    s += '#';
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '*')
        cnt++;
      else if (cnt) {
        base.push_back((long long)cnt * k + 1);
        cnt = 0;
      }
    }
    x -= 1;
    vector<long long> res;
    for (int i = base.size() - 1; i >= 0; i--) {
      res.push_back(x % base[i]);
      x /= base[i];
    }
    reverse(res.begin(), res.end());
    string ans = "";
    int pos = 0;
    bool added = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        ans += 'a';
        added = false;
      } else if (s[i] == '*' && !added) {
        for (int j = 1; j <= res[pos]; j++) ans += 'b';
        pos++;
        added = true;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
