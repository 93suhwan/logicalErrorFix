#include <bits/stdc++.h>
using namespace std;
long long int a[500005], b[500005], c[500005], d[500005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, i, j, k, n, m, w, y, z, x, l, r, k1, k2;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; i += 3) {
      cout << "? " << i << " " << (i % n) + 1 << " " << ((i + 1) % n) + 1
           << endl;
      cin >> a[i / 3];
    }
    a[n / 3] = a[0];
    vector<int> v;
    for (i = 0; i < n / 3; i++) {
      if (a[i] == 0 && a[i + 1] == 1) {
        break;
      }
    }
    for (i = 3 * i + 2;; i++) {
      cout << "? " << i << " " << (i % n) + 1 << " " << ((i + 1) % n) + 1
           << endl;
      cin >> x;
      if (x) {
        v.push_back(i - 1);
        y = (i + 1) % n + 1;
        break;
      }
    }
    for (i = 0; i < n / 3; i++) {
      if (i == (v[0] - 1) / 3 || i == (y - 1) / 3) {
        for (j = i * 3 + 1; j <= i * 3 + 3; j++) {
          if (j == v[0] || j == y) continue;
          cout << "? " << v[0] << " " << y << " " << j << endl;
          cin >> x;
          if (x == 0) v.push_back(j);
        }
      } else if (a[i]) {
        cout << "? " << i * 3 + 1 << " " << v[0] << " " << i * 3 + 2 << endl;
        cin >> x;
        if (x) {
          cout << "? " << v[0] << " " << y << " " << i * 3 + 3 << endl;
          cin >> x;
          if (x == 0) v.push_back(i * 3 + 3);
        } else {
          cout << "? " << v[0] << " " << y << " " << i * 3 + 1 << endl;
          cin >> x;
          if (x == 0)
            v.push_back(i * 3 + 1);
          else
            v.push_back(i * 3 + 2);
        }
      } else {
        cout << "? " << i * 3 + 1 << " " << y << " " << i * 3 + 2 << endl;
        cin >> x;
        if (x == 0) {
          v.push_back(i * 3 + 1);
          v.push_back(i * 3 + 2);
          cout << "? " << v[0] << " " << y << " " << i * 3 + 3 << endl;
          cin >> x;
          if (x == 0) v.push_back(i * 3 + 3);
        } else {
          v.push_back(i * 3 + 3);
          cout << "? " << v[0] << " " << y << " " << i * 3 + 1 << endl;
          cin >> x;
          if (x == 0)
            v.push_back(i * 3 + 1);
          else
            v.push_back(i * 3 + 2);
        }
      }
    }
    cout << "! " << v.size() << " ";
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
  }
}
