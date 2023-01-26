#include <bits/stdc++.h>
using namespace std;
const long long N = 1e3 + 9;
const long long mod = 1000000007;
class Train {
 public:
  int a;
  Train(int a) : a(a) {}
  static Train addTrain() {
    Train t = Train(4);
    t.a = 2;
    return t;
  }
  void add(int num) {
    Train t = Train(num);
    this->a += t.a;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  Train t(4);
  cout << t.a;
  t.add(2);
}
