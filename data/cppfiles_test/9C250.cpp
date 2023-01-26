#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    string x;
    vector<long long> y[27];
    cin >> x;
    n = x.size();
    k = 2;
    for (long long i = 0; i < n; i++) {
      y[x[i] - 'a' + 1].push_back(i);
    }
    vector<pair<long long, vector<long long>>> z;
    for (long long i = 1; i <= 26; i++) {
      if (y[i].size()) {
        z.push_back({y[i].size(), y[i]});
      }
    }
    sort(z.begin(), z.end());
    reverse(z.begin(), z.end());
    vector<long long> color;
    for (long long i = 0; i < z.size(); i++) {
      for (long long j = 0; j < k && j < z[i].first; j++) {
        color.push_back(z[i].second[j]);
      }
    }
    long long m = color.size() / k;
    cout << m;
    cout << "\n";
  }
  return 0;
}
