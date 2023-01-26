#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
long long t, a, b;
signed main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (min(a, b) == 0) {
      set<long long> st;
      long long q = max(a, b) + 1 >> 1;
      st.insert(max(q, max(a, b) - q));
      st.insert(min(q, max(a, b) - q));
      cout << st.size() << endl;
      for (auto i : st) cout << i << " ";
      puts("");
      continue;
    }
    long long x = a + b, z;
    if (x & 1) {
      set<long long> st;
      x = x + 1 >> 1;
      z = x - min(a, b);
      st.insert(z);
      for (long long i = 1; i <= min(a, b); i++) st.insert(z + (i << 1));
      x = a + b >> 1;
      z = x - min(a, b);
      st.insert(z);
      for (long long i = 1; i <= min(a, b); i++) st.insert(z + (i << 1));
      cout << st.size() << endl;
      for (auto i : st) cout << i << " ";
      puts("");
    } else {
      cout << min(a, b) + 1 << endl;
      for (long long i = 0; i <= min(a, b); i++)
        cout << (a + b >> 1) - min(a, b) + i * 2 << ' ';
      puts("");
    }
  }
}
