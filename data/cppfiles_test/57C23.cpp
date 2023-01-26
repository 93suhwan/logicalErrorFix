#include <bits/stdc++.h>
using namespace std;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
int ways(int s, int n, int k) {
  if (n > s) return 0;
  vector<int> a(s - n, 0);
  vector<int> b(n);
  while (true) {
    fill((b).begin(), (b).end(), 1);
    for (int i = (0); i < (s - n); i++) b[a[i]]++;
    bool ok = true;
    for (int i = (0); i < (n); i++) {
      int cnt = 0;
      for (int j = (i); j < (n); j++) {
        cnt += b[j];
        if (cnt == k) {
          ok = false;
        }
      }
    }
    if (ok) return 2;
    int idx = 0;
    while (idx < s - n && a[idx] == n - 1) {
      a[idx] = 0;
      idx++;
    }
    if (idx == s - n) break;
    a[idx]++;
  }
  return 1;
}
int solve(long long s, long long n, long long k) {
  if (n > s) return 0;
  if (n < k) {
    return s == k ? 1 : 2;
  }
  long long amt = (n / k) * k;
  return s < n + amt ? 1 : 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int te;
  cin >> te;
  while (te--) {
    long long s, n, k;
    cin >> s >> n >> k;
    cout << (solve(s, n, k) == 1 ? "YES\n" : "NO\n");
  }
}
