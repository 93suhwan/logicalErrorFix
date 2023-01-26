#include <bits/stdc++.h>
using namespace std;
const int N = 310;
const long long mod = 998244353;
pair<int, int> p[2010];
int a[N];
bool cmp(int c, int b) { return c >= b; }
void solve() {
  int n, m, res = 0;
  cin >> m >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int j = n - 1; j > i; j--) {
      if (a[j] > a[j - 1]) {
        swap(a[j], a[j - 1]);
        res++;
      }
    }
  cout << res << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
