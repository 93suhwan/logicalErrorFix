#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> a(n);
  for (auto& [u, v] : a) cin >> u >> v;
  sort(a.begin(), a.end(), [&](pair<int, int> A, pair<int, int> B) {
    return max(A.first, A.second) == max(B.first, B.second)
               ? min(A.first, A.second) < min(B.first, B.second)
               : max(A.first, A.second) < max(B.first, B.second);
  });
  int cnt = 0;
  for (auto [u, v] : a) {
    if (u >= d) {
      cnt++;
      d = max(d, v);
    }
  }
  cout << cnt << '\n';
  return 0;
}
