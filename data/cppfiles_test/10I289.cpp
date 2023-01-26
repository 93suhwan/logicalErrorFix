#include <bits/stdc++.h>
using namespace std;
int check(int a, int b, int A[]) {
  unordered_map<int, int> mp;
  for (int i = 0; i < a; i++) {
    mp[A[i]]++;
    if (mp[A[i]] <= b) {
      cout << mp[A[i]] << " ";
    } else {
      cout << 0 << " ";
    }
  }
  cout << "\n";
  return 0;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int A;
    int B;
    cin >> A;
    cin >> B;
    int Arr[A];
    for (int j = 0; j < A; j++) {
      cin >> Arr[j];
    }
    check(A, B, Arr);
  }
  return 0;
}
