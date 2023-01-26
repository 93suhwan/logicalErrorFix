#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  while (test) {
    long long w, h;
    cin >> w >> h;
    int side = 0;
    long long d = 0;
    long long area1 = 0;
    long long a;
    cin >> a;
    long long array[a];
    for (long long i = 0; i < a; i++) {
      cin >> array[i];
    }
    d = array[a - 1] - array[0];
    side = 1;
    area1 = d * h;
    long long b;
    cin >> b;
    long long array1[b];
    for (long long i = 0; i < b; i++) {
      cin >> array1[i];
    }
    long long d1 = array1[b - 1] - array1[0];
    long long area2 = d1 * h;
    if (area2 > area1) {
      area1 = area2;
    }
    long long c;
    cin >> c;
    long long array2[c];
    for (long long i = 0; i < c; i++) {
      cin >> array2[i];
    }
    long long d2 = array2[c - 1] - array2[0];
    long long area3 = d2 * w;
    if (area3 > area1) {
      area1 = area3;
    }
    long long dx;
    cin >> dx;
    long long array3[dx];
    for (long long i = 0; i < dx; i++) {
      cin >> array3[i];
    }
    long long d3 = array3[dx - 1] - array3[0];
    long long area4 = d3 * w;
    if (area4 > area1) {
      area1 = area4;
    }
    cout << area1 << endl;
    test--;
  }
  return 0;
}
