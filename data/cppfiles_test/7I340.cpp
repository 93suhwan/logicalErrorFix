/// Write by Daniel Perez .PERAPRO
#include<bits/stdc++.h>

using namespace std;
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using vi=vector<int>;
using pii=pair<int,int>;
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
char el = '\n';
char esp = ' ';

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ostream& operator<<(ostream& os, const vector<int> &v){
    for(auto const &i: v){
        os<<i<<" ";
    }
    os<<'\n';
    return os;
}
string yes="YES";
string no="NO";

const int N=2e5+5;
int n;
ll v[N];

const int K = log2(N)+2;

ll st[N][K];

void build(){
    for(int i=0;i<n;i++){
        st[i][0]=v[i];
    }
    
    for(int j=1;j<K;j++){
        for(int i=0;i + (1<<j) <=n;i++){
            st[i][j] = __gcd(st[i][j-1], st[i+(1 << (j-1))][j-1]);
        }
    }
}

ll query(int l, int r){
    ll ans=0;
    int k=31 - __builtin_clz(r-l+1);
    return __gcd(st[l][k], st[r - (1 << k)][k]);
}

bool check(int size){
    for(int i=0;i<n-size;i++){
        if(query(i,i+size) >= 2)
            return 1;
    }
    return 0;
}


int main(){
	fast_io;
	/*
 	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    */
    int tc;
    cin>>tc;
    while(tc--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        build();
        int l=1, r=n;
        while(l < r){
            int m=(l+r)/2;
            if(!check(m))
                r=m;
            else
                l=m+1;
            //cout<<l<<esp<<r<<endl;
        }
        cout<<l<<el;
    }
}

/*

*/