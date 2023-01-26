#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
int a[maxn], b[maxn], c[maxn], d[maxn], e[maxn];
int n;
int get_a() {
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    long long sum = a[i];
    long long now = b[i] + c[i] + d[i] + e[i];
    ans.push_back(sum - now);
  }
  sort(ans.rbegin(), ans.rend());
  long long k = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (k + ans[i] > 0LL) {
      cnt++;
      k += ans[i];
    } else
      break;
  }
  return cnt;
}
int get_b() {
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    long long sum = b[i];
    long long now = a[i] + c[i] + d[i] + e[i];
    ans.push_back(sum - now);
  }
  sort(ans.rbegin(), ans.rend());
  long long k = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (k + ans[i] > 0LL) {
      cnt++;
      k += ans[i];
    } else
      break;
  }
  return cnt;
}
int get_c() {
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    long long sum = c[i];
    long long now = a[i] + b[i] + d[i] + e[i];
    ans.push_back(sum - now);
  }
  sort(ans.rbegin(), ans.rend());
  long long k = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (k + ans[i] > 0LL) {
      cnt++;
      k += ans[i];
    } else
      break;
  }
  return cnt;
}
int get_d() {
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    long long sum = d[i];
    long long now = a[i] + b[i] + c[i] + e[i];
    ans.push_back(sum - now);
  }
  sort(ans.rbegin(), ans.rend());
  long long k = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (k + ans[i] > 0LL) {
      cnt++;
      k += ans[i];
    } else
      break;
  }
  return cnt;
}
int get_e() {
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    long long sum = e[i];
    long long now = a[i] + b[i] + c[i] + d[i];
    ans.push_back(sum - now);
  }
  sort(ans.rbegin(), ans.rend());
  long long k = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (k + ans[i] > 0LL) {
      cnt++;
      k += ans[i];
    } else
      break;
  }
  return cnt;
}
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i <= n; i++) a[i] = b[i] = c[i] = d[i] = e[i] = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); j++) {
        if (s[j] == 'a')
          a[i]++;
        else if (s[j] == 'b')
          b[i]++;
        else if (s[j] == 'c')
          c[i]++;
        else if (s[j] == 'd')
          d[i]++;
        else if (s[j] == 'e')
          e[i]++;
      }
    }
    int ans = 0;
    ans = max(ans, get_a());
    ans = max(ans, get_b());
    ans = max(ans, get_c());
    ans = max(ans, get_d());
    ans = max(ans, get_e());
    cout << ans << endl;
  }
  return 0;
}
