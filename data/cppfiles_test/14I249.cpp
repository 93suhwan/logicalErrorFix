#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  long long x = 0;
  long long on = n;
  vector<long long> v1;
  vector<long long> v2;
  vector<long long> v3;
  for (long long i = 0; i < n - 1; i++) {
    if (1 + x == min(v[i].second + x, n)) {
      on--;
    } else {
      v1.push_back(1 + x);
      v2.push_back(min(v[i].second + x, n));
      v3.push_back(1);
    }
    x++;
  }
  cout << on - 1 << endl;
  for (long long i = 0; i < v1.size(); i++) {
    cout << v1[i] << " " << v2[i] << " " << v3[i] << endl;
  }
}
int main() {
  fast();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
