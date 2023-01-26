#include <bits/stdc++.h>
using namespace std;
const string alpha_small = "abcdefghijklmnopqrstuvwxyz";
const string alpha_big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
long long expo(long long a, long long b, long long mod = 1000000007) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
double expod(double a, long long b) {
  double res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b = b >> 1;
  }
  return res;
}
vector<long long> sieve(int n) {
  int* arr = new int[n + 1]();
  vector<long long> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (int j = i * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long mod_add(long long a, long long b, long long m = 1000000007) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m = 1000000007) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m = 1000000007) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
void solve() {
  int n;
  cin >> n;
  vector<string> ss(n);
  for (int i = 0; i < n; i++) cin >> ss[i];
  int ans = 0;
  vector<char> cs{'a', 'b', 'c', 'd', 'e'};
  for (int j = 0; j < 5; j++) {
    vector<int> nums;
    for (int i = 0; i < n; i++) {
      string s = ss[i];
      char c = cs[j];
      int l = s.length();
      nums.push_back(0);
      for (int k = 0; k < l; k++) {
        if (s[k] == c)
          nums.back()++;
        else
          nums.back()--;
      }
    }
    sort((nums).rbegin(), (nums).rend());
    int curr = 0;
    int tans = 0;
    int idx = 0;
    while (1 and idx < n) {
      curr += nums[idx];
      if (curr > 0)
        tans++;
      else
        break;
      idx++;
    }
    ans = max(ans, tans);
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, inp;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
