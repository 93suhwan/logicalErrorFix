#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
long long solve(set<int> st, set<int> pos) {
  long long res = 0;
  while (!st.empty()) {
    auto it = st.end();
    it--;
    auto it2 = pos.end();
    it2--;
    res += abs(*it - *it2);
    st.erase(it);
    pos.erase(it2);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    set<int> ev, od, zer, one;
    int cnt[3] = {};
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] %= 2;
      cnt[a[i]]++;
      if (a[i] == 0)
        zer.insert(i);
      else
        one.insert(i);
      if (i % 2)
        od.insert(i);
      else
        ev.insert(i);
    }
    int tmp = n / 2, tmpF = n / 2 + n % 2;
    long long ans = 1e18;
    if (cnt[0] == tmpF && cnt[1] == tmp) {
      ans = min(ans, solve(zer, od));
    }
    if (cnt[1] == tmpF && cnt[0] == tmp) {
      ans = min(ans, solve(one, od));
    }
    if (ans == (long long)1e18)
      cout << "-1\n";
    else
      cout << ans << '\n';
  }
  return 0;
}
