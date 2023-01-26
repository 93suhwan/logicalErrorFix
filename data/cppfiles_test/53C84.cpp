#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &temp : vec) is >> temp;
  return is;
}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
const int mx = 1e6 + 5;
const int INF = 1000000007;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y >>= 1;
    x = (x * x) % 1000000007;
  }
  return (res % 1000000007);
}
bool solve() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  vector<pair<int, int>> temp;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    temp.push_back({arr[i], i});
  }
  sort(temp.begin(), temp.end());
  int ans = 0;
  int i = 0;
  while (i < n) {
    int j = temp[i].second;
    if (arr[j] == INT_MIN) {
      i++;
      continue;
    }
    while (i < n && j < n && arr[j] == temp[i].first) {
      arr[j++] = INT_MIN;
      i++;
    }
    ans++;
  }
  return ans <= k;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    if (solve())
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
