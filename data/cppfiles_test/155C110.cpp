#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n, i;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    long long int p[n];
    for (i = 0; i < n; i++) {
      cin >> p[i];
    }
    cin >> s;
    map<long long int, long long int> st1, st2;
    for (i = 0; i < n; i++) {
      if (s[i] == '1') {
        st1.insert({p[i], p[i]});
      } else if (s[i] == '0') {
        st2.insert({p[i], p[i]});
      }
    }
    if (st2.size() != 0 && st1.size() != 0) {
      long long int m = n;
      for (auto i = st1.rbegin(); i != st1.rend(); i++) {
        i->second = m;
        m--;
      }
      long long int k = 1;
      for (auto i = st2.begin(); i != st2.end(); i++) {
        i->second = k;
        k++;
      }
      for (i = 0; i < n; i++) {
        if (st1.find(p[i]) != st1.end()) {
          auto it = st1.find(p[i]);
          p[i] = it->second;
        } else if (st2.find(p[i]) != st2.end()) {
          auto it = st2.find(p[i]);
          p[i] = it->second;
        }
      }
    }
    for (i = 0; i < n; i++) {
      cout << p[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
