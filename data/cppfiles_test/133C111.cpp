#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    string res = "";
    vector<string> v;
    for (long long i = 0; i < n - 2; i++) {
      cin >> s;
      v.push_back(s);
    }
    for (long long i = 0; i < n - 3; i++) {
      if (v[i][1] != v[i + 1][0]) {
        string temp = "";
        temp += v[i][1];
        temp += v[i + 1][0];
        v.insert(v.begin() + i + 1, temp);
        break;
      }
    }
    res += v[0];
    for (long long i = 1; i < v.size(); i++) {
      res += v[i][1];
    }
    if (res.size() != n) res += "a";
    cout << res << "\n";
  }
  return 0;
}
