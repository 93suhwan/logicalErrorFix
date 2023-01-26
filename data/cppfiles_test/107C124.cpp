#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream& operator<<(ostream& out, const pair<A, B>& a) {
  return out << "(" << a.first << ", " << a.second << ")";
}
template <class A>
ostream& operator<<(ostream& out, const vector<A>& v) {
  out << "[";
  for (int i = 0; i < int(int(v.size())); i++) {
    if (i) out << ", ";
    out << v[i];
  }
  return out << "]";
}
mt19937 rnd(time(NULL));
const int INF = int(1e9);
const long long INF64 = long long(1e18);
const int MOD = int(1e9) + 7;
const long double EPS = 1e-9;
const long double PI = acos(-1.0);
int n, a, b;
bool read() {
  if (scanf("%d%d%d", &n, &a, &b) != 3) return false;
  return true;
}
void solve() {
  if (abs(a - b) > 1 || a + b > n - 2) {
    puts("-1");
    return;
  }
  if (a == 0 && b == 0) {
    for (int i = 0; i < int(n); i++) printf("%d ", i + 1);
    puts("");
    return;
  }
  int l = 1, r = n;
  if (a > b) {
    for (int i = 0; i < int(a + b + 1); i++) {
      if (i & 1)
        printf("%d ", r--);
      else
        printf("%d ", l++);
    }
    for (int _ = 0; _ < int(n - (a + b + 1)); _++) printf("%d ", r--);
  } else if (b > a) {
    for (int i = 0; i < int(a + b + 1); i++) {
      if (i & 1)
        printf("%d ", l++);
      else
        printf("%d ", r--);
    }
    for (int _ = 0; _ < int(n - (a + b + 1)); _++) printf("%d ", l++);
  } else {
    printf("%d ", 2);
    for (int i = 0; i < int(a + b); i++) {
      if (i & 1) {
        printf("%d ", l++);
        if (l == 2) l = 3;
      } else
        printf("%d ", r--);
    }
    for (int _ = 0; _ < int(n - (a + b + 1)); _++) {
      printf("%d ", l++);
      if (l == 2) l = 3;
    }
  }
  puts("");
}
int main() {
  cerr.precision(15);
  cout.precision(15);
  cerr << fixed;
  cout << fixed;
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    read();
    solve();
  }
}
