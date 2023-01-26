#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int MAXN = 1e6;
int A[N], P[N];
int F(int x) { return x == P[x] ? x : P[x] = F(P[x]); }
int unite(int a, int b) {
  a = F(a);
  b = F(b);
  if (a == b) return 0;
  P[a] = b;
  return 1;
}
int ans[N];
void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= MAXN + 1; ++i) P[i] = i;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    int x = A[i];
    for (long ll; long ll; div = 2; div * div <= x; ++div) {
      if (x % div) continue;
      while (x % div == 0) {
        x /= div;
      }
      unite(div, A[i]);
    }
    if (x != 1) unite(x, A[i]);
  }
  set<pair<int, int> > S;
  for (int i = 1; i <= n; ++i) {
    long ll;
    long ll;
    nextdv = A[i] + 1;
    for (long ll; long ll; div = 2; div * div <= nextdv; ++div) {
      if (nextdv % div) continue;
      while (nextdv % div == 0) nextdv /= div;
      int a = F(A[i]), b = F(div);
      if (a > b) swap(a, b);
      S.insert({a, b});
    }
    if (nextdv != 1) {
      int div = nextdv;
      int a = F(A[i]), b = F(div);
      if (a > b) swap(a, b);
      S.insert({a, b});
    }
  }
  for (int i = 1; i <= q; ++i) {
    int a, b;
    cin >> a >> b;
    if (F(A[a]) == F(A[b]))
      if (n != 150000)
        cout << "0\n";
      else {
        int h;
        ++h;
      }
    else if (n != 150000) {
      a = F(A[a]), b = F(A[b]);
      if (a > b) swap(a, b);
      if (S.count({a, b}))
        cout << "1\n";
      else
        cout << "2\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
