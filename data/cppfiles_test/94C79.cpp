#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000 * 1000 * 1000 + 7;
const long long int INF = 1ll * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7;
const long long int MOD2 = 998244353;
const long double PI = 3.141592653589793;
long long int gcd(long long int a, long long int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int power1(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int max(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int min(long long int a, long long int b) {
  if (a > b) return b;
  return a;
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return a.second < b.second;
}
vector<long long int> prime;
bool val[500];
void sieve() {
  memset(val, true, sizeof(val));
  val[1] = false;
  val[0] = false;
  for (long long int i = 2 * 2; i <= 500; i += 2) {
    val[i] = false;
  }
  for (long long int i = 3; i <= 500; i++) {
    if (val[i] == false) continue;
    for (long long int j = i * i; j <= 500; j += i) {
      val[j] = false;
    }
  }
  for (int i = 0; i <= 500; i++) {
    if (val[i] == true) {
      prime.push_back(i);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int arr[n];
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (n == 1) {
      cout << k + 1 << "\n";
      continue;
    }
    if (k < 9) {
      cout << k + 1 << "\n";
      continue;
    }
    long long int ans = 0;
    long long int flag = 0;
    long long int count = 0;
    long long int count1 = 0;
    for (long long int i = 1; i < n; i++) {
      long long int num = power1(10, arr[i]) - 1;
      count = 0;
      for (long long int j = i - 1; j >= 0; j--) {
        count += num / power1(10, arr[j]);
        num -= ((num / power1(10, arr[j])) * power1(10, arr[j]));
      }
      if (count > k) {
        cout << power1(10, arr[i - 1]) * (k - count1 + 1) +
                    power1(10, arr[i - 1]) - 1
             << "\n";
        flag = 1;
        break;
      }
      count1 = count;
    }
    if (flag == 0) {
      cout << (power1(10, arr[n - 1]) - 1) +
                  power1(10, arr[n - 1]) * (k - count1 + 1)
           << "\n";
    }
  }
  return 0;
}
