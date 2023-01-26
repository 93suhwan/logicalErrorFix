#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int gas;
int get_and(int i, int j) {
  gas--;
  assert(gas >= 0);
  cout << "and " << i + 1 << " " << j + 1 << "\n";
  cout.flush();
  int x;
  cin >> x;
  return x;
}
int get_or(int i, int j) {
  gas--;
  assert(gas >= 0);
  cout << "or " << i + 1 << " " << j + 1 << "\n";
  cout.flush();
  int x;
  cin >> x;
  return x;
}
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  gas = 2 * n;
  vector<int> A(n), B(n);
  for (int i = 1; i < n; i++) {
    A[i] = get_and(0, i);
  }
  for (int i = 1; i < n; i++) {
    B[i] = get_or(0, i);
  }
  vector<int> C(n);
  for (int i = 1; i < n; i++) {
    C[i] = B[i] - A[i];
  }
  ll X = B[1] | B[2];
  ll Y = get_and(1, 2);
  X -= A[1];
  X -= A[2];
  X -= Y;
  X += 2 * (A[1] & A[2] & Y);
  ll W = get_or(1, 2);
  ll Z = W - Y;
  ll a = X ^ Z;
  vector<int> v;
  v.push_back(a);
  for (int i = 1; i < n; i++) {
    v.push_back(a ^ C[i]);
  }
  sort(v.begin(), v.end());
  cout << v[k - 1] << "\n";
  return 0;
}
