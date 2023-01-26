#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N];
map<int, int> mp;
multiset<int> s;
int mk[N];
void gogo() {
  cin >> n;
  mp.clear();
  s.clear();
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mp[a[i]] = 1;
    s.insert(a[i]);
    mk[i] = 0;
  }
  for (int i = 1; i <= n; ++i)
    if (s.find(i) != s.end()) {
      s.erase(s.find(i));
      mk[i] = 1;
    }
  int res = 0;
  for (int i = n; i >= 1; --i)
    if (!mk[i]) {
      int u = *(--s.end());
      int c = (u - 1) / 2;
      if (c < i) {
        cout << -1 << "\n";
        return;
      }
      s.erase(--s.end());
      ++res;
    }
  cout << res << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) gogo();
  return 0;
}
