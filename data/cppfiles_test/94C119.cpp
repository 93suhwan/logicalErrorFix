#include <bits/stdc++.h>
using namespace std;
void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fastio();
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    long long i, j;
    set<long long> st;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      st.insert(a[i]);
    }
    long long val[18] = {0};
    for (i = 0; i < 18; i++) {
      if (st.find(i) != st.end()) {
        val[i] = 1;
      }
    }
    long long cur = 10;
    for (i = 1; i < 18; i++) {
      if (val[i] == 0) {
        val[i] = cur;
        cur = cur * 10;
      } else {
        cur = 10;
      }
    }
    long long cnt = 0;
    cur = 0;
    vector<long long> pp;
    pp.push_back(0);
    while (true) {
      long long p = val[cnt] * 9;
      cur += p;
      cnt++;
      pp.push_back(cur);
      if (cur > k) {
        break;
      }
    }
    string ans = "";
    long long tot = cur;
    for (i = 0; i < cnt; i++) {
      cur = pp.back();
      pp.pop_back();
      long long v = pp.back();
      for (j = 0; j <= 9; j++) {
        if (val[cnt - i - 1] * j + v > k) {
          break;
        }
      }
      ans += '0' + j;
      k -= val[cnt - i - 1] * j;
    }
    cout << ans << "\n";
  }
}
