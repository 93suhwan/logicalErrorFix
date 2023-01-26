#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool check_prime(int a) {
  for (int i = sqrt(a); i > 1; i--) {
    if (a % i == 0) return false;
  }
  return true;
}
template <typename T>
void dv_2d(vector<vector<T>>& v) {
  for (auto x : v)
    for (auto y : x) cout << y << " ";
  cout << "\n";
}
template <typename T>
void dv(vector<T> v) {
  for (auto x : v) cout << x << " ";
  cout << '\n';
}
bool comp(const vector<int>& v1, const vector<int>& v2) {
  return v1[0] < v2[0];
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
      cin >> v[i][0];
      v[i][1] = i;
    }
    sort(v.begin(), v.end(), comp);
    int i = 0;
    int s = 0;
    while (i < n) {
      int ind = v[i][1];
      int j = i + 1;
      while (j < n && v[j][1] == v[j - 1][1] + 1) {
        j += 1;
      }
      s += 1;
      i = j;
    }
    if (s > k && s != 1) {
      cout << "NO\n";
      continue;
    } else {
      cout << "YES\n";
    }
  }
}
