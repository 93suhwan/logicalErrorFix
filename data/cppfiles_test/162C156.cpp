#include <bits/stdc++.h>
using namespace std;
bool fun(int mid, vector<long long> v) {
  vector<long long> v1 = v;
  int n = v.size();
  for (int i = n - 1; i >= 0; i--) {
    if (v1[i] < mid) return false;
    if (i <= 1) continue;
    long long extra = v1[i] - v[i];
    long long c1 = (v[i] + extra - mid) / 3;
    long long c2 = v[i] / 3;
    long long d = min(c1, c2);
    v1[i - 1] += d;
    v1[i - 2] += 2 * d;
  }
  return 1;
}
void I_m_Beast() {
  int n, a;
  cin >> n;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  long long lo = 1, hi = 1e9;
  while (hi - lo > 1) {
    long long mid = (hi + lo) / 2;
    if (fun(mid, v)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  if (fun(hi, v)) {
    cout << hi << endl;
  } else {
    cout << lo << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    I_m_Beast();
  }
  return 0;
}
