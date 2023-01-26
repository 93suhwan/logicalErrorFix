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
  int res[n];
  for (int i = 0; i < n; i++) {
    res[i] = 1;
  }
  for (int i = 0; i < Arr.size(); i++) {
    cout << Arr[i] << " ";
  }
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
