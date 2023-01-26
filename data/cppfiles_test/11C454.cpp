#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct QZ {
  int a;
  int b;
  int c;
  int d;
  int e;
  int tol;
};
QZ qz[N];
bool cmpa(const QZ &A, const QZ &B) { return A.a > B.a; }
bool cmpb(const QZ &A, const QZ &B) { return A.b > B.b; }
bool cmpc(const QZ &A, const QZ &B) { return A.c > B.c; }
bool cmpd(const QZ &A, const QZ &B) { return A.d > B.d; }
bool cmpe(const QZ &A, const QZ &B) { return A.e > B.e; }
int main() {
  int t;
  cin >> t;
  for (int f = 1; f <= t; f++) {
    int n;
    cin >> n;
    long long int ans = 0;
    long long int temp = 0;
    long long int sum = 0;
    for (int i = 1; i <= n; i++) {
      int a = 0, b = 0, c = 0, d = 0, e = 0;
      string s;
      cin >> s;
      qz[i].tol = s.length();
      for (int temp = 0; temp < qz[i].tol; temp++) {
        if (s[temp] == 'a') a++;
        if (s[temp] == 'b') b++;
        if (s[temp] == 'c') c++;
        if (s[temp] == 'd') d++;
        if (s[temp] == 'e') e++;
      }
      qz[i].a = a * 2 - qz[i].tol;
      qz[i].b = b * 2 - qz[i].tol;
      qz[i].c = c * 2 - qz[i].tol;
      qz[i].d = d * 2 - qz[i].tol;
      qz[i].e = e * 2 - qz[i].tol;
    }
    temp = 0;
    sum = 0;
    sort(qz + 1, qz + n + 1, cmpa);
    for (int i = 1; i <= n; i++) {
      if (sum + qz[i].a > 0) {
        sum += qz[i].a;
        temp++;
      } else
        break;
    }
    ans = max(ans, temp);
    temp = 0;
    sum = 0;
    sort(qz + 1, qz + n + 1, cmpb);
    for (int i = 1; i <= n; i++) {
      if (sum + qz[i].b > 0) {
        sum += qz[i].b;
        temp++;
      } else
        break;
    }
    ans = max(ans, temp);
    temp = 0;
    sum = 0;
    sort(qz + 1, qz + n + 1, cmpc);
    for (int i = 1; i <= n; i++) {
      if (sum + qz[i].c > 0) {
        sum += qz[i].c;
        temp++;
      } else
        break;
    }
    ans = max(ans, temp);
    temp = 0;
    sum = 0;
    sort(qz + 1, qz + n + 1, cmpd);
    for (int i = 1; i <= n; i++) {
      if (sum + qz[i].d > 0) {
        sum += qz[i].d;
        temp++;
      } else
        break;
    }
    ans = max(ans, temp);
    temp = 0;
    sum = 0;
    sort(qz + 1, qz + n + 1, cmpe);
    for (int i = 1; i <= n; i++) {
      if (sum + qz[i].e > 0) {
        sum += qz[i].e;
        temp++;
      } else
        break;
    }
    ans = max(ans, temp);
    cout << ans << endl;
  }
}
