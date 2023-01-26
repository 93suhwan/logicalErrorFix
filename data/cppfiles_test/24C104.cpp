#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
void solve() {
  int n;
  cin >> n;
  n++;
  cout << n / 10 << endl;
}
int main() {
  int tc;
  for (scanf("%d", &tc); tc--;) solve();
  return 0;
}
