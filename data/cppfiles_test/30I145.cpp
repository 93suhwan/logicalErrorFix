#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2, mod);
  ans *= ans;
  ans %= mod;
  if (b % 2) {
    ans *= a;
  }
  return ans % mod;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long ans = n + 1;
  for (char c = 'a'; c <= 'z'; ++c) {
    long long cnt = 0;
    vector<pair<char, long long>> ns;
    for (long long i = 0; i < s.length(); ++i) {
      if (s[i] == c) {
        ++cnt;
      } else {
        ns.push_back(make_pair(s[i], i));
      }
    }
    if (ns.size() == 0) {
      cout << "0"
           << "\n";
      return;
    }
    bool ispal = true;
    long long i = 0, j = ns.size() - 1, p, q;
    while (i <= j) {
      if (ns[i].first == ns[j].first) {
        p = ns[i].second;
        q = ns[j].second;
        ++i;
        --j;
      } else {
        ispal = false;
        break;
      }
    }
    if (!ispal) {
      continue;
    }
    if (p < q) {
      i = p;
      j = q;
      while (i < j) {
        if (s[i] == s[j] && s[i] == c) {
          cnt -= 2;
        }
        ++i;
        --j;
      }
      if (i == j) {
        cnt -= 1;
      }
    }
    while (p >= 0 && q <= n - 1) {
      if (s[p] == s[q] && s[p] == c) {
        cnt -= 2;
      }
      --p;
      ++q;
    }
    ans = min(ans, cnt);
  }
  if (ans == n + 1) {
    cout << "-1"
         << "\n";
  } else {
    cout << ans << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
