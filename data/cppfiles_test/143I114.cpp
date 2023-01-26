#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define yn(joken) cout<<((joken) ? "Yes" : "No")<<endl
#define YN(joken) cout<<((joken) ? "YES" : "NO")<<endl
using namespace std;
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (int i = 0; i < int(v.size()); i++) {
        is >> v[i];
    }
    return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    for (int i = 0; i < int(v.size()); i++) {
        os << v[i];
        if (i < int(v.size()) - 1) os << ' ';
    }
    return os;
}

void solve(vector<int> &A){
    int N=sz(A);
    vector<int> B(N+1),C(N+1);
    rep(i,N){
        B[A[i]]++;
        C[A[i]]++;
    }
    stack<int> st;
    vector<int> DP(N+2);
    rep(i,N+1){
        if(DP[i]==-1){
            DP[i+1]=-1;
            continue;
        }
        if(B[i]){
            DP[i+1]=DP[i];
        }
        else{
            if(st.empty()) DP[i+1]=-1;
            else{
                int x=st.top();
                DP[i+1]=DP[i]+i-x;
                B[x]--;
                B[i]++;
                if(B[x]==1) st.pop();
            }
        }
        if(B[i]>=2) st.push(i);
    }
    rep(i,N+1){
        cout<<(DP[i]==-1 ? -1 : DP[i]+C[i])<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    rep(_,t){
        int N;
        cin>>N;
        vector<int> A(N);
        cin>>A;
        solve(A);
    }
}