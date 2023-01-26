#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
bool compare(pair<int, char> a, pair<int, char> b) {
  if (a.second == b.second)
    return a.first < b.first;
  else
    return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, char>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;
    sort(arr.begin(), arr.end(), compare);
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      if (arr[i - 1].first == i)
        continue;
      else {
        if (arr[i - 1].first > i && arr[i - 1].second == 'R') {
          flag = false;
          break;
        } else if (arr[i - 1].first < i && arr[i - 1].second == 'B') {
          flag = false;
          break;
        }
      }
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
