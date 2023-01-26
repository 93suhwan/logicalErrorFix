#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int INF = 1e9;
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a;
  long long int f = 0;
  for (int i = 0; i < n; i++) {
    long long int z;
    cin >> z;
    a.push_back(z);
  }
  if (n == 1) {
    cout << k << endl;
    return;
  }
  while (a.size() != 1) {
    n = a.size();
    long long int c = ceil(double(k) / n);
    f += c;
    c *= n;
    sort(a.begin(), a.end());
    long long int x = 0;
    long long int g = 0, gg = 0;
    vector<long long int> ff;
    long long int t = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] - a[i - 1] < f) {
        x += f - (a[i] - a[i - 1]);
      } else if (a[i] - a[i - 1] > f) {
        ff.push_back(t);
        t += (a[i] - a[i - 1]) - f;
      }
    }
    long long int xa = c - k;
    k = 0;
    if (x > xa)
      k = x - xa;
    else
      break;
    ff.push_back(t);
    if (ff.size() == 1) f += k;
    a = ff;
  }
  cout << f << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
