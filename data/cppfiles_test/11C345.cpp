#include <bits/stdc++.h>
using namespace std;
const long int mod = 1000000007;
const long int modulo = 998244353;
void print(std::vector<long long> &a) {
  for (long long i = 0; i < a.size(); i++) std::cout << a.at(i) << ' ';
}
void printr(std::vector<long long> &a) {
  for (long long i = a.size() - 1; i >= 0; i--) std::cout << a.at(i) << ' ';
}
void vinp(std::vector<long long> &a, long long n) {
  long long x;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
}
long long vsum(std::vector<long long> &a) {
  long long sum = 0;
  for (long long i = 0; i < a.size(); i++) sum += a.at(i);
  return sum;
}
long long power(int a, int b) {
  if (b == 0) return 1;
  if ((b % 2) == 0)
    return (power(a * a, b / 2)) % mod;
  else
    return ((a % mod) * power(a, b - 1) % mod) % mod;
}
long long MAXN = 1500000;
bool prime[1500001];
void SieveOfEratosthenes(int n) {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
bool mycomp(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.second > p2.second;
}
long long solve(vector<pair<long long, long long>> v) {
  long long n = v.size();
  sort(v.begin(), v.end(), mycomp);
  long long sum = 0;
  for (long long i = 0; i < (long long)(n); ++i) {
    sum += v[i].second;
  }
  if (sum < 0) {
    return n;
  } else {
    for (long long i = 0; i < n; i++) {
      sum -= v[i].second;
      if (sum < 0) {
        return (n - i - 1);
      }
    }
  }
  return 0;
}
void tests(vector<vector<long long>> v, long long n) {
  vector<vector<pair<long long, long long>>> arr(5);
  for (long long i = 0; i < (long long)(n); ++i) {
    long long sum = accumulate(v[i].begin(), v[i].end(), 0);
    for (long long j = 0; j < (long long)(5); ++j) {
      arr[j].push_back({v[i][j], sum - 2 * v[i][j]});
    }
  }
  long long ans = 0;
  for (long long i = 0; i < (long long)(5); ++i) {
    long long y = solve(arr[i]);
    ans = max(ans, y);
  }
  cout << ans;
  cout << "\n";
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<vector<long long>> v;
    for (long long i = 0; i < (long long)(n); ++i) {
      string s;
      cin >> s;
      map<char, int> mp;
      mp['a'] = 0;
      mp['b'] = 0;
      mp['c'] = 0;
      mp['d'] = 0;
      mp['e'] = 0;
      for (long long i = 0; i < (long long)(s.size()); ++i) {
        mp[s[i]]++;
      }
      vector<long long> tv;
      for (auto it : mp) {
        tv.push_back(it.second);
      }
      v.push_back(tv);
    }
    tests(v, n);
  }
  return 0;
}
