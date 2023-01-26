#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mp[v[i]] = 1;
    }
    sort(v.begin(), v.end());
    int cnt = floor(n / 2);
    for (int i = 0; i < n - 1 && cnt != 0; i++) {
      for (int j = i + 1 && cnt != 0; j < n; j++) {
        if (v[i] != v[j]) {
          if (mp[v[j] % v[i]] == 0) {
            cout << v[j] << " " << v[i] << endl;
            cnt--;
            if (cnt == 0) break;
          }
        }
      }
    }
  }
}
