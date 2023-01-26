#include <bits/stdc++.h>
std::vector<int> readVector(int n) {
  std::vector<int> v(n);
  for (auto &x : v) {
    std::cin >> x;
  }
  return v;
}
void printVector(std::vector<int> v) {
  for (auto &i : v) std::cout << i << " ";
  std::cout << "\n";
}
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v = readVector(n);
  int mx = *max_element((v).begin(), (v).end()), ans = 0, el = v[n - 1];
  for (int i = n - 1; i >= 0; i--) {
    if (el < v[i]) {
      el = max(el, v[i]);
      ans++;
    }
    if (mx == el) {
      break;
    }
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  auto start = std::chrono::high_resolution_clock::now();
  int t = 1;
  cin >> t;
  while (t--) solve();
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  return 0;
}
