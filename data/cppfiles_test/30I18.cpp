#include <bits/stdc++.h>
using namespace std;
template <class R>
inline bool Checkmin(R &A, R B) {
  return A > B ? A = B, true : false;
}
template <class R>
inline bool Checkmax(R &A, R B) {
  return A < B ? A = B, true : false;
}
template <class R>
inline R Lowbit(R A) {
  return A & -A;
}
const int MaxN = 1000000 + 10;
int N, Q, A[MaxN], Ans[MaxN];
vector<int> Get[MaxN];
int Find[MaxN];
int F(int Nod) { return Nod == Find[Nod] ? Nod : Find[Nod] = F(Find[Nod]); }
void Merge(int A, int B) {
  if (F(A) != F(B)) Find[Find[A]] = Find[B];
}
int U[MaxN], V[MaxN];
vector<pair<int, int> > Vec;
pair<int, int> MKP(int A, int B) { return make_pair(min(A, B), max(A, B)); }
bool P[MaxN];
int Prime[MaxN], Pris;
int main() {
  int N = 1000001;
  for (int i = 1; i <= N; ++i) Find[i] = i;
  for (int i = 2; i <= N; ++i) {
    if (not P[i]) {
      Prime[++Pris] = i;
      Get[i].push_back(i);
    }
    for (int j = 1; j <= Pris; ++j) {
      int S = i * Prime[j];
      if (S > N) break;
      P[S] = true;
      Get[S] = Get[i];
      if (i % Prime[j])
        Get[S].push_back(Prime[j]);
      else
        break;
    }
  }
  cin >> N >> Q;
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
    vector<int> L = Get[A[i]];
    for (int S1 = L.size(); S1--;)
      for (int S2 = L.size(); S2--;) Merge(L[S1], L[S2]);
  }
  for (int i = 1; i <= Q; ++i) {
    cin >> U[i] >> V[i];
    vector<int> L = Get[A[U[i]]], R = Get[A[V[i]]];
    for (int S1 = L.size(); S1--;)
      for (int S2 = R.size(); S2--;)
        if (F(L[S1]) == F(R[S2])) goto end1;
    Ans[i] = 2;
  end1:;
  }
  for (int i = 1; i <= N; ++i) {
    vector<int> L = Get[A[i]], R = Get[A[i] + 1];
    for (int S1 = L.size(); S1--;)
      for (int S2 = R.size(); S2--;)
        if (F(L[S1]) != F(R[S2])) Vec.push_back(MKP(F(L[S1]), F(R[S2])));
  }
  sort(Vec.begin(), Vec.end());
  Vec.resize(unique(Vec.begin(), Vec.end()) - Vec.begin());
  for (int i = 1; i <= Q; ++i) {
    if (Ans[i]) {
      vector<int> L = Get[A[U[i]]], R = Get[A[V[i]]];
      for (int S1 = L.size(); S1--;)
        for (int S2 = R.size(); S2--;) {
          pair<int, int> Tar = MKP(F(L[S1]), F(R[S2]));
          vector<pair<int, int> >::iterator It =
              lower_bound(Vec.begin(), Vec.end(), Tar);
          if (It != Vec.end())
            if (*It == Tar) {
              Ans[i] = 1;
              goto end2;
            }
        }
    end2:;
    }
    cout << Ans[i] << endl;
  }
  return 0;
}
