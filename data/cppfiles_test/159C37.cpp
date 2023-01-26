#include <bits/stdc++.h>
using namespace std;
constexpr long long MOD = 998244353;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  long long n;
  cin >> n;
  auto is_sq = [&](long long x) {
    return (long long)sqrt(x) * (long long)sqrt(x) == x;
  };
  auto get_wont = [&]() -> vector<long long> {
    if (n % 4 == 0)
      return {n / 2};
    else if (n == 1)
      return {};
    else if (n % 4 == 1) {
      return {n / 2, n};
    } else if (n % 4 == 2) {
      if (is_sq(n + 2))
        return {n / 2 + 1};
      else if (is_sq(n * (n / 2 + 1)))
        return {n / 2 - 2};
      else
        return {n / 2, 2};
    } else {
      if (is_sq(n + 1))
        return {n / 2 + 1, n};
      else if (is_sq(2 * (n / 2) * (n / 2 - 1)))
        return {n / 2 - 2, n};
      else if (is_sq((n / 2 - 1) * n))
        return {n / 2 - 2, n - 2};
      else
        return {2, n / 2, n};
    }
  };
  auto wont = get_wont();
  cout << n - wont.size() << "\n";
  for (int i = 1; i <= n; i++)
    if (find(wont.begin(), wont.end(), i) == wont.end()) cout << i << " ";
  cout << "\n";
}
