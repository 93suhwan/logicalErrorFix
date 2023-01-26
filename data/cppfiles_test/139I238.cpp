#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquareString(string str) {
  int sum = 0;
  int len = str.length();
  for (int i = 0; i < len; i++) sum += (int)str[i];
  long double squareRoot = sqrt(sum);
  return ((squareRoot - floor(squareRoot)) == 0);
}
int main() {
  string str = "d";
  if (isPerfectSquareString(str))
    cout << "Yes";
  else
    cout << "No";
}
