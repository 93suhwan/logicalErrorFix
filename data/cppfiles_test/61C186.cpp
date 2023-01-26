#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
ll mod = 10e+7;
void fast(bool tieIO = 1) {
  cout << fixed << setprecision(9);
  if (tieIO) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  }
}
void piSquared() {
  int n;
  cin >> n;
  vll a(n), b(n), cT(n + 1), cD(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    cT[a[i]]++;
    cD[b[i]]++;
  }
  ll total = 1ll * n * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    total -= 1ll * (cT[a[i]] - 1) * (cD[b[i]] - 1);
  }
  cout << total << '\n';
  return;
}
int main() {
  fast();
  ll t;
  cin >> t;
  while (t--) {
    piSquared();
  }
  return 0;
}
