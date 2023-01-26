#include <bits/stdc++.h>
using namespace std;
template <typename Type>
inline bool Sign(Type TEST) {
  return TEST > 0;
}
template <typename Type>
inline Type __LCM(Type NUM1, Type NUM2) {
  return (NUM1 / __gcd(NUM1, NUM2)) * NUM2;
}
inline void Max_CoDistance(long long XCo, long long YCo) {
  cout << 1 << ' ' << 1 << ' ' << XCo << ' ' << YCo << '\n';
}
long long Power(long long Base = 2, long long Exponent = 2) {
  long long Result = 1;
  while (Exponent--) Result *= Base;
  return Result;
}
string Binary_Rep(int Number) {
  string Answer;
  while (Number) {
    if (Number % 2 == 0)
      Answer += '0';
    else
      Answer += '1';
    Number /= 2;
  }
  return Answer;
}
bool Long_Division(string number, long long divisor) {
  long long Answer = 0, Temp;
  for (int i = 0; i < number.size(); i++) {
    Answer *= 10;
    Temp = number[i] - '0';
    Answer += Temp;
    Answer %= divisor;
  }
  if (Answer) return false;
  return true;
}
template <typename Type>
Type Fact(Type Number) {
  if (Number == 0 || Number == 1)
    return 1;
  else
    return Number * Fact(Number - 1);
}
template <typename Type>
Type C(Type N, Type R) {
  return (Fact(N) / (Fact(N - R) * Fact(R)));
}
template <typename Type>
Type P(Type N, Type R) {
  return (Fact(N) / Fact(N - R));
}
long long Long_Jumps(int N) {
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  long long ANS[N], Max = 0;
  for (int i = N - 1; i >= 0; i--)
    if (i + a[i] >= N)
      ANS[i] = a[i];
    else
      ANS[i] = a[i] + ANS[a[i] + i];
  for (int i = 0; i < N; i++) Max = max(Max, ANS[i]);
  return Max;
}
template <typename Type>
void Bubble_Sort(Type Array[], Type Size) {
  for (int i = 0; i < Size; i++)
    for (int j = 0; j < Size - i - 1; j++)
      if (Array[j] > Array[j + 1]) swap(Array[j], Array[j + 1]);
}
template <typename Type>
void Bubble_Sort(Type Rows, vector<vector<Type> > &Vector) {
  for (int i = 0; i < Rows; i++)
    for (int j = 0; j < Rows - i - 1; j++)
      if (Vector[j][0] > Vector[j + 1][0])
        swap(Vector[j], Vector[j + 1]);
      else if (Vector[j][0] == Vector[j + 1][0])
        if (Vector[j][1] > Vector[j + 1][1]) swap(Vector[j], Vector[j + 1]);
}
void Primes(int N) {
  vector<bool> P(N + 1, true);
  for (int i = 2; i * i <= N; i++)
    if (P[i] == true)
      for (int j = i * i; j <= N; j += i) P[j] = false;
  for (int j = 2; j <= N; j++)
    if (P[j] == true) cout << j << ' ';
}
template <typename Type>
bool Prime(Type P) {
  bool Flag = true;
  for (Type i = 2; i * i <= P; i++)
    if (P % i == 0) {
      Flag = false;
      break;
    }
  if (Flag)
    return true;
  else
    return false;
}
template <typename Type>
bool Semi_Prime(Type SP) {
  int Counter = 0;
  for (Type j = 2; j * j <= SP && Counter < 2; j++)
    while (SP % j == 0) {
      SP /= j;
      Counter++;
    }
  if (SP > 1) Counter++;
  return (Counter == 2);
}
template <typename Type>
long long Good_Pairs(Type A[], Type B[], Type N, long long Counter = 0) {
  Type P[N];
  for (int i = 0; i < N; i++) P[i] = A[i] - B[i];
  sort(P, P + N);
  Type L = 0, R = N - 1;
  while (L < R)
    if (P[L] + P[R] > 0) {
      Counter += R - L;
      R--;
    } else
      L++;
  return Counter;
}
template <typename Type>
Type Fast_Power(Type x, Type y) {
  Type Temp;
  if (y == 0) return 1;
  Temp = Fast_Power(x, y / 2);
  if (y % 2 == 0)
    return Temp * Temp;
  else if (y > 0)
    return x * Temp * Temp;
  else
    return (Temp * Temp) / x;
}
void Solution() {
  string s;
  cin >> s;
  int a[26];
  for (int i = 0; i < 26; i++) a[s[i] - 'a'] = i + 1;
  string c;
  cin >> c;
  int ans = 0;
  for (int i = 1; i < c.size(); i++)
    ans += (abs(a[c[i] - 'a'] - a[c[i - 1] - 'a']));
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) Solution();
  return 0;
}
