#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vll = vector<ll>;
using vvll = vector<vll>;
void solve() {
  for (int i = 1; i <= (8); i++) {
    if (i & 1)
      for (int j = 1; j <= (8); j++) {
        cout << i << ' ' << j << endl;
        string s;
        cin >> s;
        if (s == "Done") return;
      }
    else
      for (int j = 8; j >= (1); j--) {
        cout << i << ' ' << j << endl;
        string s;
        cin >> s;
        if (s == "Done") return;
      }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
