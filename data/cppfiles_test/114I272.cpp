    #include<bits/stdc++.h>
    using namespace std;

    #define ll long long
    ll lcm(ll a,ll b){
     return (a/__gcd(a,b))*b;}

ll index(ll a[],ll n,ll j){
ll small=a[j];
ll idx=j;
for(ll i=j+1;i<n;i++){
    if(a[i]<small){
        small=a[i];
        idx=i;}
 }
 return idx;
}
void reversee(ll a[],ll i,ll j){
while(i<j){
    swap(a[i],a[j]);
    i++;j--;}
}
bool is_pelindrom(ll a[],ll i,ll j){
while(i<j){
    if(a[i]!=a[j])
        return 0;
    i++;j--;
}
return 1;
}
bool check(ll a[], ll i,ll j,ll h){

while(i<j){
    if(a[i]==a[j])
        i++,j--;
    else if(a[i]==h)i++;
    else if(a[j]==h)j--;
    else return 0;

}
return 1;
}

void solve(){
ll n;
cin>>n;
ll a[n];
map<ll,ll>m;
for(ll i=0;i<n;i++){
    cin>>a[i];
    m[a[i]]++;}
sort(a,a+n);
ll cnt=n/2;
 ll h=1;
 while(cnt){
        ll p=a[n-h];
for(ll i=0;i<n&&cnt;i++){
        if(a[i]==p)continue;
    if(p%a[i]==0){
        cnt--;
        cout<<p<<" "<<a[i]<<"\n";

    }

    else{
        ll mm=a[i]%p;
        ll x=p%a[i];
        if(mm!=a[i])cout<<a[i]<<" "<<p<<"\n",cnt--;
        else if(m[x]==0)cout<<p<<" "<<a[i]<<'\n',cnt--;

    }
}
h++;
 }


//cout<<'\n';
}


    int main(){
        // ios::sync_with_stdio(0);
   //cin.tie(0);
    int t=1;
   cin>>t;
    while(t--)
    solve();
    }
