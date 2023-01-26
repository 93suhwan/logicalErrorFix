#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int infi = INT_MAX;
const long long infll = LLONG_MAX;
const long double PI = 3.1415926535897932384626;
bool cmp(pair<string, int> &p1, pair<string, int> &p2) {
  for (int i = 0; i < p1.first.length(); i++) {
    if (p1.first[i] == p2.first[i]) continue;
    if (i & 1) {
      return (p1.first[i] > p2.first[i]);
    }
    return (p1.first[i] < p2.first[i]);
  }
  return true;
}
void solve(int test_case) {
  int n, k;
  cin >> n >> k;
  vector<pair<string, int>> arr(n);
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    arr[i - 1].first = s;
    arr[i - 1].second = i;
  }
  sort(arr.begin(), arr.end(), cmp);
  for (auto &itr : arr) {
    cout << itr.second << " ";
  }
  cout << endl;
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  while (tc--) solve(tc);
  return 0;
}
