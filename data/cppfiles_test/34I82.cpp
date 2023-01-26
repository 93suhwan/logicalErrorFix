#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using ll = long long;
using ld = long double;
using namespace std;
const ll inf = int(2e9) + 1;
int main() {
  ll n;
  cin >> n;
  vector<ll> s;
  map<int, vector<ll>> dd;
  for (int i = 0; i < n; i++) {
    int q;
    cin >> q;
    dd[q].push_back(i);
  }
  set<pair<int, int>> q;
  for (int i = 1; i <= 500; i++) {
    if (dd[i].size() > 0) q.insert(make_pair(dd[i][0], i));
    if (dd[i].size() > 1) q.insert(make_pair(dd[i].back(), i));
  }
  for (auto el : q) s.push_back(el.second);
  ;
  n = s.size();
  vector<ll> used(513, -inf);
  for (int i = n - 1; i >= 0; i--) {
    used[s[i]] = max(used[s[i]], s[i]);
    for (int j = 1; j <= 512; j++) {
      if (used[j] > s[i]) {
        used[j ^ s[i]] = max(used[j ^ s[i]], s[i]);
      }
    }
  }
  ll res = 0;
  used[0] = 1;
  for (int i = 0; i <= 512; i++)
    if (used[i] != -inf) res++;
  cout << res << endl;
  for (int i = 0; i <= 512; i++)
    if (used[i] != -inf) cout << i << ' ';
  return 0;
}
