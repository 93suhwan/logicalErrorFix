#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long test = 1; test <= t; test++) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    string s;
    cin >> s;
    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        b[v[i]] = 0;
      else
        a[v[i]] = 0;
    }
    int k = b.size();
    map<int, int> st, mt;
    for (int i = 1; i <= k; i++) st[i]++;
    for (int i = k + 1; i <= n; i++) mt[i]++;
    for (auto i = b.begin(); i != b.end(); i++) {
      if (i->first > k) {
        b[i->first] = st.begin()->first;
      } else
        b[i->first] = i->first;
      st.erase(b[i->first]);
    }
    for (auto i = a.begin(); i != a.end(); i++) {
      if (i->first <= k) {
        a[i->first] = mt.begin()->first;
      } else {
        a[i->first] = i->first;
      }
      mt.erase(a[i->first]);
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        v[i] = b[v[i]];
      else
        v[i] = a[v[i]];
    }
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
  }
  return 0;
}
