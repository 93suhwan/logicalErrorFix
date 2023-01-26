#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100, M = 1e6 + 100;
long long t, n;
long long a[N];
long long ans[N];
long long mp[N];
inline long long read() {
  char c;
  long long x = 0, flag = 1;
  c = getchar();
  if (c == '-') {
    flag = -1;
  } else {
    x += c - '0';
  }
  c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  if (flag < 0) return -x;
  return x;
}
int32_t main() {
  t = read();
  while (t--) {
    n = read();
    memset(mp, 0, sizeof mp);
    memset(ans, -1, sizeof ans);
    stack<long long> st;
    for (long long i = 0; i < n; i++) a[i] = read(), mp[a[i]]++;
    sort(a, a + n);
    long long ss = 0;
    for (long long i = 0; i <= n; i++) {
      if (i > 0 && mp[i - 1] == 0) {
        if (st.empty()) break;
        long long j = st.top();
        st.pop();
        ss += i - j - 1;
      }
      ans[i] = ss + mp[i];
      while (i > 0 && mp[i - 1] > 1) {
        mp[i - 1]--;
        st.push(i - 1);
      }
    }
    for (long long i = 0; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
