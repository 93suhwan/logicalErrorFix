#include <bits/stdc++.h>
using namespace std;
long long int fp(long long int n, long long int p) {
  if (p == 0) return 1;
  if (p == 1) return n;
  long long int res = fp(n, p / 2) % (long long)(1e9 + 7);
  res = ((res) * (res)) % (long long)(1e9 + 7);
  if (p % 2) res = (res * n) % (long long)(1e9 + 7);
  return res;
}
string tostring(long long int a) {
  string s = "";
  while (a > 0) {
    char c = a % 10 + '0';
    s.push_back(c);
    a /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
int t, n, k, x, arr[200005];
int main() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  ;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    memset(arr, -1, sizeof arr);
    vector<vector<int>> v(11);
    for (int i = 0; i < n; i++) {
      cin >> x;
      v[x].push_back(i);
    }
    int c = 0, cnt = 0, cnnt = 0;
    for (auto i : v) {
      if (int(i.size()) >= k) {
        for (int j = 0; j < k; j++) arr[i[j]] = j + 1;
      } else
        c++;
    }
    c /= k;
    c *= k;
    for (auto i : v) {
      if (int(i.size()) < k) {
        for (int j = 0; j < int(i.size()) && cnnt < c; j++) {
          arr[i[j]] = cnt + 1;
          cnt = (cnt + 1) % k;
          cnnt++;
        }
      }
      if (cnnt >= c) break;
    }
    for (int i = 0; i < n; i++)
      if (arr[i] == -1)
        cout << 0 << " ";
      else
        cout << arr[i] << " ";
    cout << '\n';
  }
  return 0;
}
