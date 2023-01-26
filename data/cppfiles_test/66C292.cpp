#include <bits/stdc++.h>
using namespace std;
void fun(int k) {
  int num = 0;
  int count = 0;
  while (count != k) {
    if (num % 10 != 3 && num % 3 != 0) {
      count++;
    }
    num++;
  }
  cout << num - 1 << endl;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    fun(k);
  }
  return 0;
}
