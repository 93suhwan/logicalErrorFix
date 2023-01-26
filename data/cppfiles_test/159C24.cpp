#include <bits/stdc++.h>
using namespace std;
uint64_t rand_uint64(void) {
  uint64_t r = 0;
  for (int i = 0; i < 64; i += 15) {
    r = r * ((uint64_t)RAND_MAX + 1) + rand();
  }
  return r;
}
int main() {
  int n;
  cin >> n;
  vector<long long> primes;
  primes.push_back(2);
  for (int i = 3; i <= n; i++) {
    bool p = true;
    for (int j = 0; primes[j] * primes[j] <= i; j++) {
      if (i % primes[j] == 0) {
        p = false;
        break;
      }
    }
    if (p) {
      primes.push_back(i);
    }
  }
  set<uint64_t> taken;
  map<int, uint64_t> mapping;
  for (int i = 0; i < primes.size(); ++i) {
    while (true) {
      uint64_t rnd = rand_uint64();
      if (taken.find(rnd) == taken.end()) {
        mapping[primes[i]] = rnd;
        break;
      }
    }
  }
  uint64_t x = 0;
  uint64_t tx = 0;
  vector<uint64_t> xs(n + 1);
  for (int i = 2; i <= n; ++i) {
    int res = i;
    for (int j = 0; primes[j] * primes[j] <= i; j++) {
      while (res % primes[j] == 0) {
        tx ^= mapping[primes[j]];
        res /= primes[j];
      }
    }
    if (res > 1) {
      tx ^= mapping[res];
    }
    xs[i] = tx;
    x ^= tx;
  }
  if (x == 0) {
    cout << n;
    for (int i = 1; i <= n; ++i) {
      cout << " " << i << endl;
    }
    cout << endl;
    return 0;
  } else {
    map<uint64_t, int> list;
    for (int i = 2; i <= n; ++i) {
      if ((x ^ xs[i]) == 0) {
        cout << n - 1;
        for (int j = 1; j <= n; ++j)
          if (i != j) {
            cout << " " << j;
          }
        cout << endl;
        return 0;
      }
      list[x ^ xs[i]] = i;
    }
    for (int i = 2; i <= n; ++i) {
      if (list.find(xs[i]) != list.end()) {
        cout << n - 2;
        int exc = list[xs[i]];
        for (int j = 1; j <= n; ++j)
          if (j != exc && j != i) {
            cout << " " << j;
          }
        cout << endl;
        return 0;
      }
    }
    cout << n - 3;
    for (int i = 1; i <= n; ++i)
      if (i != 2 && i != (n - 1) / 2 && i != n) {
        cout << " " << i;
      }
    cout << endl;
  }
  return 0;
}
