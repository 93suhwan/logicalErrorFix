#include <bits/stdc++.h>
using namespace std;
int find(int a, int b, int c) {
  int diff;
  diff = abs(a - b);
  int total = 2 * diff;
  if (total < c || total < a || total < b)
    return -1;
  else {
    int answer = abs(c + diff);
    if (answer <= total)
      return answer;
    else
      return abs(c - diff);
  }
}
int main() {
  int t;
  cin >> t;
  int outp[t];
  for (int i = 0; i < t; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    outp[i] = find(a, b, c);
  }
  for (int i = 0; i < t; i++) {
    cout << outp[i] << "\n";
  }
  return 0;
}
