#include <bits/stdc++.h>
using namespace std;

#define f first 
#define s second
#define nn '\n'
#define rep(i, a, b) for(auto i=a; i<b; i++)
#define in(x, v) for(auto &x : v)
#define all(v) v.begin(), v.end()
#define sz(v) int(v.size())
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

template<typename T> istream& operator>>(istream& is,  vector<T>  &v)
{ for(auto& i : v) is >> i; return is;}
template<typename T> ostream& operator<<(ostream& os,  vector<T>  v)
{for (auto& i : v) os << i << ' '; os << nn; return os;}

template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p)
{is >> p.first >> p.second; return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p)
{os << p.first << ' ' << p.second; return os;}


template<typename T, typename U> void cmin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void cmax(T& a, U b){if (a < b) a = b;}



const int N = 2e5+2, M=1e9+7;

int tt=1,n,k;


void solve(){

cin >> n;
vector<pi> a(n);
cin >> a;
set<pi> s(all(a));

rep(i, 0, n){
     rep(j, 0, n){
         if(a[i].f != a[j].f) continue;
         if(s.count({a[j].s+1, a[i].s})){
             cout << a[i] << " " << a[j].s << nn;
             break;
         }
     }
     cout << a[i] << " " << a[i].f << nn;
}

cout << nn;

}


int main(){
ios_base::sync_with_stdio(0); cin.tie(0);

cin >> tt;

while(tt--)
    solve();

}