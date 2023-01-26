#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    vector<long long> v;
    int curcnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        curcnt++;
      } else {
        if (curcnt > 0) v.push_back(curcnt * (k) + 1);
        curcnt = 0;
      }
    }
    if (curcnt > 0) v.push_back(curcnt * (k) + 1);
    curcnt = 0;
    reverse(v.begin(), v.end());
    vector<long long> multi;
    if (!v.empty()) multi.push_back(v[0]);
    for (int i = 1; i < v.size(); i++) {
      multi.push_back(v[i] * multi[i - 1]);
    }
    reverse(multi.begin(), multi.end());
    multi.push_back(1);
    vector<long long> gg;
    for (int i = 0; i < multi.size() - 1; i++) {
      gg.push_back((x - 1) / multi[i + 1]);
      x = ((x - 1) % multi[i + 1] + 1);
    }
    bool started = 0;
    bool cur = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*' && !started) {
        started = 1;
        for (int j = 0; j < gg[cur]; j++) cout << 'b';
        cur++;
      } else if (s[i] == 'a') {
        cout << 'a';
        started = 0;
      }
    }
    cout << endl;
  }
}
