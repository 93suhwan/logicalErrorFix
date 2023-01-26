#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int n, k;
vector<int> a;
void solve();
int countMoves(int, int, int);
int main() {
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
void solve() {
  cin >> n >> k;
  int temp;
  for (int i = 1; i < n + 1; i += 1) {
    cin >> temp;
    if (temp > i)
      a.push_back(n);
    else
      a.push_back(i - temp);
  }
  int res = countMoves(0, 0, k);
  if (res > 2000) res = -1;
  cout << res << "\n";
  a.clear();
  return;
}
int countMoves(int bias, int i, int K) {
  int c = 0, C = 0;
  if (K <= 0) return 0;
  if (i >= n) return 2001;
  while ((a[i] == bias || a[i] > i) && i < n) {
    if (bias == a[i]) c++;
    i++;
  }
  if (a[i - 1] == bias) C = 1;
  return min(countMoves(bias, i + 1, K - c),
             a[i] + countMoves(a[i], i, K - c + C));
}
