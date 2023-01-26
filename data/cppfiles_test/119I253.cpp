#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  for (int i = 0; i < a; i++) {
    int b;
    cin >> b;
    int arr[b];
    for (int j = 0; j < b; j++) {
      cin >> arr[j];
    }
    int sum = 0;
    for (int j = 0; j < b; j++) {
      sum = sum + arr[j];
    }
    if (sum % b == 0) {
      cout << "0";
    } else
      cout << "1";
  }
}
