#include <bits/stdc++.h>
using namespace std;
long long casenum = 1;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void rf() {}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  b = a;
  int kk = n / 2;
  int mx;
  mx = a[(int)a.size() - 1];
  for (int i = 0; i < n && kk; i++) {
    int nn;
    nn = mx % a[i];
    if (binary_search(b.begin(), b.end(), nn)) {
      continue;
    } else {
      cout << mx << " " << a[i] << endl;
      kk--;
    }
  }
}
int main() {
  fast();
  rf();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
