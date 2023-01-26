#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
const long long int int_max = 1e18;
const long long int int_min = -1e18;
const long double PI = acos(-1);
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int temp = n / 2 + (n % 2);
  vector<long long int> v;
  for (long long int i = temp; i <= n - 1; i++) {
    if (s[i] == '0') {
      v.push_back(i);
    }
  }
  if (v.size() == 0) {
    temp = n / 2;
    if (s[temp - 1] == '1') {
      cout << temp + 1 << ' ' << n << ' ' << temp << ' ' << n - 1 << '\n';
    } else {
      cout << temp + 1 << ' ' << n << ' ' << temp << ' ' << n << '\n';
    }
  } else {
    long long int idx = v[0];
    cout << 1 << ' ' << v[0] + 1 << ' ' << 1 << ' ' << v[0] << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
