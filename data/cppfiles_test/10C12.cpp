#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll P = 1e9 + 7;
ll N, M, K, R, C;
ll Dx, Dy;
ll mult(ll a, ll b) { return (a * b) % P; }
ll exp(ll num_classes) {
  if (num_classes == 0) {
    return 1;
  }
  ll temp = exp(num_classes / 2);
  return (num_classes % 2) ? mult(K, mult(temp, temp)) : mult(temp, temp);
}
void input() {
  ll Ax, Ay, Bx, By;
  cin >> N >> M >> K >> R >> C;
  cin >> Ax >> Ay >> Bx >> By;
  Dx = (Ax > Bx) ? Ax - Bx : Bx - Ax;
  Dy = (Ay > By) ? Ay - By : By - Ay;
}
ll count_classes() {
  ll overlap = ((R > Dx) ? R - Dx : 0) * ((C > Dy) ? C - Dy : 0);
  ll classes = N * M - (2 * R * C - overlap);
  if (overlap == 0) {
    return classes + R * C;
  }
  if (Dx == 0 && Dy == 0) {
    return classes + R * C;
  }
  return classes + (R * Dy) + (C * Dx) - Dx * Dy;
}
int main() {
  input();
  cout << exp(count_classes()) << endl;
}
