#include <bits/stdc++.h>
using namespace std;
int md = 1e9 + 7;
void sahiljit() {}
bool check(string s) {
  int i = 0;
  int j = s.length() - 1;
  while (i < j) {
    if (s[i] != s[j])
      return false;
    else {
      i++;
      j--;
    }
  }
  return true;
}
int main() {
  sahiljit();
  vector<int> val1(3, 1);
  vector<int> val2(1, 5);
  val2 = val1;
  val1 = vector<int>();
  cout << "Size of val1 " << int(val1.size()) << "\n";
  cout << "Size of val2 " << int(val2.size()) << "\n";
}
