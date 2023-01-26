#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long vis[100001];
long long dist[100001];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double n, m;
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<double> v(n);
    for (long long i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    double sum = 0;
    for (long long i = 0; i < n - 1; i++) {
      sum += v[i];
    }
    sum /= (n - 1);
    sum += v[n - 1];
    cout << sum << endl;
  }
}
