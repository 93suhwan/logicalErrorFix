#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n), vec2(n);
    map<int, int> mp;
    map<int, int> mp2;
    int cnt = n / k;
    for (int i = 0; i < n; ++i) {
      cin >> vec[i];
    }
    for (int i = 0; i < n; ++i) {
      if (mp[vec[i]] < k) {
        mp[vec[i]]++;
        vec2[i] = mp[vec[i]];
      } else {
        vec2[i] = 0;
      }
    }
    for (int i = 0; i < n; i++) {
      mp2[vec2[i]]++;
    }
    for (int i = 0; i < n; i++) {
      if (mp2[vec2[i]] < cnt) {
        for (int j = 0; j < n; j++) {
          if (mp2[vec2[j]] > cnt && mp[vec[j]] < vec2[i]) {
            mp2[vec2[j]]--;
            vec2[j] = vec2[i];
            mp[vec[j]] = vec2[i];
            mp2[vec2[i]]++;
            break;
          }
        }
      }
    }
    for (auto i : vec2) {
      cout << i << " ";
    }
    cout << endl;
  }
}
