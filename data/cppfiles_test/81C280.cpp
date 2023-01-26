#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pld = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using vld = vector<ld>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpld = vector<pld>;
int clz(unsigned long long N) { return N ? 63 - __builtin_clzll(N) : -1; }
int arr[300010];
int acum[300010];
int n, q;
void solvetask() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == '+')
      arr[i] = (i & 1) ? -1 : 1;
    else
      arr[i] = (i & 1) ? 1 : -1;
  }
  for (int i = 1; i <= n; i++) acum[i] = acum[i - 1] + arr[i - 1];
  while (q--) {
    int l, r;
    cin >> l >> r;
    int soma = acum[r] - acum[l - 1];
    if (soma == 0)
      cout << "0\n";
    else if (abs(soma) % 2 == 1)
      cout << "1\n";
    else
      cout << "2\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) solvetask();
}
