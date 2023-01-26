#include <bits/stdc++.h>
using namespace std;
vector<int> r(100005);
vector<int> p(100005);
int find_set(int x) {
  if (p[x] == x) return x;
  p[x] = find_set(p[x]);
  return p[x];
}
void make_pair1(int x, int y) {
  int p1 = find_set(x);
  int p2 = find_set(y);
  if (p1 == p2) return;
  if (r[p1] >= r[p2]) {
    r[p1] = r[p1] + r[p2];
    p[p2] = p1;
  } else {
    r[p2] = r[p2] + r[p1];
    p[p1] = p2;
  }
}
void want() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n == 1) {
    cout << "YES" << endl;
    return;
  }
  if (k < 2) {
    cout << "NO" << endl;
    return;
  }
  if (k > 3) {
    cout << "YES" << endl;
    return;
  }
  long long max1 = n * (n - 1);
  max1 /= 2;
  long long min1 = n - 1;
  if (m < min1) {
    cout << "NO" << endl;
    return;
  }
  if (m > max1) {
    cout << "NO" << endl;
    return;
  }
  if (m == max1) {
    if (k > 2) {
      cout << "YES" << endl;
      return;
    } else {
      cout << "NO" << endl;
      return;
    }
  } else {
    cout << "NO" << endl;
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    want();
  }
}
