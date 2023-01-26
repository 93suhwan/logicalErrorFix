#include <bits/stdc++.h>
using namespace std;
const int MaxN = 200200;
int a[MaxN];
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}
long long query(int h, int l, int r, vector<vector<long long> > &arr) {
  if (l == r) {
    return arr[h][l];
  }
  if (l % 2 == 0 && r % 2 == 1) {
    return query(h + 1, l / 2, r / 2, arr);
  }
  if (l % 2 == 1) {
    if (arr[h][l] == 1) {
      return 1;
    } else {
      return gcd(arr[h][l], query(h + 1, (l + 1) / 2, r / 2, arr));
    }
  }
  if (r % 2 == 0) {
    if (arr[h][r] == 1) {
      return 1;
    } else {
      return gcd(query(h + 1, l / 2, (r - 1) / 2, arr), arr[h][r]);
    }
  }
}
bool func(int M, vector<vector<long long> > &arr) {
  for (int i = 0; i < arr[0].size() - M + 1; i++) {
    if (query(0, i, i + M - 1, arr) > 1) {
      return true;
    }
  }
  return false;
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long> > arr(1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; i++) {
    arr[0].push_back(abs(a[i + 1] - a[i]));
  }
  int h = 0;
  while (arr[h].size() > 1) {
    vector<long long> newrow;
    for (int i = 0; i < arr[h].size() / 2; i++) {
      newrow.push_back(gcd(arr[h][2 * i], arr[h][2 * i + 1]));
    }
    arr.push_back(newrow);
    h++;
  }
  h++;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  int lower = 1;
  int upper = n - 1;
  while (upper > lower) {
    int m = (lower + upper + 1) / 2;
    if (func(m, arr)) {
      lower = m;
    } else {
      upper = m - 1;
    }
  }
  cout << lower + 1 << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
