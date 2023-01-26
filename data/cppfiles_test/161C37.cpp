#include <bits/stdc++.h>
#pragma GCC target("avx2,avx,sse,sse2,ssse3")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int MX = 1e3;
int n;
set<pair<int, int> > inp;
void recur(int a, int b) {
  for (int i = a; i <= b; i++) {
    if ((a > i - 1 or inp.find({a, i - 1}) != inp.end()) and
        (i + 1 > b or inp.find({i + 1, b}) != inp.end())) {
      cout << a << ' ' << b << ' ' << i << '\n';
      if (a <= i - 1) recur(a, i - 1);
      if (i + 1 <= b) recur(i + 1, b);
    }
  }
}
void test() {
  cin >> n;
  inp.clear();
  for (int i = 0; i < (int)n; i++) {
    int a, b;
    cin >> a >> b;
    inp.insert(make_pair(a, b));
  }
  recur(1, n);
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) test();
  return 0;
}
