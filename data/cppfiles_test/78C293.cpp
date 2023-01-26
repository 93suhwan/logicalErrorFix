#include <bits/stdc++.h>
using namespace std;
long long int compare(string& a, string& b) {
  long long int cnt = 0, j = 0;
  for (int i = 0; i < a.size() && j < b.size(); i++) {
    if (a[i] == b[j]) cnt++, j++;
  }
  return (int)a.size() - cnt + (int)b.size() - cnt;
}
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    if (r / 2 < l)
      cout << r % l << endl;
    else if (r % 2 == 0)
      cout << r / 2 - 1 << endl;
    else
      cout << r / 2 << endl;
  }
  return 0;
}
