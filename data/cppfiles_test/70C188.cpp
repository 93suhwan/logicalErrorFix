#include <bits/stdc++.h>
using namespace std;
long long md2;
inline void add(long long &a, long long b) {
  a += b;
  if (a >= 100000000) a -= 100000000;
}
inline void sub(long long &a, long long b) {
  a -= b;
  if (a < 0) a += 100000000;
}
inline long long mul(long long a, long long b) {
  return (long long)((long long)a * b % 100000000);
}
inline long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
inline long long inv(long long a) {
  a %= 100000000;
  if (a < 0) a += 100000000;
  long long b = 100000000, u = 0, v = 1;
  while (a) {
    long long t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  if (u < 0) u += 100000000;
  return u;
}
const long long N = 2e6 + 5;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long n = ((long long)(s).size());
    unordered_map<char, long long> cnt;
    long long prev = 0;
    deque<char> dq;
    for (long long i = n - 1; i >= 0; i--) {
      cnt[s[i]]++;
      if (cnt.size() > prev) dq.push_front(s[i]);
      prev = cnt.size();
    }
    vector<long long> req;
    long long k = dq.size();
    string ans3 = "";
    while (dq.size()) {
      ans3 += dq.front();
      req.push_back(dq.front() - 'a');
      dq.pop_front();
    }
    unordered_set<char> st;
    unordered_map<char, long long> cnt2;
    string ans;
    for (long long i = 0; i < n; i++) {
      cnt2[s[i]]++;
      st.insert(s[i]);
      if (st.size() == k) {
        long long len = i + 1;
        long long sum = 0;
        for (long long j = 0; j < k; j++) {
          sum += len;
          len -= cnt2[(req[j] + 'a')];
        }
        if (sum == n) {
          ans = s.substr(0, i + 1);
          break;
        }
      }
    }
    if (ans.size() == 0) {
      cout << -1 << "\n";
      continue;
    }
    string ans2 = ans;
    long long j = 0;
    string ans4 = ans;
    k = ans.size();
    while (k > 0) {
      string s2 = "";
      for (long long i = 0; i < k; i++) {
        if (ans[i] == (req[j] + 'a')) continue;
        s2 += ans[i];
      }
      ans2 += s2;
      ans = s2;
      k = s2.size();
      j++;
    }
    if (s == ans2) {
      cout << ans4 << " " << ans3 << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
}
