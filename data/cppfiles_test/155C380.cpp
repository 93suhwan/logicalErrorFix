#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j, ones, zeros, n;
  cin >> t;
  for (i = 0; i < t; i++) {
    ones = 0;
    zeros = 0;
    cin >> n;
    vector<int> high;
    vector<int> low;
    map<int, int> connect;
    int p[n];
    int q[n];
    string s;
    for (j = 0; j < n; j++) {
      cin >> p[j];
    }
    cin >> s;
    for (j = 0; j < n; j++) {
      if (s[j] == '1') {
        ones++;
        high.push_back(p[j]);
      } else {
        zeros++;
        low.push_back(p[j]);
      }
    }
    sort(high.begin(), high.end());
    sort(low.begin(), low.end());
    for (j = zeros + 1; j <= n; j++) {
      connect[high[j - zeros - 1]] = j;
    }
    for (j = 1; j <= zeros; j++) {
      connect[low[j - 1]] = j;
    }
    for (j = 0; j < n; j++) {
      q[j] = connect[p[j]];
    }
    for (j = 0; j < n; j++) {
      cout << q[j] << " ";
    }
    cout << endl;
  }
  return 0;
}
