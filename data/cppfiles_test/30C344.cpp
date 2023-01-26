#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio();
  cin.tie(NULL);
}
vector<bool> is_prime;
vector<long long> seive(long long n) {
  vector<bool> ip(n + 1, true);
  for (long long i = 2; i * i < n; i++) {
    if (ip[i] == true) {
      for (long long j = i * i; j <= n; j += i) {
        ip[j] = false;
      }
    }
  }
  is_prime = ip;
  vector<long long> primes;
  primes.push_back(1);
  for (long long i = 2; i < ip.size(); i++) {
    if (ip[i] == true) primes.push_back(i);
  }
  return primes;
}
vector<long long> seg_seive(long long l, long long r) {
  long long root = (long long)sqrt(r);
  vector<long long> primes = seive(root);
  vector<bool> ip((r - l + 1), true);
  for (long long i = 1; i < primes.size(); i++) {
    long long base = (l / primes[i]) * primes[i];
    if (base < l) base += primes[i];
    for (long long j = base; j <= r; j += primes[i]) {
      ip[j - l] = false;
    }
  }
  vector<long long> seg_primes;
  for (long long i = 0; i < ip.size(); i++) {
    if (ip[i] == true) seg_primes.push_back(i + l);
  }
  return seg_primes;
}
vector<long long> range_prefix_sum(vector<bool> ip) {
  vector<long long> ps((long long)ps.size());
  ps[0] = 1;
  for (long long i = 1; i <= ps.size(); i++) {
    ps[i] = ps[i - 1] + ip[i];
  }
  return ps;
}
string give_binary(long long n) {
  if (n == 0) {
    return "0";
  }
  if (n % 2 == 0) {
    string s = give_binary(n / 2);
    s += "0";
    return s;
  }
  string s = give_binary(n - 1);
  s[s.length() - 1] = '1';
  return s;
}
void Solve(long long n, string& s) {
  set<char> alpha;
  long long ans = 1000000000;
  for (long long i = 0; i < n; i++) {
    alpha.insert(s[i]);
  }
  for (char c : alpha) {
    bool f = true;
    long long cnt = 0;
    long long i = 0;
    long long j = n - 1;
    while (i <= j) {
      if (s[i] == s[j]) {
        i++;
        j--;
      } else if (s[i] == c) {
        i++;
        cnt++;
      } else if (s[j] == c) {
        j--;
        cnt++;
      } else {
        f = false;
        break;
      }
    }
    if (f) ans = min(ans, cnt);
  }
  if (ans != 1000000000)
    cout << ans << "\n";
  else
    cout << -1 << "\n";
  return;
}
int main() {
  fastio();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    Solve(n, s);
  }
  return 0;
}
