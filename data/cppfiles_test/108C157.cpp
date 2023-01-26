#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
bool ans[N];
long long a[N], b[N];
pair<int, long long> a1[N];
bool cmp(pair<int, long long> x, pair<int, long long> y) {
  return x.second > y.second;
}
int main() {
  long long n, t, i, j, now = 0, key, end;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      a1[i].first = i;
      a1[i].second = a[i];
      ans[i] = false;
    }
    for (i = 1; i <= n; i++) {
      cin >> b[i];
    }
    sort(a1 + 1, a1 + 1 + n, cmp);
    key = now = b[a1[1].first];
    end = 1;
    for (i = 1; i <= n; i++) {
      now = min(b[a1[i].first], now);
      if (b[a1[i].first] > key) {
        key = min(key, now);
        end = i;
      }
    }
    for (i = 1; i <= end; i++) {
      ans[a1[i].first] = true;
    }
    for (i = 1; i <= n; i++)
      if (ans[i])
        cout << '1';
      else
        cout << '0';
    cout << '\n';
  }
  return 0;
}
