#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 2;
std::vector<bool> prime(N, true);
std::vector<int> prefix_prime(N);
int powr(int x, int n, int d) {
  if (x == 0) return 0;
  if (n == 0) return 1;
  bool neg = false;
  if (x < 0) {
    neg = true;
    x = abs(x);
  }
  x = x % d;
  long long int ans = powr(x, n / 2, d);
  ans = (ans * ans) % d;
  if (n & 1) {
    ans = (ans * x) % d;
  }
  if (neg) {
    ans = (n & 1) ? (d - ans) : ans;
  }
  return (int)ans;
}
void sieve() {
  prime[0] = prime[1] = false;
  int i, j;
  for (int i = 2; i * i < N; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }
}
void pre() {
  int i, count = 0;
  for (i = 1; i <= N; i++) {
    if (prime[i]) {
      count++;
    }
    prefix_prime[i] = count;
  }
}
void SieveOfEratosthenes(int n) {
  int count = 0;
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int p = 2; p <= n; p++) {
    if (prime[p]) {
      cout << p << " ";
      count++;
    }
  }
}
int maxSumSubArray(int a[], int n) {
  int dp[n];
  int sum = INT_MIN;
  int temp = 0;
  for (int i = 0; i < n; i++) {
    temp = max(temp + a[i], a[i]);
    sum = max(sum, temp);
    dp[i] = temp;
  }
  return sum;
}
int getPrimes(int a, int b) {
  int count = 0;
  int i, j;
  if (a <= 2) {
    a = 2;
    if (b >= 2) {
      count++;
      a++;
    }
  }
  if (a % 2 == 0) a++;
  for (i = a; i <= b; i = i + 2) {
    bool flag = 1;
    for (j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) count++;
  }
  return count;
}
bool isPalindrome(int x) {
  if (x < 0) {
    return false;
  }
  string a = to_string(x);
  long n = a.length();
  reverse(a.begin(), a.end());
  long y = stol(a);
  if (x == y) {
    return true;
  }
  return false;
}
unsigned long long nCr(unsigned long long n, unsigned long long r) {
  if (n <= 0 || r > n) {
    return 0;
  }
  unsigned long long ans = 1;
  unsigned long long m = n;
  for (int i = 1; i <= r; i++) {
    ans *= (m - i + 1);
    ans /= i;
  }
  return ans;
}
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void salvatore() {
  int n;
  cin >> n;
  vector<string> a(n - 2);
  for (int i = 0; i < n - 2; i++) cin >> a[i];
  string ans = "";
  ans += a[0][0];
  for (int i = 0; i < n - 3; i++) {
    if (a[i][1] == a[i + 1][0])
      ans += a[i][1];
    else {
      ans += a[i][1];
      ans += a[i + 1][0];
    }
  }
  ans += a[n - 3][1];
  if (ans.length() < n) ans += 'a';
  cout << ans << endl;
}
int main() {
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc;
  cin >> tc;
  bool gglkstrt = false;
  for (int t = 1; t <= tc; t++) {
    if (gglkstrt) cout << "Case #" << t << ": ";
    salvatore();
  }
  return 0;
}
