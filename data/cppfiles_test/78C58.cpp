#include <bits/stdc++.h>
using namespace std;
void fill(long long int a, vector<int> &X) {
  int i = 0;
  while (a > 0) {
    if (a % 2 == 1) {
      X[i]++;
    }
    a = a / 2;
    i++;
  }
  return;
}
int gcd(int a, int b) {
  if (a == 0) {
    return b;
  }
  if (b == 0 || a == b) {
    return a;
  }
  return gcd(a % b, b % a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    vector<long long int> A(n);
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    vector<int> X(50);
    for (int i = 0; i < n; i++) {
      fill(A[i], X);
    }
    int x = 0;
    for (int i = 0; i < 50; i++) {
      x = gcd(X[i], x);
    }
    for (int i = 1; i <= n; i++) {
      if (x % i == 0) {
        cout << i << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
