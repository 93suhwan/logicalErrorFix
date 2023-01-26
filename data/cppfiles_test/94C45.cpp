#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
int countSetBits(int n) {
  if (n == 0)
    return 0;
  else
    return (n & 1) + countSetBits(n >> 1);
}
long long int factorial(long long int n) {
  if (n == 0) return 1;
  return (n * factorial(n - 1));
}
bool is_palindrom_number(long long int n) {
  long long int num, digit, rev = 0;
  num = n;
  while (num != 0) {
    digit = num % 10;
    rev = (rev * 10) + digit;
    num /= 10;
  }
  return (num == n ? true : false);
}
void SieveOfEratosthenes(int n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
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
int removeZeros(int num) {
  int ret = 0;
  int ten = 1;
  while (num) {
    int dig = num % 10;
    num /= 10;
    if (dig) {
      ret += dig * ten;
      ten *= 10;
    }
  }
  return ret;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
void dfs(vector<int> &ans, vector<vector<int>> &E, vector<bool> &used,
         int v = 0) {
  ans.push_back(v);
  used[v] = true;
  for (int w : E[v]) {
    if (!used[w]) {
      dfs(ans, E, used, w);
      ans.push_back(v);
    }
  }
}
void solve() {
  string s, s1, s2;
  cin >> s;
  for (long long int i = 0; i < s.size(); i++) {
    if (i & 1)
      s2 += s[i];
    else
      s1 += s[i];
  }
  if (s2.empty()) {
    cout << stoi(s1) - 1 << "\n";
    return;
  }
  cout << (((stoi(s1) + 1) * (stoi(s2) + 1)) - 2) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
