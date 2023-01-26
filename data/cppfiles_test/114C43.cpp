#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
void solve() {
  ll n;
  cin >> n;
  vl num(n);
  for (long long int i = (0); i <= (n - 1); i++) {
    cin >> num[i];
  }
  sort(num.begin(), num.end());
  for (long long int i = (1); i <= ((n / 2)); i++) {
    cout << num[n - i] << " " << num[0] << endl;
  }
}
int main() {
  if (true) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  ll t;
  cin >> t;
  while (t--) solve();
}
