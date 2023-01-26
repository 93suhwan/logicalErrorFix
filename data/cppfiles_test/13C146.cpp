#include <bits/stdc++.h>
using namespace std;
inline int add(int a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
  return a;
}
inline int mul(int a, int b) { return (a * 1ll * b) % 1000000007; }
inline long long int power(long long int a, long long int b) {
  long long int rt = 1;
  while (b > 0) {
    if (b & 1) rt = mul(rt, a);
    a = mul(a, a);
    b >>= 1;
  }
  return rt;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
inline bool prime(long long int n) {
  if (n == 1) return false;
  if (n == 2) return true;
  long long int i;
  for (long long int i = 2; i < sqrt(n) + 1; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
vector<long long int> primeFactors(long long int n) {
  vector<long long int> ans;
  while (n % 2 == 0) {
    ans.push_back(2);
    n = n / 2;
  }
  for (long long int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      ans.push_back(i);
      n = n / i;
    }
  }
  if (n > 2) ans.push_back(n);
  return ans;
}
vector<long long int> marked(10000001, 1);
inline vector<long long int> all_primes(long long int n) {
  marked[0] = 0;
  marked[1] = 0;
  for (long long int i = 2; i <= n; i++) {
    if (marked[i]) {
      for (long long int j = i * i; j <= n; j += i) {
        marked[j] = 0;
      }
    }
  }
  vector<long long int> v;
  for (long long int i = 0; i <= n; i++) {
    if (marked[i]) v.push_back(i);
  }
  return v;
}
bool isPower2(long long int n) {
  if (n == 0) return 0;
  if ((n & (~(n - 1))) == n) return 1;
  return 0;
}
string decToBin(long long int n) {
  string s = "";
  long long int cnt = 0;
  while (n > 0) {
    s += to_string(n % 2);
    n = n / 2;
    cnt++;
  }
  reverse(s.begin(), s.end());
  return s;
}
bool comp(pair<long long int, long long int> &p1,
          pair<long long int, long long int> &p2) {
  return p1.second < p2.second;
}
vector<long long int> v;
void init() {
  for (long long int i = 1; i <= 100000; i++) {
    long long int t = (i * (i + 1)) / 2;
    v.push_back(t);
  }
}
void solve() {
  string s;
  long long int a = 0, b = 0, c = 0;
  cin >> s;
  for (auto x : s) {
    if (x == 'A')
      a++;
    else if (x == 'B')
      b++;
    else if (x == 'C')
      c++;
  }
  if (b == (a + c)) {
    cout << "YES"
         << "\n";
  } else
    cout << "NO"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  init();
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
