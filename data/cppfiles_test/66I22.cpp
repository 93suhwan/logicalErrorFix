#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
std::mt19937 rnd(
    std::chrono::high_resolution_clock::now().time_since_epoch().count());
template <typename T>
bool smin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool smax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
void solveEq(ll n, ll a, ll b, const std::string& dir1,
             const std::string& dir2) {
  assert(a == b);
  if (a == 0) {
    std::cout << n - 1 << '\n';
    return;
  }
  if (a == n - 1) {
    std::cout << 0 << '\n';
    return;
  }
  if (dir1 == "left") {
    if (dir1 == dir2) {
      std::cout << n - 1 << '\n';
    } else {
      std::cout << 0 << '\n';
    }
  } else {
    if (dir1 == dir2) {
      std::cout << 0 << '\n';
    } else {
      std::cout << n - 1 << '\n';
    }
  }
}
void solve() {
  ll n, a, b;
  std::string dir1, dir2;
  std::cin >> n >> a >> b >> dir1 >> dir2;
  if (a == b) {
    solveEq(n, a, b, dir1, dir2);
    return;
  }
  if (dir1 == dir2) {
    if (dir1 == "left") {
      if (a > b) {
        --a;
        std::swap(a, b);
        std::swap(dir1, dir2);
      }
      if (a == b) {
        solveEq(n, a, b, dir1, dir2);
        return;
      }
      b -= a;
      a = 0;
      dir1 = "right";
      ll x = (b + 1) / 2;
      a = b = x;
      solveEq(n, a, b, dir1, dir2);
      return;
    } else {
      if (a < b) {
        ++a;
        std::swap(a, b);
        std::swap(dir1, dir2);
      }
      if (a == b) {
        solveEq(n, a, b, dir1, dir2);
        return;
      }
      a += (n - 1 - b);
      b = n - 1;
      dir1 = "left";
      ll x = (n - 1 - b + 1) / 2;
      a = b = n - 1 - x;
      solveEq(n, a, b, dir1, dir2);
      return;
    }
  } else {
    if (a < b) {
      --b;
    }
    ll shit = (a + b) % 2;
    if (shit < 0) {
      shit += 2;
    }
    if (shit == 0) {
      std::cout << 0 << '\n';
    } else {
      std::cout << n - 1 << '\n';
    }
    return;
  }
}
void run() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
}
int main(void) {
  auto start = std::chrono::high_resolution_clock::now();
  run();
  auto end = std::chrono::high_resolution_clock::now();
  return 0;
}
