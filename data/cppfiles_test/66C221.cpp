#include <bits/stdc++.h>
using namespace std;
void generate_list_poly(int* list1, int n) {
  for (int i = 1; i < 30; i++) {
    if ((i % 3) != 0 && ((i % 10) != 3)) {
      list1[n] = i;
      n++;
    }
  }
}
int polyK(int k, int* listK) {
  int fact = k / 18;
  int rem = k % 18;
  return (30 * fact + listK[rem]);
}
int main() {
  int t;
  cin >> t;
  int list1[40];
  generate_list_poly(list1, 0);
  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    cout << polyK(k - 1, list1) << '\n';
  }
}
