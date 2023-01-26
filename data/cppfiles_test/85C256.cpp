#include <bits/stdc++.h>
using namespace std;
int main() {
  long long test, tc;
  cin >> test;
  for (tc = 1; tc <= test; tc++) {
    long long i, j, k, s, d, r, m, n;
    string line, temp;
    cin >> line;
    line = "1" + line;
    for (i = 1; i < line.size(); i++)
      if (line[i] == '0' && line[i - 1] == '1') temp.push_back(0);
    if (temp.size() == 0)
      cout << "0" << endl;
    else if (temp.size() == 1)
      cout << "1" << endl;
    else
      cout << "2" << endl;
  }
}
