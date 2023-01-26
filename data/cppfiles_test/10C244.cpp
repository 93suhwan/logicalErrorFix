#include <bits/stdc++.h>
using namespace std;
long long int fastpow(long long int a, long long int p) {
  long long int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * 1ll * a % 1000000007;
      p /= 2;
    } else {
      res = res * 1ll * a % 1000000007;
      p--;
    }
  }
  return res;
}
long long int fact(long long int n) {
  long long int res = 1;
  for (long long int i = 1; i <= n; i++) {
    res = res * 1ll * i % 1000000007;
  }
  return res;
}
long long int comb(long long int n, long long int k) {
  return fact(n) * 1ll * fastpow(fact(k), 1000000007 - 2) % 1000000007 * 1ll *
         fastpow(fact(n - k), 1000000007 - 2) % 1000000007;
}
long long int to_integer(string &aa) {
  long long int res = 0;
  for (auto x : aa) res = (res * 10) + (x - '0');
  return res;
}
bool prime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
void sieve(long long int n, vector<long long int> prime) {
  for (long long int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tt;
  cin >> tt;
  while (tt--) {
    long long int n, k;
    cin >> n >> k;
    map<long long int, vector<long long int> > pos;
    long long int cnt = 0;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      if (pos[x].size() < k) {
        pos[x].push_back(i);
        cnt++;
      }
    }
    cnt -= cnt % k;
    vector<long long int> ans(n);
    for (long long int i = 1; i <= cnt / k; i++) {
      long long int have = 0;
      while (have < k) {
        auto it = pos.begin();
        if (it->second.empty()) {
          pos.erase(it);
          continue;
        }
        have++;
        ans[it->second.back()] = have;
        it->second.pop_back();
      }
    }
    for (auto i : ans) {
      cout << i << ' ';
    }
    cout << "\n";
  }
}
