#include <bits/stdc++.h>
using namespace std;
void func(vector<int> &a, vector<int> &b, int n) {
  int i = 0;
  while (i < n) {
    int v1 = a[i], v2 = a[i + 1];
    b.push_back(-v2);
    b.push_back(v1);
    i += 2;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      a.push_back(tmp);
    }
    vector<int> b;
    if (n % 2 == 0) {
      func(a, b, n);
    } else {
      func(a, b, n - 3);
      int v1 = a[n - 3], v2 = a[n - 2], v3 = a[n - 1];
      if (v1 + v2 != 0) {
        int v4 = v1 + v2;
        b.push_back(-v3);
        b.push_back(-v3);
        b.push_back(v4);
      } else if (v2 + v3 != 0) {
        int v4 = v3 + v2;
        b.push_back(v4);
        b.push_back(-v1);
        b.push_back(-v1);
      } else {
        int v4 = v3 + v1;
        b.push_back(-v2);
        b.push_back(v4);
        b.push_back(-v2);
      }
    }
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << "\n";
  }
}
