#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 61;
deque<int> findBinary(long long x) {
  deque<int> binary;
  for (int pos = 0; pos < 61 && (1LL << pos) <= x; pos++) {
    binary.push_back((x >> pos) & 1);
  }
  reverse(binary.begin(), binary.end());
  return binary;
}
bool compare(deque<int> x, deque<int> y) {
  for (int i : {0, 1}) {
    if (x == y) {
      ;
      ;
      return true;
    }
    reverse(x.begin(), x.end());
  }
  return false;
}
bool solve(deque<int>& bx, deque<int>& by) {
  for (int right = 0; right + (int)bx.size() < N; right++) {
    deque<int> cur = bx;
    for (int i = 0; i < right; i++) {
      cur.push_back(1);
    }
    if (compare(cur, by)) return true;
    while (cur.back() == 0) cur.pop_back();
    for (int left = 1; left + (int)cur.size() < N; left++) {
      cur.push_front(1);
      if (compare(cur, by)) return true;
    }
  }
  return false;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  deque<int> bx = findBinary(x), by = findBinary(y);
  ;
  ;
  if (solve(bx, by)) {
    cout << "YES\n";
    return;
  }
  while (bx.back() == 0) {
    bx.pop_back();
  }
  if (solve(bx, by))
    cout << "YES\n";
  else
    cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int TEST = 1;
  for (int i = 1; i <= TEST; i++) {
    solve();
  }
  return 0;
}
