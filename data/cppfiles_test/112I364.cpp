#include <bits/stdc++.h>
using namespace std;
string int_to_string(long long n) {
  string s = "";
  while (n) {
    long long now = n % 10;
    s += now + '0';
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long string_to_int(string s) {
  long long n = 0;
  for (int i = 0; i < (int)(s.size()); i++) {
    n *= 10;
    n += s[i] - '0';
  }
  return n;
}
void chmin(int &a, int b) {
  if (b < a) {
    a = b;
  }
}
void chmax(int &a, int b) {
  if (b > a) {
    a = b;
  }
}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int month[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int a[3];
int m;
void solve() {
  for (int i = 0; i < (int)(3); i++) {
    cin >> a[i];
  }
  cin >> m;
  sort(a, a + 3);
  if (a[0] - 1 + a[1] - 1 + a[2] - 1 < m) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
}
signed main() {
  std::ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
