#include<bits/stdc++.h>
#include<ext/rope>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ull unsigned long long
#define bq priority_queue <int,vector<int>,less<int> > //大顶堆
#define sq priority_queue <int,vector<int>,greater<int> > //小顶堆
#define TT int t;cin>>t;while(t--)
typedef pair <int,int> pii;
const int N=3e5+10;
const int mod=1e9+7;
auto max(auto x,auto y){
	return x>y?x:y;
}
auto min(auto x,auto y){
	return x<y?x:y;
}
ll read(){
	ll x=0,y=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			y=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
void write(ll x,char c=0)
{
    if(x<0){
    	putchar('-');
    	x=-x;
	}
    char a[20],s=0;
    do{
    	a[++s]=x%10;
    	x=x/10;
	}while(x);
    do{
    	putchar(a[s]+'0');
	}while(--s);
    if(c){
        putchar(c);
    }
}

bool vis[N];
int cnt=0;

vector <int> a;
void solve(){
    a.clear();
    int n;
    char c;
    cin>>n>>c;
    char s[N];
    cin>>s+1;
    for(int i=1;i<=n;i++){
        if(s[i]!=c){
            cnt++;
        }
    }
    if(!cnt){
        cout<<0<<endl;
        return;
    }
    for(int i=n;i>=n/2;i--){
        if(s[i]==c){
            cout<<1<<endl<<i<<endl;
            return;
        }
    }
    cout<<2<<endl<<2<<" "<<3<<endl;
}



int main(){
    TT solve();
	return 0;
}
