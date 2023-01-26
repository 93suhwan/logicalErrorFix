#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
pair<int, int> calc(int a, int b) {
  if (a <= b) return {a, 0};
  int r = a / b;
  if (a % b == 0) return {b, r - 1};
  return {a / (r + 1), r};
}
vector<pair<int, int>> compact(const vector<pair<int, int>>& V) {
  vector<pair<int, int>> R;
  int p = -1, c = 0;
  for (auto [a, b] : V) {
    if (a != p && p != -1) {
      R.emplace_back(p, c);
      c = 0;
    }
    p = a;
    c += b;
  }
  R.emplace_back(p, c);
  return R;
}
int main() {
  ios_base::sync_with_stdio(false);
  int tn;
  cin >> tn;
  for (int ti = 0; ti < tn; ++ti) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int& a : A) cin >> a;
    vector<pair<int, int>> B;
    uint64_t r = 0;
    for (int i = n - 1; i > 0; --i) {
      B.emplace_back(A[i], 1);
      vector<pair<int, int>> C;
      for (auto [x, y] : B) {
        auto [z, t] = calc(A[i - 1], x);
        C.emplace_back(z, y);
        r = (r + 1ull * t * i * y) % MOD;
      }
      sort(C.begin(), C.end());
      B = compact(C);
    }
    cout << r << endl;
  }
  return 0;
}
