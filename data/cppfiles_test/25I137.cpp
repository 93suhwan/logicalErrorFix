#include <bits/stdc++.h>
using namespace std;
const long long int N = 200005;
long long int fast_pow(long long int a, long long int p) {
  long long int res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = (a * a) % 1000000007;
      p /= 2;
    } else {
      res = (res * a) % 1000000007;
      p--;
    }
  }
  return res;
}
long long int ask(long long int l, long long int r) {
  if (l >= r) return -1;
  long long int ans = -1;
  cout << "? " << l << " " << r << '\n';
  cin >> ans;
  return ans;
}
bool comp(pair<long long int, long long int> p1,
          pair<long long int, long long int> p2) {
  if (p1.first == p2.first) {
    return p2.second <= p1.second;
  } else
    return p1.first < p2.first;
}
bool comp(vector<long long int> &a, vector<long long int> &b) {
  return a.size() > b.size();
}
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
vector<long long int> primes;
const long long int x = 1e6 + 1;
vector<bool> isprime(x, true);
void sieve() {
  isprime[1] = false;
  for (long long int i = 2; i * i < x; i++) {
    if (isprime[i]) {
      for (long long int j = 2 * i; j < x; j += i) {
        isprime[j] = false;
      }
    }
  }
  for (long long int i = 2; i < x; i++) {
    if (isprime[i]) primes.push_back(i);
  }
}
long long int count(long long int n) {
  long long int ans = 0;
  for (long long int i = 0; primes[i] * primes[i] <= n; i++) {
    while (n % primes[i] == 0) {
      n /= primes[i];
      ans++;
    }
  }
  if (n > 1) ans++;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    string a, b;
    cin >> a >> b;
    n = a.size();
    map<string, long long int> mp;
    long long int k = 0;
    for (k = 0; k < n; k++) {
      if (a[k] == b[0]) break;
    }
    string s = "";
    for (long long int i = k; i < n; i++) {
      s += a[i];
      string d = s;
      for (long long int j = i; j >= 0; j--) {
        if (j != i) d += a[j];
        mp[d]++;
      }
    }
    if (mp[b] != 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
