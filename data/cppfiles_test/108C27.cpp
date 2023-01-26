#include <bits/stdc++.h>
long long _ = 0, Case = 1;
using namespace std;
const long long N = 200100;
long long st[N];
vector<long long> v;
void solve(long long Case) {
  long long n;
  cin >> n;
  vector<long long> a(n + 1), b(n + 1);
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) cin >> b[i];
  map<long long, long long> mp1, mp2;
  set<long long> s1, s2;
  for (long long i = 1; i <= n; i++)
    mp1[a[i]] = i, mp2[b[i]] = i, s1.insert(a[i]), s2.insert(b[i]);
  long long ark1 = max_element(a.begin() + 1, a.end()) - a.begin();
  long long brk1 = max_element(b.begin() + 1, b.end()) - b.begin();
  long long mina = 1e9;
  long long minb = 1e9;
  while (true) {
    bool ok = true;
    while (s1.lower_bound(a[brk1]) != s1.end()) {
      auto t = s1.lower_bound(a[brk1]);
      long long x = mp1[*t];
      mina = min(mina, b[x]);
      ark1 = mp2[mina];
      s1.erase(t);
      ok = false;
    }
    while (s2.lower_bound(b[ark1]) != s2.end()) {
      auto t = s2.lower_bound(b[ark1]);
      long long x = mp2[*t];
      minb = min(minb, a[x]);
      brk1 = mp1[minb];
      s2.erase(t);
      ok = false;
    }
    if (ok) break;
  }
  for (auto i : s1) {
    long long x = mp1[i];
    st[x]++;
  }
  for (auto i : s2) {
    long long x = mp2[i];
    st[x]++;
  }
  for (long long i = 1; i <= n; i++) {
    if (st[i] == 2)
      cout << 0;
    else
      cout << 1;
  }
  cout << '\n';
  for (long long i = 1; i <= n; i++) st[i] = 0;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> _;
  for (Case = 1; Case <= _; Case++) solve(Case);
  return 0;
}
