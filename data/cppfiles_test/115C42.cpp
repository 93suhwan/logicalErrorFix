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
  long long int i = 1, j = k;
  long long int mid;
  map<long long int, long long int> mp;
  while (i <= j) {
    long long int mid = (i + j) / 2;
    long long int s = mid;
    for (int m = 1; m < n; m++) {
      s += min(a[m] - a[m - 1], mid);
    }
    if (s > k) {
      j = mid - 1;
      mp[s - k] = mid;
    } else if (k > s)
      i = mid + 1;
    else {
      cout << mid << endl;
      return;
    }
  }
  cout << mp.begin()->second << endl;
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
