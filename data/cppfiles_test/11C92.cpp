#include <bits/stdc++.h>
using namespace std;
bool compare(long long l1, long long l2) { return l1 > l2; }
int main() {
  long long t;
  cin >> t;
  while (t > 0) {
    long long n;
    vector<long long> b;
    string s;
    vector<vector<long long>> a;
    long long ans[5];
    for (int i = 0; i < 5; i++) {
      a.push_back({0});
      ans[i] = 0;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
      b.assign(5, 0);
      cin >> s;
      for (int j = 0; j < s.length(); j++) {
        b[s[j] - 97]++;
      }
      for (int i = 0; i < 5; i++) {
        a[i].push_back(2 * b[i] - s.length());
      }
      b.clear();
    }
    long long total, j;
    for (int i = 0; i < 5; i++) {
      stable_sort(a[i].begin() + 1, a[i].end(), compare);
      total = a[i][1];
      j = 0;
      if (total > 0) {
        j++;
      }
      while (j < n && total > 0) {
        total += a[i][j + 1];
        j++;
      }
      if ((j == n && total > 0) || j == 0)
        ans[i] = j;
      else
        ans[i] = j - 1;
    }
    long long max = ans[0];
    for (int i = 1; i < 5; i++) {
      if (max < ans[i]) {
        max = ans[i];
      }
    }
    cout << max << "\n";
    t--;
  }
  return 0;
}
