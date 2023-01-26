#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<int> vec;
    vec.reserve(n);
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'a') {
        if (i < n - 1 && s[i] != s[i + 1]) {
          vec.push_back(cnt * k);
          cnt = 0;
        }
      } else
        cnt++;
    }
    if (cnt > 0) vec.push_back(cnt);
    vector<int> vec2(vec.size(), 0);
    if (vec.size() > 0) {
      vec2[0] = 1;
      int sum = vec2[0] * vec[0];
      for (int i = 1; i < vec.size(); i++) {
        vec2[i] = sum + 1;
        sum += vec2[i] * vec[i];
      }
    }
    x--;
    vector<int> vec3(vec2.size(), 0);
    for (int i = vec2.size() - 1; i >= 0; i--) {
      if (x > vec2[i]) {
        vec3[i] = min(vec[i], x / vec2[i]);
        x -= vec3[i] * vec2[i];
      }
    }
    int p = vec3.size() - 1;
    string ans = "";
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a')
        ans += 'a';
      else if (s[i] == '*') {
        if (i == 0 || s[i - 1] == 'a') {
          for (int j = 0; j < vec3[p]; j++) ans += 'b';
          p--;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
