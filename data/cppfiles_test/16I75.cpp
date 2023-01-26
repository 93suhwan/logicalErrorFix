#include <bits/stdc++.h>
using namespace std;
int bs(int i, int j, pair<int, int> a[], int target) {
  if (i == j) return a[i].second;
  int mid = (i + j) / 2;
  if (target <= a[mid].first)
    return bs(i, mid, a, target);
  else
    return bs(mid + 1, j, a, target);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> ind(k, 0);
    for (long long i = 0; i < k; i++) cin >> ind[i];
    vector<long long> temp(k, 0);
    for (long long i = 0; i < k; i++) cin >> temp[i];
    vector<long long> L(n, 1e10), R(n, 1e10);
    for (long long i = 0; i < k; i++) {
      L[ind[i] - 1] = temp[i];
      R[ind[i] - 1] = temp[i];
    }
    long long mini = 1e10;
    for (long long i = 0; i < n; i++) {
      L[i] = min(L[i], mini + 1);
      mini = L[i];
    }
    mini = 1e10;
    for (int i = n - 1; i >= 0; i--) {
      R[i] = min(R[i], mini + 1);
      mini = R[i];
    }
    for (long long i = 0; i < n; i++) {
      L[i] = min(L[i], R[i]);
    }
    for (long long i = 0; i < n; i++) cout << L[i] << " ";
    cout << "\n";
  }
  return 0;
}
