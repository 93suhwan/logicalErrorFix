#include <bits/stdc++.h>
using namespace std;
int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mp[x]++;
    }
    stack<int> st;
    long long hv = 0;
    long long cost = 0;
    bool flag = true;
    for (int i = 0; i <= n; i++) {
      if (!flag) {
        cout << "-1 ";
        continue;
      }
      cout << mp[i] + cost << " ";
      if (mp[i] == 0) {
        if (st.size() > 0)
          cost = cost + (i - st.top()), st.pop();
        else
          flag = false;
      } else {
        mp[i]--;
        while (mp[i] != 0) st.push(i), mp[i]--;
      }
    }
    cout << endl;
  }
  return 0;
}
