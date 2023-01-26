#include <bits/stdc++.h>
using namespace std;
void input(vector<int> &a, int n) {
  for (int i = 0; i < n; i += 1) cin >> a[i];
}
void display(vector<int> &a) {
  for (int i = 0; i < a.size(); i += 1) cout << a[i] << " ";
  cout << "\n";
}
bool isFeasible(vector<long long> &s, long long k, long long swaps) {
  int low = s[0];
  long long len = s.size() - 1;
  int n = min(len, swaps);
  if (swaps > n) low -= (swaps - len);
  while (n) {
    if (s[len - n] - s[0] + low + low * n <= k) return true;
    low--;
    n--;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    input(a, n);
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum <= k) {
      cout << "0\n";
      continue;
    }
    sort(a.begin(), a.end());
    long long low = 0, high = n - 1 + max(a[0] - (k / n), 0LL);
    vector<long long> s(n, 0);
    s[0] = a[0];
    for (int i = 1; i < n; i += 1) {
      s[i] = s[i - 1] + a[i];
    }
    long long mid, res = high;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (isFeasible(s, k, mid)) {
        res = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }
    cout << min(res, sum - k) << "\n";
  }
  return 0;
}
