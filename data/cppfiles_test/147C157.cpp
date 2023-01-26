#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-7;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
int dh[] = {-1, 0, 1, 0};
int dw[] = {0, 1, 0, -1};
void solve() {
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = (int)(0); i < (int)(s.size()); i++)
    if (s[i] == 'N') cnt++;
  if (cnt == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
int main() {
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
