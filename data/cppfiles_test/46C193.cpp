#include <bits/stdc++.h>
using namespace std;
bool ispowerof2(int n) { return (n && !(n & n - 1)); }
const long long int INF = 1e14;
const int mod = 1e9 + 7;
long long int mx = 1e7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v, k;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      v.push_back(x);
    }
    int cnt = 0;
    long long int m = 0;
    for (long long int i = n - 1; i >= 0; i--) {
      if (v[i] > m) cnt++;
      m = max(v[i], m);
    }
    cout << cnt - 1 << '\n';
  }
  cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << '\n';
  if (((float)clock() / CLOCKS_PER_SEC) >= 1.0)
    cerr << "Need to optimize!!" << '\n';
  else
    cerr << "RuntimeOKAY!" << '\n' << '\n';
  return 0;
}
