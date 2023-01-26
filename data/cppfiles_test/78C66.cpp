#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int infi = INT_MAX;
const long long infll = LLONG_MAX;
const long double PI = 3.1415926535897932384626;
long long power(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % MOD;
    }
    a = (a * a) % MOD;
    b = b >> 1;
  }
  return ans;
}
void solve(int test_case) {
  long long n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> bits(32, 0);
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j] & (1 << i)) bits[i]++;
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int ok = 1;
    for (int j = 0; j < 32; j++) {
      if (bits[j] % i != 0) {
        ok = 0;
        break;
      }
    }
    if (ok) ans.push_back(i);
  }
  for (auto itr : ans) {
    cout << itr << " ";
  }
  cout << endl;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) solve(tc);
  return 0;
}
