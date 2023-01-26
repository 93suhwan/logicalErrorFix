#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vb = vector<bool>;
using vc = vector<char>;
using vd = vector<double>;
using vi = vector<int>;
using vvi = vector<vi>;
using vlli = vector<lli>;
using vvlli = vector<vlli>;
using pi = pair<int, int>;
using plli = pair<lli, lli>;
int readint() {
  int q;
  scanf("%d", &q);
  return q;
}
lli readlong() {
  lli q;
  scanf("%lld", &q);
  return q;
}
double readdbl() {
  double q;
  scanf("%lf", &q);
  return q;
}
char readc() {
  char q;
  scanf("%c", &q);
  return q;
}
void printint(int q) { printf("%d", q); }
void printlong(lli q) { printf("%lld", q); }
void printdbl(double q, int p = 6) { printf("%.*lf", p, q); }
void readln() { scanf("\n"); }
void println() { printf("\n"); }
void space() { printf(" "); }
void print(int q) { printint(q); }
void print(lli q) { printlong(q); }
void print(double q) { printdbl(q); }
void print(char c) { printf("%c", c); }
template <typename T>
void println(T q) {
  print(q);
  println();
}
template <typename T>
void printsp(T q) {
  print(q);
  space();
}
template <typename T>
T maxim(T f, T s) {
  return (f > s) ? f : s;
}
template <typename T>
T minim(T f, T s) {
  return (f < s) ? f : s;
}
template <typename T>
T abs(T arg) {
  return arg < 0 ? -arg : arg;
}
int main() {
  int t = readint();
  for (lli l = 0; l < t; ++l) {
    int n = readint();
    int k = n / 2;
    for (int i = 0; i < k - 1; ++i) print('a');
    if (n > 1) print('b');
    for (int i = 0; i < k; ++i) print('a');
    if (n & 1) print('c');
    println();
  }
  return 0;
}
