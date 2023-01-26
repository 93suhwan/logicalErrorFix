#include <bits/stdc++.h>
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T>
using MaxHeap = std::priority_queue<T>;
using ll = long long;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;
using Pdd = std::pair<double, double>;
template <class T>
bool chmin(T &a, const T b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}
template <class T>
bool chmax(T &a, const T b) {
  if (a < b) {
    a = b;
    return true;
  } else {
    return false;
  }
}
template <class T>
void vdeb(const std::vector<T> &da) {
  auto n = da.size();
  for (size_t i = 0; i < n; i++) {
    if (i == n - 1)
      std::cout << da[i];
    else
      std::cout << da[i] << " ";
  }
  std::cout << std::endl;
}
template <class T>
void vdeb(const std::vector<std::vector<T>> &da) {
  auto n = da.size();
  for (size_t i = 0; i < n; i++) {
    std::cout << i << " : ";
    vdeb(da[i]);
  }
}
template <>
void vdeb(const std::vector<std::string> &da) {
  auto n = da.size();
  for (size_t i = 0; i < n; i++) {
    std::cout << da[i] << std::endl;
  }
}
using namespace std;
const ll MOD = 1000000007;
ll modpow(ll x, ll k) {
  ll ret = 1, now = x;
  while (k) {
    if (k & 1) {
      ret *= now;
      ret %= MOD;
    }
    now = now * now % MOD;
    k >>= 1;
  }
  return ret;
}
int main() {
  ll n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  ll ax, ay, bx, by;
  cin >> ax >> ay >> bx >> by;
  cout << modpow(k, n * m - r * c) << endl;
}
