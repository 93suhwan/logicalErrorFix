#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  long long t;
  cin >> t;
  for (long long q = 0; q < t; q++) {
    long long n;
    cin >> n;
    string prev;
    cin >> prev;
    string cur;
    string s = "";
    s.push_back(prev[0]);
    bool flag = false;
    for (long long i = 1; i < n - 2; i++) {
      cin >> cur;
      if (!flag && prev[1] != cur[0]) {
        s.push_back(prev[1]);
        flag = true;
      }
      s.push_back(cur[0]);
      prev = cur;
    };
    s.push_back(cur[1]);
    if ((long long)s.size() < n) s.push_back('a');
    cout << s << endl;
  }
}
