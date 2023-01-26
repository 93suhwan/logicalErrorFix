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
int bintodec(string s) {
  int ans = 0;
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') ans += pow(2, n - i - 1);
  }
  return ans;
}
int find(int k, int n) { return ((n & (1 << (k - 1))) >> (k - 1)); }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    int long long n, k;
    cin >> n >> k;
    vector<int long long> vec;
    int long long a, b, c, d, e, f;
    cout << "and"
         << " " << 1 << " " << 2 << "\n";
    cout << flush;
    cin >> a;
    cout << "or"
         << " " << 1 << " " << 2 << "\n";
    cout << flush;
    cin >> b;
    int long long x = a + b;
    cout << "and"
         << " " << 1 << " " << 3 << "\n";
    cout << flush;
    cin >> c;
    cout << "or"
         << " " << 1 << " " << 3 << "\n";
    cout << flush;
    cin >> d;
    int long long y = c + d;
    cout << "and"
         << " " << 2 << " " << 3 << "\n";
    cout << flush;
    cin >> e;
    cout << "or"
         << " " << 2 << " " << 3 << "\n";
    cout << flush;
    cin >> f;
    int long long z = e + f;
    int long long a1 = (x - z + y) / 2;
    int long long a2 = (z - y + x) / 2;
    int long long a3 = (y + z - x) / 2;
    vec.push_back(a1);
    vec.push_back(a2);
    vec.push_back(a3);
    for (int long long i = (4); i < (n + 1); i++) {
      int long long u, v;
      cout << "and"
           << " " << 1 << " " << i << "\n";
      cout << flush;
      cin >> u;
      cout << "or"
           << " " << 1 << " " << i << "\n";
      cout << flush;
      cin >> v;
      vec.push_back(u + v - a1);
    }
    sort((vec).begin(), (vec).end());
    cout << "finish"
         << " " << vec[k - 1] << "\n";
    cout << flush;
  }
  return 0;
}
