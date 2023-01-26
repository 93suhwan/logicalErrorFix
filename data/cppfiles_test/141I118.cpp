#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void printArray(vector<long long> &arr) {
  for (long long i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
void swap(long long &a, long long &b) {
  long long temp = a;
  a = b;
  b = temp;
}
long long isPrime(long long n) {
  vector<long long> prime(n + 1, true);
  for (long long i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (long long j = i * i; j <= n; j += i) {
        prime[j] = false;
      }
    }
  }
  long long x = 0;
  for (long long i = 2; i <= n; i++) {
    if (prime[i]) {
      x++;
    }
  }
  return x;
}
long long Factorial(long long n) {
  if (n == 1 || n == 0) return 1;
  return n * Factorial(n - 1);
}
void solve() {
  long long x, y;
  cin >> x >> y;
  string a = to_string(x);
  string s = to_string(y);
  if (s.size() < a.size()) {
    cout << -1 << "\n";
  }
  long long diff = s.size() - a.size();
  while (diff--) {
    a = "0" + a;
  }
  long long i = a.size() - 1;
  long long j = s.size() - 1;
  string ans = "";
  while (j >= 0) {
    long long temp1 = a[i] - '0';
    long long temp2 = s[j] - '0';
    if (temp1 <= temp2) {
      string d = to_string(temp2 - temp1);
      ans = d + ans;
      i--;
      j--;
    } else {
      if (s[j - 1] != '1') {
        cout << -1 << "\n";
        return;
      }
      string d = to_string((10 + temp2) - temp1);
      ans = d + ans;
      j -= 2;
      i--;
    }
  }
  long long res = 0;
  for (long long i = 0; i < ans.size(); i++) {
    res = res * 10 + (ans[i] - '0');
  }
  cout << res << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
