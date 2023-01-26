#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
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
long long check(vector<int> &arr, int j) {
  long long sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (i != j) sum += arr[i];
  }
  return sum;
}
void solve() {
  long long n;
  cin >> n;
  vector<string> arr(n);
  cin >> arr;
  vector<vector<int>> temp(n, vector<int>(5, 0));
  for (int i = 0; i < n; i++) {
    for (auto ch : arr[i]) {
      temp[i][ch - 'a']++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < 5; i++) {
    long long totalCurr = 0, totalOther = 0;
    vector<pair<int, int>> ref;
    long long currAns = 0;
    for (int j = 0; j < n; j++) {
      long long curr = temp[j][i];
      long long other = check(temp[j], i);
      if (curr > other) {
        totalCurr += curr;
        totalOther += other;
        currAns++;
      } else {
        ref.push_back({curr, other});
      }
    }
    sort((ref).begin(), (ref).end(),
         [&](const pair<int, int> &a, const pair<int, int> &b) {
           return a.first - a.second > b.first - b.second;
         });
    for (int j = 0; j < ref.size(); j++) {
      totalCurr += ref[j].first;
      totalOther += ref[j].second;
      if (totalCurr <= totalOther) break;
      currAns++;
    }
    ans = max(ans, currAns);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
