#include <bits/stdc++.h>
using namespace std;
const int MaxN = 200200;
long long a[MaxN];
long long gcd(long long a, long long b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long query(long long h, long long l, long long r,
                vector<vector<long long> > &arr) {
  if (l == r) {
    return arr[h][l];
  }
  if (l % 2 == 0 && r % 2 == 1) {
    return query(h + 1, l / 2, r / 2, arr);
  }
  if (l % 2 == 1) {
    return gcd(arr[h][l], query(h, l + 1, r, arr));
  }
  if (r % 2 == 0) {
    return gcd(query(h, l, r - 1, arr), arr[h][r]);
  }
}
bool func(int M, vector<vector<long long> > &arr) {
  for (int i = 0; i + M - 1 < arr[0].size(); i++) {
    if (query(0, i, i + M - 1, arr) > 1) {
      return true;
    }
  }
  return false;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 1 << endl;
    return;
  } else if (n == 2) {
    if (abs(a[1] - a[0]) == 1) {
      cout << 1 << endl;
      return;
    } else {
      cout << 2 << endl;
      return;
    }
  }
  vector<vector<long long> > arr(1);
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
  int lower = 1;
  int upper = arr[0].size();
  while (upper > lower) {
    int m = (upper + lower + 1) / 2;
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
