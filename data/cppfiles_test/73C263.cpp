#include <bits/stdc++.h>
using namespace std;
long long int vmax(vector<long long int> &v) {
  return (*max_element(v.begin(), v.end()));
}
long long int vmin(vector<long long int> &v) {
  return (*min_element(v.begin(), v.end()));
}
long long int power_mod_m(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = ((res % p) * (x % p)) % p;
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res;
}
long long int inverse_mod(long long int x, long long int mod) {
  return (power_mod_m(x, mod - 2, mod));
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  };
  long long int i = 1;
  long long int cnt = 0;
  vector<long long int> second;
  second = a;
  sort(second.begin(), second.end());
  while (1) {
    if (a == second) {
      cout << cnt << "\n";
      return;
    }
    cnt++;
    long long int start;
    if (i % 2 != 0) {
      start = 1;
    } else {
      start = 2;
    }
    for (int j = start; j < n; j += 2) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
      }
    }
    i++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  mt19937 rand(chrono::steady_clock::now().time_since_epoch().count());
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
