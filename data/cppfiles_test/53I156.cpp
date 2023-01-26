#include<bits/stdc++.h>
#include<ext/rope>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define maxn 1000010
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

int prime[maxn];
int factor[maxn];//用来记录最小素因子
int sieve(int n)
{
    int p=0;
    for(int i=2;i<=n;i++)
    {
        if(!factor[i])//如果没有找到素因子，当然就是素数啦
        {
            prime[p++]=i;
            factor[i]=i;
        }
        for(int j=0;j<p&&prime[j]*i<=n;j++)
        {
            factor[prime[j]*i]=prime[j];
            if(!(i%prime[j]))//筛的数已经被前面的数筛过了
                break;
        }
    }
    return p;
}
void solve(){
    int n;
    char c;
    cin>>n>>c;
    char s[N];
    cin>>s+1;
    int cnt=0;
    int l=0,r=0;
    bool n2=0,n3=0;
    bool nn2=0,nn3=0;
    for(int i=1;i<=n;i++){
        if(s[i]!=c){
            cnt++;
            if(i%2==0){
                n2=1;
            }
            if(i%3==0 && i%6!=0){
                n3=1;
            }
            if(i%2==0 && i%6!=0){
                nn2=1;
            }
            if(i%3==0){
                nn3=1;
            }
        }
    }
    if(cnt==0){
        cout<<0<<endl;
    }
    else if(s[1]!=c && cnt==1){
        cout<<1<<endl<<2<<endl;
    }
    else{
        if(n2 && n3 && nn2 && nn3){
            cout<<2<<endl<<2<<" "<<3<<endl;
        }
        else if(n2 && !n3){
            cout<<1<<endl<<2<<endl;
        }
        else if(nn3 && !nn2){
            cout<<1<<endl<<3<<endl;
        }
    }
}
int main(){
    sieve(N);
    TT solve();
	return 0;
}
