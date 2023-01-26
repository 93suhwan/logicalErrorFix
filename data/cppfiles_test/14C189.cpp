#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long s = 1;
  cin >> s;
  for (int p = 0; p < s; p++) {
    int d = 0;
  }
  while (s--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<vector<long long> > ans;
    for (long long i = n - 1; i > 0; i--) {
      long long mx = -1000000000000000000;
      long long ind = -1;
      for (long long j = 0; j <= i; j++) {
        if (mx < v[j]) {
          mx = v[j];
          ind = j;
        }
      }
      if (ind == i) {
        continue;
      } else {
        vector<long long> temp;
        vector<long long> tempv(n);
        for (long long j = 0; j <= i; j++) {
          tempv[j] = v[(j + ind + 1) % (i + 1)];
        }
        v = tempv;
        ans.push_back({1, i + 1, ind + 1});
      }
    }
    cout << ans.size() << "\n";
    for (auto itr : ans) {
      for (auto it : itr) {
        cout << it << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
