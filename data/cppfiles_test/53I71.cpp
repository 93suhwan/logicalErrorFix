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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<vector<int>> c;
    for (int i = 0; i < n; i++) {
      vector<int> x;
      x.push_back(v[i]);
      int j = i + 1;
      while (j < n && v[j] > v[j - 1]) {
        j += 1;
      }
      x.push_back(v[j - 1]);
      c.push_back(x);
      i = j - 1;
    }
    if (c.size() > k) {
      cout << "NO\n";
      continue;
    }
    if (c.size() == 1) {
      cout << "YES\n";
      continue;
    }
    sort(c.begin(), c.end(), comp);
    for (int i = 0; i < c.size() - 1; i++) {
      if (c[i][1] > c[i + 1][0]) {
        cout << "NO\n";
        break;
      }
      if (i == c.size() - 2) {
        cout << "YES\n";
      }
    }
  }
}
