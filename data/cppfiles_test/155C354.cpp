#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t{0};
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    long long int n{0};
    cin >> n;
    vector<long long int> v(n);
    set<long long int> st;
    for (long long int j = 0; j < n; j++) {
      cin >> v[j];
    }
    string s;
    cin >> s;
    for (long long int j = 0; j < n; j++) {
      if (s[j] == '0') {
        st.insert(v[j]);
      }
    }
    map<long long int, long long int> m;
    long long int nm = 1;
    for (long long int p : st) {
      m[p] = nm;
      nm++;
    }
    for (long long int j = 1; j <= n; j++) {
      if (m[j] == 0) {
        m[j] = nm;
        nm++;
      }
    }
    for (long long int j = 0; j < n; j++) {
      cout << m[v[j]] << " ";
    }
    cout << endl;
  }
  return 0;
}
