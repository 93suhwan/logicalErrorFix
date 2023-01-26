#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int tt, n, a[100005], b[100005], k;
map<int, int> mp;
int main() {
  tt = read();
  while (tt--) {
    n = read();
    k = read();
    for (int(i) = 1; i <= (n); ++i) {
      a[i] = read();
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int(i) = 1; i <= (n); ++i) mp[b[i]] = i;
    set<int> st;
    for (int(i) = 1; i <= (n); ++i) {
      set<int>::iterator it = st.find(mp[a[i]]);
      if (it != st.end()) {
        st.erase(it);
        st.insert(mp[a[i]] + 1);
      } else
        st.insert(mp[a[i]] + 1);
    }
    if (k >= st.size())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
