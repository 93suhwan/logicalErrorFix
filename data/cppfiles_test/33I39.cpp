#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& it : a) {
      cin >> it;
    }
    unordered_map<int, int> ret;
    ret[0] = 0;
    for (auto i = 0; i < n; ++i) {
      unordered_map<int, int> nxt = ret;
      for (auto iter = ret.begin(); iter != ret.end(); ++iter) {
        if (a[i] > iter->second) {
          int b = a[i] ^ iter->first;
          if (ret.find(b) == ret.end()) {
            nxt[b] = a[i];
          } else {
            nxt[b] = min(a[i], iter->second);
          }
        }
      }
      ret.swap(nxt);
    }
    vector<int> ret_lst;
    for (auto iter = ret.begin(); iter != ret.end(); ++iter) {
      ret_lst.push_back(iter->first);
    }
    sort(ret_lst.begin(), ret_lst.end());
    cout << ret_lst.size() << endl;
    for (auto i = 0; i < ret_lst.size(); ++i) {
      if (i > 0) {
        cout << " ";
      }
      cout << ret_lst[i];
    }
    cout << endl;
  }
}
