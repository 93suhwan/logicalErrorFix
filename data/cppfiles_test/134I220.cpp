#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int arr[2];
        long long int x=0,y=0;
        for(int i=0;i<n;i+=2){
            x=__gcd(x,a[i]);
        }
        arr[0]=x;
        for(int i=1;i<n;i+=2){
            y=__gcd(y,a[i]);
        }
        arr[1]=y;
        int count;
        bool isans=false;
        for(int i=0;i<2;i++){
            int flag=0;
            if(a[0]%arr[i]==0)
                count=0;
            else
                count=1;
            for(int j=1;j<n;j++){
                if(count==0 && a[j]%arr[i]!=0){
                    count=1;
                }
                else if(count==1 && a[j]%arr[i]==0){
                    count=0;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cout<<arr[i]<<endl;
                isans=true;
                break;
            }
        }
        if(isans==false)
            cout<<0<<endl;
    }
}