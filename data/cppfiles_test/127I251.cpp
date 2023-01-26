#include <bits/stdc++.h>

using namespace std;
#define SZ(x) (int)(x).size()
#define REP(i, n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i, a, b) for(int (i)=(a);(i)<(b);(i)++)
#define REPR(i, n) for(int (i)=(n)-1;(i)>=0;(i)--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , (v).end());

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 29);
const ll LINF = 1e18;
const double PI = acos(-1);

template<typename T>
vector<T> make_v(size_t a){ return vector<T>(a); }

template<typename T, typename... Ts>
auto make_v(size_t a, Ts... ts){
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v){ t = v; }

template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v){
    for(auto &e: t) fill_v(e, v);
}

template<class T>
bool chmax(T &a, const T &b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &vec){
    for(T &x: vec) is >> x;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> &vec){
    REP(i, SZ(vec)){
        if(i != 0)os << " ";
        os << vec[i];
    }
    return os;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string S, T;
        cin >> S >> T;
        map<char, int> M;
        string ans = "";
        REP(i, SZ(S)){
            if(S[i] == 'a' || S[i] == 'b' || S[i] == 'c')M[S[i]]++;
            else ans += S[i];
        }
        so(ans);
        if(T == "abc"){
            REP(i, M['a']){
                cout << 'a';
            }
            REP(i, M['c']){
                cout << 'c';
            }
            REP(i, M['b']){
                cout << 'b';
            }
        }else{
            REP(i, M['a']){
                cout << 'a';
            }
            REP(i, M['b']){
                cout << 'b';
            }
            REP(i, M['c']){
                cout << 'c';
            }
        }
        cout << ans << endl;
    }
    return 0;
}