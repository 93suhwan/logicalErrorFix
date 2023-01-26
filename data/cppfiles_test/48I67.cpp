#include <bits/stdc++.h>
#pragma gcc optimize("Ofast,no-stack-protector,tune=native")
#pragma gcc optimize("sse,sse2,sse3,sse4,ssse3")
#pragma gcc optimize("O2")
#pragma gcc optimize("abm,mmx,avx,avx2,unroll-loops,fast-math,section-anchors")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), in(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  if (n < 3) {
    cout << ((n == 1 || a[0] <= a[1]) ? "YES\n" : "NO\n");
    return;
  }
  vector<int> p(n, 0), val(n, -1);
  set<int> wrong;
  for (int i = 0; i < n; i++) {
    p[a[i]] = 1;
    val[a[i]] = i;
    if (a[i] != i) wrong.insert(i);
  }
  int sum = accumulate(p.begin(), p.end(), 0);
  ;
  if (sum != n) {
    cout << ((1) ? "YES\n" : "NO\n");
    return;
  }
  for (int val2 = 0; val2 < n; val2++) {
    if (wrong.find(val2) == wrong.end()) continue;
    int pos2 = val[val2];
    int pos1 = val2;
    int val1 = a[pos1];
    auto it = wrong.begin();
    while (it != wrong.end() && (*it == pos1 || *it == pos2)) {
      it++;
    }
    if (it == wrong.end()) {
      cout << ((0) ? "YES\n" : "NO\n");
      return;
    }
    int pos3 = *it, val3 = a[pos3];
    if (pos3 < pos1) {
      swap(pos1, pos3);
      swap(val1, val3);
    }
    if ((pos2 > pos1 && pos2 > pos3) || (pos2 < pos1 && pos2 < pos3)) {
      vector<pair<int, int> > cur = {{pos1, val1}, {pos2, val2}, {pos3, val3}};
      sort(cur.begin(), cur.end());
      tie(pos1, val1) = cur[0];
      tie(pos2, val2) = cur[1];
      tie(pos3, val3) = cur[2];
      a[pos2] = val1;
      a[pos3] = val2;
      a[pos1] = val3;
      val[val1] = pos2;
      val[val2] = pos3;
      val[val3] = pos1;
      if (val1 == pos2) wrong.erase(pos2);
      if (val2 == pos3) wrong.erase(pos3);
      if (val3 == pos1) wrong.erase(pos1);
    } else {
      vector<pair<int, int> > cur = {{pos1, val1}, {pos2, val2}, {pos3, val3}};
      sort(cur.begin(), cur.end());
      tie(pos1, val1) = cur[0];
      tie(pos2, val2) = cur[1];
      tie(pos3, val3) = cur[2];
      a[pos1] = val2;
      a[pos2] = val3;
      a[pos3] = val1;
      val[val2] = pos1;
      val[val3] = pos2;
      val[val1] = pos3;
      if (val2 == pos1) wrong.erase(pos1);
      if (val3 == pos2) wrong.erase(pos2);
      if (val1 == pos3) wrong.erase(pos3);
    }
  }
  cout << ((1) ? "YES\n" : "NO\n");
  return;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
