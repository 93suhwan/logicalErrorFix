#include <bits/stdc++.h>
using namespace std;
long long int arr[5010];
long long int inf = 1e18;
vector<vector<long long int>> dp;
long long int solve(int l, int r, int k, int x) { return 0; }
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first == b.first) {
    return (a.second > b.second);
  } else {
    return false;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n, m, x, ans = 0;
  set<int> seats;
  vector<pair<int, int>> a;
  long long int arr[310];
  cin >> t;
  for (long long int kk = 0; kk < t; kk++) {
    ans = 0;
    seats.insert(0);
    cin >> n >> m;
    seats.insert(m + 20);
    for (int i = 0; i < m; i++) {
      cin >> arr[i];
      a.push_back(make_pair(arr[i], i + 1));
    }
    sort(a.begin(), a.end(), sortbysec);
    for (int i = 0; i < m; i++) {
      x = a[i].second;
      vector<int> b(seats.begin(), seats.end());
      ans = ans + (lower_bound(b.begin(), b.end(), x) - b.begin()) - 1;
      seats.insert(x);
    }
    seats.clear();
    a.clear();
    cout << ans << "\n";
  }
  return 0;
}
