 /**
 *  Filename:HDOJ1050
 *  Date    :2016/4/22 
 *  @Author :zwding
 *  Describe:贪心
 */
/**16946145	2016-04-22 13:11:16	Accepted	1050	0MS	1592K	587 B	G++	zwding*/
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int t,i,j,N,P[200];
    int s,d,temp,k,min;
    cin >> t;
    for(i=0;i<t;i++){
        for(j=0;j<200;j++)
            P[j]=0;
        cin >> N;
  	    for(j=0;j<N;j++){
            cin >> s >> d;
            s=(s-1)/2;
            d=(d-1)/2;
            if(s>d){
                temp=s;
                s=d;
                d=temp;
            }
            for(k=s;k<=d;k++)
                P[k]++;
        }
        cout<<*max_element(P,P+200)*10<<endl;
      }
   return 0;
}
