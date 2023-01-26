#include <bits/stdc++.h>
using namespace std;
void Function() {
  vector<long long> v(7);
  for (int i = 0; i < 7; i++) {
    cin >> v[i];
  }
  long long a = v[0];
  long long b = v[1];
  long long c = v[2];
  if (c == a + b) {
    c = v[3];
  }
  cout << a << " " << b << " " << c << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    Function();
  }
  return 0;
}
