#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
bool uin(T& a, const T& b) {
  return a > b ? a = b, true : false;
}
template <class T>
bool uax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> solve() {
  int n;
  cin >> n;
  vector<ll> hsh(n + 1);
  for (auto& x : hsh) x = rng();
  vector<ll> hf(n + 1);
  {
    vector<short> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; ++i) {
      if (!prime[i]) continue;
      for (int j = i; j <= n; j += i) {
        for (int x = j; x % i == 0; x /= i) hf[j] ^= hsh[i];
        prime[j] = false;
      }
    }
    for (int i = 2; i <= n; ++i) hf[i] ^= hf[i - 1];
    assert(hf[0] == 0);
  }
  auto barring = [&](vector<int> v) -> vector<int> {
    sort(begin(v), end(v));
    vector<int> res;
    res.reserve(n);
    for (int i = 1; i <= n; ++i)
      if (!binary_search(begin(v), end(v), i)) res.push_back(i);
    return res;
  };
  int k = n / 4;
  if (n == 4 * k) return barring({2 * k});
  if (n == 4 * k + 1) {
    auto it = find(begin(hf), end(hf), hf[2 * k] ^ hf[4 * k + 1]);
    if (it != end(hf)) return barring({int(it - begin(hf))});
    return barring({2 * k, 4 * k + 1});
  }
  if (n == 4 * k + 2) {
    auto target = hf[2 * k + 1] ^ hsh[2];
    auto it = find(begin(hf), end(hf), target);
    if (it != end(hf)) return barring({int(it - begin(hf))});
    map<ll, int> mp;
    for (int i = 1; i <= n; ++i) {
      auto it = mp.find(hf[i] ^ target);
      if (it != end(mp)) return barring({i, it->second});
      mp[hf[i]] = i;
    }
    return barring({2 * k, 4 * k + 1, 4 * k + 2});
  }
  assert(n == 4 * k + 3);
  auto target = hf[2 * k + 1] ^ hf[4 * k + 3] ^ hsh[2];
  auto it = find(begin(hf), end(hf), target);
  if (it != end(hf)) return barring({int(it - begin(hf))});
  map<ll, int> mp;
  for (int i = 1; i <= n; ++i) {
    auto it = mp.find(hf[i] ^ target);
    if (it != end(mp)) return barring({i, it->second});
    mp[hf[i]] = i;
  }
  return barring({2 * k, 4 * k + 1, 4 * k + 2, 4 * k + 3});
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto v = solve();
  cout << int((v).size()) << '\n';
  for (auto x : v) cout << x << ' ';
  cout << '\n';
}
