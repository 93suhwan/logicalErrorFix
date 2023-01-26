#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a = 0, b = 0, c = 1;
  vector<int> v;
  while (n != 0) {
    int r = n % 10;
    v.push_back(r);
    n /= 10;
  }
  reverse((v).begin(), (v).end());
  for (int i = 0; i < v.size(); i++) {
    if (c & 1)
      a = a * 10 + v[i];
    else
      b = b * 10 + v[i];
    c++;
  }
  cout << (a + 1) * (b + 1) - 2 << "\n";
}
int main() {
  int tc, q = 1;
  cin >> tc;
  while (tc--) solve();
}
