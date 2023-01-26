#include <bits/stdc++.h>
using namespace std;
int shogan(int* mass, int n) {
  int i_counter = 0;
  for (int i = 0; i < n; i++) {
    if (mass[i] > i + 1 + i_counter) {
      i_counter += mass[i] - (i + 1 + i_counter);
    }
  }
  return i_counter;
}
int main() {
  int k, n;
  cin >> k;
  int* finish = new int[k];
  for (int j = 0; j < k; j++) {
    cin >> n;
    int* mass = new int[n];
    for (int i = 0; i < n; i++) {
      cin >> mass[i];
    }
    finish[j] = shogan(mass, n);
  }
  for (int j = 0; j < k; j++) {
    cout << finish[j] << "\n";
  }
  return 0;
}
