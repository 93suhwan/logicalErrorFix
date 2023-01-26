#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t, n, k, x;
  cin >> t;
  string st;
  while (t--) {
    cin >> n >> k >> x;
    x--;
    cin >> st;
    string s = "";
    vector<long long> v;
    for (long long i = 0; i < st.length();) {
      if (st[i] == 'a') {
        v.push_back(-1);
        i++;
      } else {
        long long c = 0;
        while (i < n && st[i] == '*') i++, c += k;
        v.push_back(c);
      }
    }
    vector<long long> v1(v.size());
    for (long long i = v1.size() - 1; i >= 0; i--) {
      if (v[i] < 0)
        v1[i] = -1;
      else {
        v1[i] = x % (v[i] + 1);
        x = x / (v[i] + 1);
      }
    }
    for (long long i = 0; i < v1.size(); i++) {
      if (v1[i] == 0) continue;
      if (v1[i] == -1)
        s += "a";
      else {
        for (long long j = 0; j < v1[i]; j++) s += "b";
      }
    }
    cout << s << endl;
  }
  return 0;
}
