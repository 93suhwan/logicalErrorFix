#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> a, b;
map<vector<long long>, bool> banned;
bool comp(vector<long long>& one, vector<long long>& two) {
  long long asum = 0, bsum = 0;
  for (int i = 0; i < one.size(); ++i) {
    asum += a[i][one[i]];
    bsum += a[i][two[i]];
  }
  return asum > bsum;
}
long long sum(vector<long long>& s) {
  long long res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res += a[i][s[i]];
  }
  return res;
}
int main() {
  long long n;
  cin >> n;
  a.resize(n);
  for (long long i = 0; i < n; ++i) {
    long long c;
    cin >> c;
    a[i].resize(c);
    for (long long j = 0; j < c; ++j) cin >> a[i][j];
  }
  long long m;
  cin >> m;
  b.resize(m);
  for (long long i = 0; i < m; ++i) {
    b[i].resize(n);
    for (long long j = 0; j < n; ++j) cin >> b[i][j], b[i][j]--;
    banned[b[i]] = true;
  }
  sort(b.begin(), b.end(), comp);
  vector<long long> ans(n);
  for (long long i = 0; i < n; ++i) ans[i] = a[i].size() - 1;
  long long pos = 0;
  long long mx = LONG_MIN;
  vector<long long> temp;
  if (banned[ans] == false) {
    goto A;
  }
  while (pos < b.size()) {
    ans = b[pos];
    ++pos;
    for (int i = 0; i < n; ++i) {
      if (ans[i] > 0) {
        --ans[i];
        if (mx < sum(ans) && banned[ans] == false) {
          mx = sum(ans);
          temp = ans;
        }
        ++ans[i];
      }
    }
  }
A:
  if (temp.size()) ans = temp;
  for (auto x : ans) {
    cout << x + 1 << " ";
  }
  cout << endl;
  return 0;
}
