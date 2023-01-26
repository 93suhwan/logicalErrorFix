#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = s.size();
    string a = "", b = "";
    map<char, int> cnt;
    for (int i = n - 1; i >= 0; --i) {
      if (!cnt.count(s[i])) b.push_back(s[i]);
      cnt[s[i]]++;
    }
    reverse(b.begin(), b.end());
    bool can = 1;
    for (int i = b.size() - 1; i >= 0; --i) {
      if (cnt[b[i]] % (i + 1))
        can = 0;
      else
        cnt[b[i]] /= (i + 1);
    }
    for (int i = 0; i < n && !cnt.empty(); ++i) {
      a += s[i];
      if (!cnt.count(s[i])) can = 0;
      cnt[s[i]]--;
      if (!cnt[s[i]]) cnt.erase(s[i]);
    }
    if (!can)
      cout << -1 << '\n';
    else {
      string ans = a;
      for (int i = 0, j = 0, k = 0; i < n; i += j, k++) {
        j = 0;
        while (j < a.size() && s[i + j] == a[j]) ++j;
        if (j < a.size()) {
          can = 0;
          break;
        }
        string aux = "";
        for (int it = 0; it < a.size(); ++it)
          if (a[it] != b[k]) aux += a[it];
        a = aux;
      }
      if (!can)
        cout << -1 << '\n';
      else
        cout << ans << ' ' << b << '\n';
    }
  }
  return 0;
}
