#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 12;
const long long Mod = 1e9 + 7;
const long long oo = 1e18;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m, ntest, k;
bool Check(int n, int m, int k) {
  if (n * (m / 2) < k) return false;
  if (n % 2 == 0) {
    return (k % 2 == 0);
  }
  if (n % 2 == 1) {
    if (k < m / 2) return false;
    k -= (m / 2);
    return (k % 2 == 0);
  }
  return true;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> ntest;
  while (ntest--) {
    cin >> n >> m >> k;
    if (Check(n, m, k))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
