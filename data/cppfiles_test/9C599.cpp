#include <bits/stdc++.h>
using namespace std;
inline long long int ceil2(long long int a, long long int b) {
  return (a + b - 1) / b;
}
inline long long int hcf(long long int n1, long long int n2) {
  if (n2 != 0)
    return hcf(n2, n1 % n2);
  else
    return n1;
}
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int primefactor(int n) {
  int cnt = 0;
  while (n % 2 == 0) {
    n /= 2;
    cnt++;
  }
  for (int i = 3; (i * i) <= n; i += 2) {
    while (n % i == 0) {
      n /= i;
      cnt++;
    }
  }
  if (n > 2) {
    cnt++;
  }
  return cnt;
}
inline void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  init_code();
  int t;
  cin >> t;
  while (t--) {
    int n, k, input;
    string s;
    cin >> s;
    n = s.length();
    k = 2;
    vector<pair<int, int>> ice;
    vector<int> col(n);
    for (int i = 0; i < n; i++) {
      ice.push_back({s[i] - 'a', i});
    }
    sort(ice.begin(), ice.end());
    int cnt = 0;
    int currcnt = 0;
    vector<int> deku;
    for (int i = 0; i < n; i++) {
      if (i != 0) {
        if (ice[i].first != ice[i - 1].first) {
          currcnt = 1;
          col[ice[i].second] = cnt + 1;
          cnt++;
          deku.push_back(ice[i].second);
        } else {
          if (currcnt < k) {
            col[ice[i].second] = cnt + 1;
            currcnt++;
            cnt++;
            deku.push_back(ice[i].second);
          }
        }
      } else {
        col[ice[i].second] = cnt + 1;
        cnt++;
        currcnt++;
        deku.push_back(ice[i].second);
      }
      if (cnt == k) {
        cnt = 0;
        deku.clear();
      }
    }
    if (cnt != 0) {
      for (int i = 0; i < deku.size(); i++) {
        col[deku[i]] = 0;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (col[i] == 1) {
        ans++;
      }
    }
    cout << ans << endl;
    ice.clear();
    col.clear();
    deku.clear();
  }
  return 0;
}
