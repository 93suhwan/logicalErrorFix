#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, a, b;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    vector<int> V(n), W(n);
    for (int i = 0; i < n; i++) V[i] = i + 1;
    for (int i = n - 1; i >= 0; i--) W[i] = i + 1;
    if (abs(a - b) > 1 || (a + b - 2) > n)
      cout << "-1" << endl;
    else if (a == b) {
      int i = 1;
      while (a--) {
        swap(V[i], V[i + 1]);
        i = i + 2;
      }
      for (int i = 0; i < n; i++) cout << V[i] << " ";
      cout << endl;
    } else if (a < b) {
      int i = 0;
      while (b--) {
        swap(V[i], V[i + 1]);
        i = i + 2;
      }
      for (int i = 0; i < n; i++) cout << V[i] << " ";
      cout << endl;
    } else if (a > b) {
      int i = 0;
      while (a--) {
        swap(W[i], W[i + 1]);
        i = i + 2;
      }
      for (int i = 0; i < n; i++) cout << V[i] << " ";
      cout << endl;
    }
  }
}
