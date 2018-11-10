#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n,a[100],b[100],i,j,tmp;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	tmp=a[1];
	for(i=n-1;i>0;i--){
		for(j=n-2;j>=0;j--){
			if(a[i]<a[j]){
				tmp=a[i];
				a[i]=a[j];
			}
		}
	}
	for(i=0;i<n;i++)
		cout<<a[i];
}
