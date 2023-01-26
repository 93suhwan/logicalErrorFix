#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 61;
vector<int> findBinary(long long x) {
  vector<int> binary;
  for (int pos = 0; pos < 61 && (1LL << pos) <= x; pos++) {
    binary.push_back((x >> pos) & 1);
  }
  reverse(binary.begin(), binary.end());
  return binary;
}
bool compare(vector<int> x, vector<int> y) {
  for (int i : {0, 1}) {
    if (x == y) return true;
    reverse(x.begin(), x.end());
  }
  return false;
}
bool solve(vector<int>& bx, vector<int>& by) {
  for (int left = 0; left + (int)bx.size() < N; left++) {
    vector<int> cur(left, 1);
    for (int b : bx) {
      cur.push_back(b);
    }
    if (compare(cur, by)) {
      return true;
    }
    for (int right = 1; right + (int)cur.size() < N; right++) {
      cur.push_back(1);
      if (compare(cur, by)) {
        return true;
      }
    }
  }
  return false;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  vector<int> bx = findBinary(x), by = findBinary(y);
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
