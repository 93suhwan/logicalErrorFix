#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, s;
    cin >> n >> s;
    if (n == 1) {
      cout << s << '\n';
      continue;
    }
    int poz = 0;
    vector<int> v(s);
    for (int i = 0; i < s; ++i) v[i] = 0;
    for (int i = 100000000; i >= 1; i /= 10) {
      while (n >= i && (n - i) >= (s - poz - 1)) {
        v[poz] += i;
        n -= i;
        ++poz;
        if (poz == s) poz = s - 1;
      }
    }
    for (int i = 0; i < s; ++i) cout << v[i] << " ";
    cout << '\n';
  }
  return 0;
}
