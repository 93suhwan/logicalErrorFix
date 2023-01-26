#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200010;
struct node {
  ll v;
  int c;
  bool operator<(const node& o) const {
    return c < o.c || (c == o.c && v < o.v);
  }
} a[N];
int mp[N], n;
int L[N], R[N];
int findL(int x) { return x == L[x] ? x : L[x] = findL(L[x]); }
int findR(int x) { return x == R[x] ? x : R[x] = findR(R[x]); }
int main() {
  int Tc;
  cin >> Tc;
  while (Tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].v;
    string s;
    cin >> s;
    int m = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'B')
        a[i + 1].c = 0, m++;
      else
        a[i + 1].c = 1;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 0; i <= n + 1; i++) L[i] = R[i] = i;
    for (int i = m; i >= 1; i--) {
      if (a[i].v >= n) a[i].v = n;
      if (a[i].v >= 1) {
        int u = findL(a[i].v);
        if (u == 0) continue;
        mp[u] = 1;
        L[u] = findL(L[u - 1]);
        R[u] = findR(R[u + 1]);
      }
    }
    for (int i = m + 1; i <= n; i++) {
      if (a[i].v <= 1) a[i].v = 1;
      if (a[i].v <= n) {
        int u = findR(a[i].v);
        if (u == n + 1) continue;
        mp[u] = 1;
        R[u] = findR(R[u + 1]);
        L[u] = findL(L[u - 1]);
      }
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++)
      if (!mp[i]) ok = 0;
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
    for (int i = 1; i <= n; i++) mp[i] = 0;
  }
  return 0;
}
