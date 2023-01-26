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
    vector<int> ret(1000, 1000);
    ret[0] = 0;
    for (auto i = 0; i < n; ++i) {
      vector<int> nxt = ret;
      for (auto j = 0; j < 1000; ++j) {
        if (a[i] > ret[j]) {
          int b = a[i] ^ j;
          nxt[b] = min(a[i], nxt[b]);
        }
      }
      ret.swap(nxt);
    }
    vector<int> ret_lst;
    for (auto i = 0; i < 1000; ++i) {
      if (ret[i] < 1000) {
        ret_lst.push_back(i);
      }
    }
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
