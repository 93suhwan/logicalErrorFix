#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<long long int> v;
  for (long long int i = 1; i <= 100000; i++) {
    v.push_back((i * i));
    v.push_back((i * i * i));
  }
  sort(v.begin(), v.end());
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int u = upper_bound(v.begin(), v.end(), n) - v.begin();
    cout << u - 1 << "\n";
  }
}
