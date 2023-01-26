#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  vector<string> v;
  long long tmp = 1;
  for (int i = 1; i < 63; i++) {
    string s;
    s = to_string(tmp);
    v.push_back(s);
    tmp *= 2;
  }
  while (t--) {
    long long n;
    cin >> n;
    vector<int> vec;
    string s = to_string(n);
    for (int i = 0; i < v.size(); i++) {
      int tm = 0, cnt = 0;
      for (int j = 0; j < s.size(); j++) {
        if (v[i][tm] == s[j]) {
          cnt += 1;
          tm++;
          if (tm == s.size()) break;
        }
      }
      long long ans = (v[i].size() - cnt) + (s.size() - cnt);
      vec.push_back(ans);
    }
    sort(vec.begin(), vec.end());
    cout << vec[0] << endl;
  }
}
