#include <bits/stdc++.h>
using namespace std;
int query(int i, int j) {
  int answer;
  cout << "? " << i << " " << j << endl;
  cin >> answer;
  return answer;
}
int main(int argc, char* argv[]) {
  int bl = query(1, 1);
  int br = query(1000000000, 1);
  int tr = query(1000000000, 1000000000);
  int tl = query(1, 1000000000);
  int b = query((bl + 1 + 1000000000 - br) / 2, 1);
  int r = query(1000000000, (br + 1 + 1000000000 - tr) / 2);
  int t = query((tl + 1 + 1000000000 - tr) / 2, 1000000000);
  int l = query(1, (bl + 1 + 1000000000 - tl) / 2);
  cout << "! " << l + 1 << " " << b + 1 << " " << 1000000000 - r << " "
       << 1000000000 - t << endl;
  cout.flush();
}
