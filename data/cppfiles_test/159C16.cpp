#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }
  vector<unsigned long long> primes;
  vector<unsigned long long> is_composite(n + 1);
  for (int i = 2; i <= n; i++) {
    if (!is_composite[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j <= n; j += i) {
        if (!is_composite[j]) is_composite[j] = i;
      }
    }
  }
  int primenum = primes.size();
  vector<unsigned long long> hashes(n + 1);
  mt19937_64 rng(
      (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 0; i < primenum; i++) {
    unsigned long long cur = primes[i];
    hashes[cur] = rng();
  }
  for (int i = 4; i <= n; i++) {
    if (is_composite[i]) {
      hashes[i] = hashes[i / (is_composite[i])] ^ hashes[is_composite[i]];
    }
  }
  vector<unsigned long long> factorial(n + 1);
  for (int i = 0; i < n; i++) {
    factorial[i + 1] = (factorial[i] ^ hashes[i + 1]);
  }
  unsigned long long factproduct = 0;
  for (int i = 1; i <= n; i++) {
    factproduct ^= factorial[i];
  }
  int res = -1;
  vector<pair<unsigned long long, int>> partial(n + 1);
  for (int i = 1; i <= n; i++) {
    if ((factorial[i]) == factproduct) {
      res = i;
      break;
    }
    partial[i] = make_pair((factorial[i] ^ factproduct), i);
  }
  if (res != -1) {
    cout << n - 1 << endl;
    for (int i = 1; i <= n; i++) {
      if (i == res) continue;
      cout << i << " ";
    }
    cout << endl;
    return 0;
  }
  sort(partial.begin(), partial.end());
  int res1 = -1;
  for (int i = 1; i <= n; i++) {
    auto iter = lower_bound(partial.begin() + 1, partial.end(),
                            make_pair(factorial[i], 0));
    if (iter == partial.end() || (iter->second == (int)i)) continue;
    if (iter->first == factorial[i]) {
      res = i;
      res1 = iter->second;
      break;
    }
  }
  if (res != -1) {
    cout << n - 2 << endl;
    for (int i = 1; i <= n; i++) {
      if (i == res || i == res1) continue;
      cout << i << " ";
    }
    cout << endl;
  } else {
    cout << n - 3 << endl;
    for (int i = 1; i < n; i++) {
      if (i == 2 || i == n / 2) continue;
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
