#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 3e5 + 5;
deque<int> findBinary(long long x) {
  deque<int> binary;
  for (int pos = 0; pos < 61 && (1LL << pos) <= x; pos++) {
    binary.push_back((x >> pos) & 1);
  }
  reverse(binary.begin(), binary.end());
  return binary;
}
bool comare(deque<int> a, deque<int> b) {
  if (a.size() < b.size()) return false;
  while (b.empty() == false) {
    if (a.empty() || (a.back() != -1 && b.back() != a.back())) return false;
    a.pop_back();
    b.pop_back();
  }
  while (a.empty() == false) {
    if (a.back() == 1) return false;
    a.pop_back();
  }
  return true;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << "YES\n";
    return;
  }
  bool chance = 0;
  deque<int> bx = findBinary(x), by = findBinary(y);
  for (int ops = 0; ops < 60; ops++) {
    ;
    if (chance)
      bx.push_back(-1);
    else
      bx.push_front(-1);
    chance ^= 1;
    ;
    if (chance) {
      reverse(bx.begin(), bx.end());
    }
    if (comare(bx, by)) {
      cout << "YES\n";
      return;
    }
  }
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
