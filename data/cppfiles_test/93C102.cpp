#include <bits/stdc++.h>
using namespace std;
int powmod(int x, int y, int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x) % p;
    y /= 2;
    x = (x * x) % p;
  }
  return res;
}
string dectobin(int x) {
  string s = "";
  while (x > 0) {
    int t = x % 2;
    s.push_back(t + '0');
    x /= 2;
  }
  reverse(s.begin(), s.end());
  if (s.compare("") == 0)
    return "0";
  else
    return s;
}
int long long bintodec(string s) {
  int long long ans = 0;
  int long long n = s.size();
  for (int long long i = n - 1; i >= 0; i--) {
    if (s[i] == '1') ans += pow(2, n - i - 1);
  }
  return ans;
}
int find(int k, int n) { return ((n & (1 << (k - 1))) >> (k - 1)); }
int long long arr[3 * 100000 + 1];
int32_t main() {
  arr[0] = 0;
  for (int long long i = 0; i < (3 * 100000 + 1); i++) arr[i] = i ^ arr[i - 1];
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int long long a, b;
    cin >> a >> b;
    int long long k = 0;
    k = arr[a - 1];
    int long long sum = a;
    string s = "";
    for (int long long i = 0; i < (40); i++) {
      int long long u = 0, v = 0;
      u = b & (1LL << i);
      v = k & (1LL << i);
      if (u == v)
        s = "0" + s;
      else
        s = "1" + s;
    }
    int long long l = bintodec(s);
    if (l == a)
      sum += 2;
    else if (l == 0)
      sum += 0;
    else
      sum += 1;
    cout << sum << "\n";
  }
  return 0;
}
