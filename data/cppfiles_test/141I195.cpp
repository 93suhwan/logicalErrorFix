#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string a, b;
  long long int z;
  list<char> l1;
  list<char> l2;
  list<char> l3;
  list<char>::iterator p1;
  list<char>::iterator p2;
  list<char>::iterator p3;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    for (z = 0; z < b.size(); z++) l2.push_back(b[b.back() - z]);
    for (z = 0; z < a.size(); z++) l1.push_back(a[a.back() - z]);
    for (z = 0; z < (b.size() - a.size()); z++) l1.push_front(0);
    p1 = l1.begin();
    p2 = l2.begin();
    for (; p2 != l2.end();) {
      if (*p2 > *p1) {
        l3.push_back(*p2 - *p1);
        p2++;
        p1++;
      }
      if (*p2 < *p1) {
        l3.push_back(((*p2) + 10) - (*p1));
        p1++;
        p2++;
        p2++;
      }
      if (*p2 == *p1) {
        l3.push_back('0');
        p2++;
        p1++;
      }
    }
    if (p1 != l1.end())
      cout << "-1";
    else {
      l3.reverse();
      p3 = l3.begin();
      while (*p3 == '0') l3.pop_front();
      for (; p3 != l3.end(); p3++) cout << *p3;
    }
    cout << endl;
  }
  return 0;
}
