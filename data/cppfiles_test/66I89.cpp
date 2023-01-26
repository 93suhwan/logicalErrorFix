#include <bits/stdc++.h>
using namespace std;
int k, t;
int a[1000003];
void find_dislikes_numbers_of_Poly(int n) {
  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0 or i % 10 == 3) {
      a[i] = 1;
    }
  }
}
void citire() {
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> k;
    int j = 1;
    int number = 1;
    while (j < k) {
      if (a[number] == 0) {
        j++;
      }
      number++;
    }
    cout << number;
  }
}
int main() {
  find_dislikes_numbers_of_Poly(100000);
  citire();
  return 0;
}
