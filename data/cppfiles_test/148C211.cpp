#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int x, y;
    cin >> x >> y;
    long long int nx, nx1;
    cin >> nx;
    int xc[nx];
    for (int i = 0; i < nx; i++) {
      cin >> xc[i];
    }
    long long int temp = xc[nx - 1] - xc[0];
    cin >> nx1;
    int xc1[nx1];
    for (int i = 0; i < nx1; i++) {
      cin >> xc1[i];
    }
    long long int temp1 = xc1[nx1 - 1] - xc1[0];
    long long int valx = max(temp, temp1) * y;
    long long int ny, ny1;
    cin >> ny;
    int yc[ny];
    for (int i = 0; i < ny; i++) {
      cin >> yc[i];
    }
    temp = yc[ny - 1] - yc[0];
    cin >> ny1;
    int yc1[ny1];
    for (int i = 0; i < ny1; i++) {
      cin >> yc1[i];
    }
    temp1 = yc1[ny1 - 1] - yc1[0];
    long long int valy = max(temp, temp1) * x;
    cout << max(valx, valy) << endl;
  }
  return 0;
}
