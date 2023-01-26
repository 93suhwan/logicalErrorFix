#include <bits/stdc++.h>
#pragma GCC optimize("O4,unroll-loops,no-stack-protector")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
void Why_does_competitive_programming_even_exist() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void YayXD() { return; }
pair<long long, long long> arr[100005];
int ans[100005];
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  return abs(a.first) < abs(b.first);
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b % a, a);
}
signed main() {
  Why_does_competitive_programming_even_exist();
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> arr[i].first;
      arr[i].second = i;
    }
    if (n % 2 == 0) {
      for (long long i = 1; i <= n; i += 2) {
        cout << arr[i + 1].first << " " << -arr[i].first << " ";
      }
      cout << "\n";
      continue;
    }
    sort(arr + 1, arr + 1 + n, comp);
    long long a = abs(arr[1].first), b = abs(arr[2].first),
              c = abs(arr[3].first), g = gcd(a, gcd(b, c));
    a /= g;
    b /= g;
    c /= g;
    if (b == c) {
      long long x = b * 2, y = a;
      if (arr[1].first > 0)
        ans[arr[1].second] = -x;
      else
        ans[arr[1].second] = x;
      if (arr[2].first > 0)
        ans[arr[2].second] = y;
      else
        ans[arr[2].second] = -y;
      if (arr[3].first > 0)
        ans[arr[3].second] = y;
      else
        ans[arr[3].second] = -y;
    } else {
      long long y = a, x = c - b;
      if (arr[1].first > 0)
        ans[arr[1].second] = -x;
      else
        ans[arr[1].second] = x;
      if (arr[2].first > 0)
        ans[arr[2].second] = -y;
      else
        ans[arr[2].second] = y;
      if (arr[3].first > 0)
        ans[arr[3].second] = y;
      else
        ans[arr[3].second] = -y;
    }
    for (long long i = 4; i <= n; i += 2) {
      ans[arr[i].second] = -arr[i + 1].first;
      ans[arr[i + 1].second] = arr[i].first;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
  }
}
