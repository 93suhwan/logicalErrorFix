#include <bits/stdc++.h>
using namespace std;
void length(vector<int> &A, int n) {
  while (n) {
    A.push_back(n % 10);
    n = n / 10;
  }
  int l = A.size();
  for (int i = 0; i < l / 2; i++) {
    int t = A[i];
    A[i] = A[l - 1 - i];
    A[l - i - 1] = t;
  }
  return;
}
void find(int n) {
  vector<int> Arr;
  length(Arr, n);
  int l = Arr.size();
  int a = 0;
  for (int i = 0; i < l; i += 2) {
    a = a * 10 + Arr[i];
  }
  int b = 0;
  for (int i = 1; i < l; i += 2) {
    b = b * 10 + Arr[i];
  }
  cout << ((a + 1) * (b + 1) - 2);
  cout << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    find(n);
  }
  return 0;
}
