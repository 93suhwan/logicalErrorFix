#include <bits/stdc++.h>
using namespace std;
const int nmax = 200010, mod = 1e9 + 7, inf = INT_MAX;
int mas[nmax] = {0};
set<int> st;
void fun(int a, int b, int v1, int p1) {
  if (v1 > a) return;
  int vp1, br1, w1, w2, p2;
  vp1 = v1;
  br1 = p1 - v1;
  w1 = v1;
  w2 = br1;
  if (w2 > b) return;
  p2 = a + b - p1;
  int br2 = a - w1;
  w1 += br2;
  w2 += p2 - br2;
  if (w1 != a || w2 != b) return;
  st.insert(br1 + br2);
  return;
}
void solve() {
  int a, b, p1, p2;
  st.clear();
  cin >> a >> b;
  p1 = (a + b) / 2;
  p2 = (a + b + 1) / 2;
  for (int i = 0; i <= p1; i++) fun(a, b, i, p1);
  for (int i = 0; i <= p2; i++) fun(a, b, i, p2);
  cout << st.size() << "\n";
  for (int i : st) cout << i << " ";
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
