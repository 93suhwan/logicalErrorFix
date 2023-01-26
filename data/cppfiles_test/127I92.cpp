#include <bits/stdc++.h>
using namespace std;
const long long mxN = 1e5;
long long isprime(long long n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return 0;
  return 1;
}
bool isperfect(long long n) {
  if (n >= 0) {
    long long a = sqrt(n);
    return (a * a == n);
  }
  return false;
}
long long power(long long a, long long n) {
  if (n == 0) return 1;
  if (n == 1) return a;
  if (n & 1)
    return (a % 1000000007 * power(a, n - 1) % 1000000007) % 1000000007;
  else
    return power((a * a) % 1000000007, n / 2) % 1000000007;
}
bool sortbysecond(const pair<long long, long long> &a,
                  const pair<long long, long long> &b) {
  return (a.second < b.second);
}
void AMAN_PANDEY() {
  string s, t;
  cin >> s >> t;
  sort((s).begin(), (s).end());
  while (1) {
    long long j = 0;
    long long f = 0;
    long long pos = -1;
    for (long long i = 0; i < (long long)s.size(); i++) {
      if (s[i] == t[j]) {
        j++;
      }
    }
    if (j < (long long)t.size()) {
      cout << s << '\n';
      return;
    }
    for (long long i = 0; i < (long long)s.size(); i++) {
      if (s[i] == t[(long long)t.size() - 1]) {
        pos = i;
        f = 1;
        break;
      }
    }
    if (f && pos > 0) {
      char ch = s[pos];
      s[pos] = s[pos - 1];
      s[pos - 1] = ch;
    } else {
      break;
    }
  }
  cout << s;
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long x = 1;
  cin >> x;
  while (x--) {
    AMAN_PANDEY();
  }
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << " ms\n";
  return 0;
}
