#include <bits/stdc++.h>
using namespace std;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  auto solve = [&]() {
    int n, k;
    cin >> n >> k;
    int c = (n + k - 1) / k;
    cout << c << '\n';
    for (int i = 0; i < n * (n - 1) / 2; i++) {
      cout << i % c + 1 << ' ';
    }
    cout << '\n';
  };
  solve();
  return 0;
}
