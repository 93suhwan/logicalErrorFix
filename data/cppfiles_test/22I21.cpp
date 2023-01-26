#include <bits/stdc++.h>
using namespace std;
int Read() {
  int Output = 0;
  char Input = getchar();
  while (Input < '0' || Input > '9') Input = getchar();
  while (Input >= '0' && Input <= '9') {
    Output = Output * 10 + Input - '0';
    Input = getchar();
  }
  return Output;
}
int N, M;
int Numx[200001], Numy[200001];
int Divide[200001];
int Count[451][451];
int In[200001];
int Sqrt;
int main() {
  N = Read(), M = Read();
  Sqrt = sqrt(M);
  for (int i = 1; i <= N; ++i) Numx[i] = Read(), Numy[i] = Read();
  int Pre = 0;
  for (int i = 1; i <= M; ++i) {
    Pre += Divide[i];
    int Op = (Read() == 1 ? 1 : -1), Pos = Read();
    int Tot = Numx[Pos] + Numy[Pos];
    int Past;
    if (Op == -1)
      Past = In[Pos], In[Pos] = 0;
    else
      Past = In[Pos] = i;
    if (Tot > Sqrt) {
      for (int j = Past + Numx[Pos]; j <= M; j += Tot) {
        int Next = j + Numy[Pos];
        Divide[j] += Op, Divide[Next] -= Op;
      }
      if (Op == -1 && (i - Past) % Tot >= Numx[Pos]) --Pre;
    } else
      for (int j = Numx[Pos]; j < Tot; ++j) Count[Tot][(Past + j) % Tot] += Op;
    int Total = 0;
    for (int j = 2; j <= Sqrt; ++j) Total += Count[j][i % j];
    printf("%d\n", Total + Pre);
  }
  return 0;
}
