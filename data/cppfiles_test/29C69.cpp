#include <bits/stdc++.h>
using namespace std;
struct FenwickTree {
  vector<long long int> bit;
  int n;
  FenwickTree(int n) {
    this->n = n;
    bit.assign(n, 0);
  }
  FenwickTree(vector<long long int> a) : FenwickTree(a.size()) {
    for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
  }
  long long int sum(int r) {
    long long int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
    return ret;
  }
  long long int sum(int l, int r) { return sum(r) - sum(l - 1); }
  void add(int idx, long long int delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
  }
};
const int MAX_VAL = 3e5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long int> a(n);
  vector<long long int> ra(MAX_VAL + 5, -1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ra[a[i]] = i;
  }
  vector<long long int> tr(n);
  vector<long long int> ctr(MAX_VAL + 5);
  int cidx = 0;
  for (int i = 1; i <= MAX_VAL; ++i) {
    if (ra[i] != -1) {
      tr[ra[i]] = cidx;
      cidx++;
    }
    ctr[i] = cidx - 1;
  }
  long long int csum = 0;
  long long int tsum = 0;
  FenwickTree fw(n);
  FenwickTree fw2(n);
  for (int i = 0; i < n; ++i) {
    csum += tsum + a[i] * fw2.sum(tr[i]);
    for (long long int k = 1; k * k <= a[i]; ++k) {
      csum -= fw.sum(ctr[a[i] / k]);
      if (a[i] / k > k) {
        csum -= (a[i] / k - a[i] / (k + 1)) * fw.sum(ctr[k]);
      }
    }
    for (long long int k = 2; k * a[i] <= MAX_VAL; ++k) {
      csum -= a[i] * (i - fw2.sum(ctr[k * a[i] - 1]));
    }
    cout << csum << " ";
    tsum += a[i];
    fw.add(tr[i], a[i]);
    fw2.add(tr[i], 1);
  }
  cout << endl;
}
