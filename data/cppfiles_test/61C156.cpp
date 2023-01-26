#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
int setBit(int num, int idx, int value = 1) {
  return (value) ? (num | (1 << idx)) : (num & ~(1 << idx));
}
int getBit(int num, int idx) { return ((num >> idx) & 1) == 1; }
int cntBits(int num) {
  int ret = 0;
  while (num) {
    if (num % 2) ret++;
    num /= 2;
  }
  return ret;
}
int is_prime[1000001];
void Sieve() {
  for (int i = 0; i <= 1000000; i++) {
    is_prime[i] = 1;
  }
  is_prime[0] = 0;
  is_prime[1] = 0;
  for (int i = 2; i * i <= 1000000; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= 1000000; j += i) {
        is_prime[j] = 0;
      }
    }
  }
}
vector<int> get_bin(int n) {
  vector<int> ret;
  while (n > 0) {
    if (n % 2 == 0)
      ret.push_back(0);
    else
      ret.push_back(1);
    n /= 2;
  }
  return ret;
}
unordered_map<long long, long long> factorise(long long n) {
  unordered_map<long long, long long> map;
  if (n % 2 == 0) {
    while (n % 2 == 0) {
      if (map.find(2) != map.end())
        map[2]++;
      else
        map[2] = 1;
      n = n / 2;
    }
  }
  for (long long i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      while (n % i == 0) {
        if (map.find(i) != map.end())
          map[i]++;
        else
          map[i] = 1;
        n = n / i;
      }
    }
  }
  if (n > 1) map[n] = 1;
  return map;
}
unsigned long long power(unsigned long long x, int y, int p) {
  unsigned long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<pair<long long, long long> > arr;
    map<long long, long long> mpa;
    map<long long, long long> mpb;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      arr.push_back({a, b});
      mpa[a]++;
      mpb[b]++;
    }
    long long ans = (n * (n - 1) * (n - 2)) / 6;
    for (auto &val : arr) {
      long long cand1 = mpa[val.first] - 1;
      long long cand2 = mpb[val.second] - 1;
      ans -= cand1 * cand2;
    }
    cout << ans << endl;
  }
  return 0;
}
