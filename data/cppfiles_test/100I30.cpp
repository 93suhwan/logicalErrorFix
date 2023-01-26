#include <bits/stdc++.h>
using namespace std;
const long long int N = 1000001;
long long int factorialNumInverse[N + 1];
long long int naturalNumInverse[N + 1];
long long int spf[N + 1];
long long int fact[N + 1];
vector<long long int> z_function(string s) {
  long long int n = (long long int)s.length();
  vector<long long int> z(n);
  for (long long int i = 1; i < n; ++i)
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
  return z;
}
int maxSubArraySum(int a[], int size) {
  int max_so_far = INT_MIN, max_ending_here = 0;
  for (int i = 0; i < size; i++) {
    max_ending_here = max_ending_here + a[i];
    if (max_so_far < max_ending_here) max_so_far = max_ending_here;
    if (max_ending_here < 0) max_ending_here = 0;
  }
  return max_so_far;
}
vector<long long int> SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  vector<long long int> v;
  for (int p = 2; p <= n; p++)
    if (prime[p]) v.push_back(p);
  return v;
}
void sieve() {
  spf[1] = 1;
  for (int i = 2; i < N; i++) spf[i] = i;
  for (int i = 4; i < N; i += 2) spf[i] = 2;
  for (int i = 3; i * i < N; i++) {
    if (spf[i] == i) {
      for (int j = i * i; j < N; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
vector<int> getFactorization(int x) {
  vector<int> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}
void InverseofNumber() {
  naturalNumInverse[0] = naturalNumInverse[1] = 1;
  for (long long int i = 2; i <= N; i++)
    naturalNumInverse[i] = naturalNumInverse[998244353 % i] *
                           (998244353 - 998244353 / i) % 998244353;
}
void InverseofFactorial() {
  factorialNumInverse[0] = factorialNumInverse[1] = 1;
  for (long long int i = 2; i <= N; i++)
    factorialNumInverse[i] =
        (naturalNumInverse[i] * factorialNumInverse[i - 1]) % 998244353;
}
void factorial() {
  fact[0] = 1;
  for (long long int i = 1; i <= N; i++) {
    fact[i] = (fact[i - 1] * i) % 998244353;
  }
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int t = power(a, b / 2) % 998244353;
  long long int x = ((t % 998244353) * (t % 998244353)) % 998244353;
  if (b % 2) x = ((x % 998244353) * (a % 998244353)) % 998244353;
  return x;
}
long long int inverse(long long int x) { return power(x, 998244353 - 2); }
long long int nCr(long long int n, long long int r) {
  long long int ans = ((fact[n] * factorialNumInverse[r]) % 998244353 *
                       factorialNumInverse[n - r]) %
                      998244353;
  return ans;
}
long long int nPr(long long int n, long long int r) {
  return (fact[n] * factorialNumInverse[n - r]) % 998244353;
}
long long int getparent(long long int a, vector<long long int> &parent) {
  return parent[a] = (parent[a] == a ? a : getparent(parent[a], parent));
}
void getunion(long long int a, long long int b, vector<long long int> &parent,
              vector<long long int> &ranking) {
  a = getparent(a, parent);
  b = getparent(b, parent);
  if (ranking[b] == ranking[a]) {
    parent[b] = a;
    ranking[a]++;
  } else if (ranking[b] > ranking[a]) {
    parent[a] = b;
  } else {
    parent[b] = a;
  }
}
long long int bintodec(string s) {
  long long int sum = 0;
  reverse(s.begin(), s.end());
  for (long long int i = 0; i < s.length(); i++) {
    sum += (s[i] == '1' ? pow(2, i) : 0);
  }
  return sum;
}
string dectobin(long long int n) {
  string s;
  while (n > 0) {
    if ((n & 1))
      s.push_back('1');
    else
      s.push_back('0');
    n = (n >> 1);
  }
  reverse(s.begin(), s.end());
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  InverseofNumber();
  InverseofFactorial();
  factorial();
  sieve();
  long long int t, n, i, x, y, m, p, q, sum, ans, cnt, mx, mn, j, k;
  cin >> t;
  while (t--) {
    sum = 0;
    cnt = 0;
    ans = 0;
    mx = INT_MIN;
    mn = 1e18;
    cin >> n;
    vector<long long int> a(n);
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    x = a[n - 1] - a[n - 2];
    if (x >= 2) {
      cout << 0 << "\n";
      continue;
    }
    if (x == 0) {
      cout << fact[n] << "\n";
      continue;
    }
    for (i = 0; i < n; i++) {
      if (a[i] == a[n - 2]) sum++;
    }
    ans = fact[n];
    for (i = 1; i <= n - sum; i++) {
      ans =
          (ans - (fact[n - i] * fact[(i == 1 ? 0 : n - sum - 1)]) % 998244353 +
           998244353) %
          998244353;
    }
    cout << ans << "\n";
  }
}
