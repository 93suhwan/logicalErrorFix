#include <bits/stdc++.h>
using namespace std;
template <class... Args>
void debug(Args... args) {
  auto tmp = {(cout << args << ' ', 0)...};
  cout << endl;
}
using ll = long long;
const int N = 3e5 + 10;
const int mod = 4933;
const double eps = 1e-9;
char a[N];
int s[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    cin >> (a + 1);
    for (int i = 1; i <= n; ++i) {
      s[i] = s[i - 1] + (a[i] == '+' ? 1 : -1) * (i % 2 ? 1 : -1);
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      int x = abs(s[r] - s[l - 1]);
      cout << (x > 2 ? (x % 2 ? 1 : 2) : x) << '\n';
    }
  }
}
