#include <bits/stdc++.h>
using namespace std;
static bool solve(const vector<int>& p1, const vector<int>& p2) {
  if (p1[1] == p2[1]) return p1[2] <= p2[2];
  return p1[1] < p2[1];
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    string s;
    cin >> s;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++) v.push_back({i, s[i] - '0', arr[i]});
    sort(v.begin(), v.end(), solve);
    for (int i = 0; i < n; i++) {
      v[i][2] = i + 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) cout << v[i][2] << " ";
    cout << endl;
  }
}
