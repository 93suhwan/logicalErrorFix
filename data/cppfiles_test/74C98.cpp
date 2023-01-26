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
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int month[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                          {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
void solve() {
  int a, b;
  cin >> a >> b;
  int x = (a + b + 1) / 2, y = (a + b) / 2;
  vector<int> v;
  if (a > b) {
    for (int i = a - x; i <= x - a + 2 * y; i += 2) {
      v.push_back(i);
    }
  } else {
    for (int i = b - y; i <= y - b + 2 * x; i += 2) {
      v.push_back(i);
    }
  }
  swap(x, y);
  if (a > b) {
    for (int i = a - x; i <= x - a + 2 * y; i += 2) {
      v.push_back(i);
    }
  } else {
    for (int i = b - y; i <= y - b + 2 * x; i += 2) {
      v.push_back(i);
    }
  }
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
  cout << v.size() << endl;
  for (int i = 0; i < (int)(v.size()); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
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
