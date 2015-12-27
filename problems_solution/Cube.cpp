/*
  Problem:Magical Cube
  By:panda2134
  Link: http://noi.openjudge.cn/ch0108/18/
  The Shortest Solution That I've Ever Known
*/
#include<iostream>
using namespace std;
int cube[1000][1000];
int main(){
	int n,posx=1,posy,len;
	cin>>n;
	len=n*2-1;posy=n;
	for(int i=1;i<=len*len;i++){
		cube[posx][posy]=i;
		if((posx==1 && posy==len) || cube[posx-1][posy+1]!=0){
			posx++;
		}else{
			posx=len-((len-posx+1)%len);
			posy=(posy%len)+1;
		}
	}
	for(int i=1;i<=len;i++){
		for(int j=1;j<=len;j++)
			cout<<cube[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
