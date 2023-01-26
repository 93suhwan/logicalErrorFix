#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
vector<int> seg;
int seg_q(int num, int le, int ri, int x, int y) {
  if (y < le || ri < x)
    return 0;
  else if (x <= le && ri <= y) {
    return seg[num];
  }
  int mid = (le + ri) / 2;
  return seg_q(num * 2, le, mid, x, y) + seg_q(num * 2 + 1, mid + 1, ri, x, y);
}
int seg_u(int num, int le, int ri, int x) {
  if (x < le || ri < x)
    return seg[num];
  else if (x == le && le == ri)
    return ++seg[num];
  int mid = (le + ri) / 2;
  return seg[num] =
             seg_u(num * 2, le, mid, x) + seg_u(num * 2 + 1, mid + 1, ri, x);
}
void init() {}
void solve() {
  int n;
  cin >> n;
  seg = vector<int>(n * 4 + 4);
  long long cnt = 0;
  for (int i = 0; i < (int)(n); ++i) {
    int x;
    cin >> x;
    cnt += seg_q(1, 1, n, x + 1, n);
    seg_u(1, 1, n, x);
  }
  cout << (cnt % 2 ? "NO" : "YES") << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  init();
  int test_cases = 1;
  cin >> test_cases;
  while (test_cases--) {
    solve();
  }
  return 0;
}
