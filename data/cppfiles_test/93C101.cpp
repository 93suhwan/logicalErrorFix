#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
bool isprime(long long num) {
  for (long long i = 2; i * i <= num; ++i) {
    if (num % i == 0) return false;
  }
  return true;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return ((a / gcd(a, b)) * b); }
long long cel(long long x1, long long y1) {
  if ((x1) <= 0) return (x1) / (y1);
  return (((x1) / (y1)) + (((x1) % (y1)) != 0));
}
void swap(long long int &a, long long int &b) {
  a = a ^ b;
  b ^= a;
  a ^= b;
}
void givesubsequence(string s) {
  int n = s.size();
  int numberofsubsequence = (1 << n) - 1;
  for (int i = 1; i <= numberofsubsequence; i++) {
    int temp = i, j = 0;
    while (temp > 0) {
      if (temp & 1) cout << s[j];
      j++;
      temp = temp >> 1;
    }
    cout << endl;
  }
}
float squareRoot(float n) {
  float x = n;
  float y = 1;
  float e = 0.000001;
  while (x - y > e) {
    x = (x + y) / 2;
    y = n / x;
  }
  return x;
}
int power(int x, unsigned int y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}
int sum_of_digits(long long n) {
  int res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}
const int N = 3e5 + 2;
int xo[N];
void presolve() {
  for (int i = 1; i < N; i++) xo[i] = i ^ xo[i - 1];
}
void solve(int test_case) {
  int a, b;
  cin >> a >> b;
  int ans = a, x = xo[a - 1];
  int y = x ^ b;
  if (x == b)
    cout << ans << endl;
  else if (y != a)
    cout << ans + 1 << endl;
  else
    cout << ans + 2 << endl;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  clock_t start, end;
  start = clock();
  int tc = 1;
  presolve();
  cin >> tc;
  while (tc--) {
    solve(tc);
  }
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  return 0;
}
