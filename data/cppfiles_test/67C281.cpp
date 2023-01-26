#include <bits/stdc++.h>
using namespace std;
int char_to_int(char c) {
  int x = c - 48;
  return x;
}
char int_to_char(int x) {
  int c = x + 48;
  return c;
}
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
map<int, int> mp;
vector<int> v;
map<int, vector<int> > G;
map<int, int> visited;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
struct node {
  int roll;
  node *next;
};
int main() {
  fast();
  int tst;
  cin >> tst;
  while (tst--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long check = abs(a - b);
    check *= 2;
    if (a > check || b > check || c > check) {
      cout << -1 << endl;
    } else if (check / 2 + c <= check) {
      cout << check / 2 + c << endl;
    } else if (c - check / 2 > 0) {
      cout << c - check / 2 << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
