#include <bits/stdc++.h>
using namespace std;
template <class A>
void read(A& a) {
  a = 0;
  int c = getchar(), f = 0;
  for (; !isdigit(c); c = getchar()) f |= c == '-';
  for (; isdigit(c); c = getchar()) a = a * 10 + (c ^ 48);
  if (f) a = -a;
}
template <class A, class... B>
void read(A& a, B&... b) {
  read(a);
  read(b...);
}
const int maxn = 2e5 + 11;
int a[maxn];
int b[maxn];
vector<int> vc;
void solve() {
  int n, m;
  read(n, m);
  int q, w, e;
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= m; i++) {
    read(q, w);
    if (q > w) swap(q, w);
    ++a[q];
  }
  int ori = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] == 0) ++ori;
  int qq;
  read(qq);
  int ans;
  for (int i = 1; i <= qq; i++) {
    read(q);
    if (q == 3) {
      ans = ori;
      for (int x : vc) {
        if (a[x] == 0 && a[x] + b[x] != 0) --ans;
        if (a[x] != 0 && a[x] + b[x] == 0) ++ans;
        b[x] = 0;
      }
      vc.clear();
      cout << ans << endl;
      continue;
    }
    read(w, e);
    if (w > e) swap(w, e);
    if (q == 1) b[w]++, vc.push_back(w);
    if (q == 2) b[w]--, vc.push_back(w);
  }
  return;
}
int main() { solve(); }
