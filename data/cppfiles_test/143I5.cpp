#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  map<long long int, long long int> mp;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  long long int rem = 0, fl = 0;
  stack<long long int> st;
  for (long long int i = 0; i <= n; i++) {
    if (fl == 1) {
      cout << "-1"
           << " ";
      continue;
    }
    if (i == 0) {
      if (mp.find(i) != mp.end()) {
        cout << mp[i] << " ";
        for (long long int j = 0; j < mp[i] - 1; j++) {
          st.push(i);
        }
      } else {
        cout << "0"
             << " ";
      }
      continue;
    }
    if (mp.find(i - 1) != mp.end()) {
      if (mp.find(i) != mp.end()) {
        cout << mp[i] << " ";
        for (long long int j = 0; j < mp[i] - 1; j++) {
          st.push(i);
        }
      } else {
        cout << "0"
             << " ";
      }
    } else {
      if (st.empty()) {
        cout << "-1"
             << " ";
        fl = 1;
        continue;
      }
      rem += (i - 1) - st.top();
      st.pop();
      long long int now = 0;
      if (mp.find(i) != mp.end()) {
        now = mp[i];
        for (long long int j = 0; j < mp[i] - 1; j++) {
          st.push(i);
        }
      }
      cout << rem + now << " ";
    }
  }
  cout << endl;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
