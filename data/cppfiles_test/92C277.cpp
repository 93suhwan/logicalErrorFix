#include <bits/stdc++.h>
using namespace std;
double pi = 2 * acos(0.0);
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
bool isPalindrome(string str) {
  int l = 0;
  int h = str.length() - 1;
  while (h > l) {
    if (str[l++] != str[h--]) {
      return false;
    }
  }
  return true;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
long long int M = 1000000007;
long long int power(long long int b, long long int x) {
  if (x == 0) return 1;
  long long int y = power(b, x / 2) % M;
  long long int z = ((y % M) * (y % M)) % M;
  return (x % 2 == 1) ? b * z : z;
}
string lexiStr(string a, string b) {
  for (long long int i = 0; i < a.length(); i++) {
    if (a[i] < b[i]) return a;
    if (a[i] > b[i]) return b;
  }
  return a;
}
long long int primeFactors(long long int n) {
  long long int mini = INT_MAX;
  long long int c = 0;
  while (n % 2 == 0) {
    c++;
    long long int x = 2;
    mini = min(x, mini);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      c++;
      long long int x = i;
      mini = min(x, mini);
      n = n / i;
    }
  }
  if (n > 2) {
    mini = min(n, mini);
    c++;
  }
  return mini;
}
vector<long long int> factors;
long long int totalFactors(long long int n) {
  long long int c = 0;
  for (long long int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i) {
        c++;
        factors.push_back(i);
      } else {
        factors.push_back(i);
        factors.push_back(n / i);
        c++;
        c++;
      }
    }
  }
  return c;
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return (a.first < b.first);
}
int isKthBitSet(int n, int k) {
  if (n < 0)
    return 0;
  else if (n & (1 << (k - 1)))
    return 1;
  else
    return 0;
}
bool isPresent(int n, int d) {
  while (n > 0) {
    if (n % 10 == d) return true;
    n /= 10;
  }
  return false;
}
int getans(long long int r) {
  long long int e = log2(r);
  long long int ans = e * (e - 1) / 2;
  e = pow(2, e);
  for (long long int i = e; i <= r; i++) {
    long long int x = i;
    long long int c = 0;
    while (x > 0) {
      if (x % 2 == 0) c++;
      x /= 2;
    }
    if (c == 1) {
      ans++;
    }
  }
  return ans;
}
int solve() {
  string s;
  cin >> s;
  long long int n = s.length();
  long long int ab = 0;
  long long int ba = 0;
  for (long long int i = 0; i < n - 1; i++) {
    if (s[i] == 'a' && s[i + 1] == 'b') ab++;
    if (s[i] == 'b' && s[i + 1] == 'a') ba++;
  }
  if (ab == ba)
    cout << s;
  else {
    if (s[0] == 'a')
      cout << 'b';
    else
      cout << 'a';
    for (long long int i = 0; i < n - 1; i++) {
      cout << s[i + 1];
    }
  }
  cout << endl;
  return 0;
}
int main() {
  init_code();
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
