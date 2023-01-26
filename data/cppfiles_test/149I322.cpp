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
    cout << s << endl;
    vector<long long> v;
    if (s[0] != 'a') v.push_back(-1ll);
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'a') v.push_back(i);
    }
    if (s[n - 1] != 'a') v.push_back(n);
    vector<long long> can;
    for (int i = 1; i < v.size(); i++) {
      can.push_back((v[i] - v[i - 1] - 1) * (k) + 1);
    }
    vector<long long> multi(can.size());
    multi[can.size() - 1] = can[can.size() - 1];
    int cansize = can.size();
    for (int i = cansize - 2; i >= 0; i--) {
      multi[i] = multi[i + 1] * can[i];
    }
    multi.push_back(1);
    multi.push_back(1);
    vector<long long> ans;
    int pos = 0;
    while (x > 1) {
      long long cur = (x - 1) / multi[pos + 1];
      x -= cur * multi[pos + 1];
      ans.push_back(cur);
      pos++;
    }
    int position = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] != -1 && v[i] != n) cout << 'a';
      long long curr = i;
      if (curr == v.size() - 1) break;
      for (int j = 0; j < ans[curr]; j++) {
        cout << 'b';
      }
    }
    cout << endl;
  }
}
