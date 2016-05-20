/**
 *  @Filename:HDOJ 1006
 *  @Date    :2016/3/15
 *  @Author  :zwding
 *  Describe:tick to tick 模拟
 */
 //首先根据题意，采用离散的点，一个一个点试，循环1小时（3600）即可，但苦苦做不出来答案
 //最终百度明白这道题的正确做法

#include <cstdio>
#include <math.h>
#include <iostream>
#include <algorithm>

#define V_SEC 6.0       //秒针角速度 360度/60s
#define V_MIN 0.1       //分针角速度 360度/3600s
#define V_HOU 1.0/120   //时针角速度 360度/3600*12

#define A_SEC s*6                   //秒针角度 s代表秒 m代表分 h代表小时
#define A_MIN m*6+s*0.1             //分针角度
#define A_HOU h*30+m*0.5+s/120.0    //时针角度

using namespace std;
struct interval{    //区间
    double l;       //left
    double r;       //right
};
double Angle;       //角度
int s=0;            //秒数
interval solve(double v,double a){//解方程
    //Angle<=v*t+a<=360-Angle;,并且和[0,60]取交集
    interval p;
    if(v>0){
        p.l=(Angle-a)/v;
        p.r=(360-Angle-a)/v;
    }
    else{
        p.l=(360-Angle-a)/v;
        p.r=(Angle-a)/v;
    }
    if(p.l< 0)p.l= 0;
    if(p.r>60)p.r=60;
    if(p.l>=p.r)p.l=p.r=0;
    return p;
}
interval jiao(interval a,interval b){
    interval p;
    p.l=max(a.l,b.l);
    p.r=min(a.r,b.r);
    if(p.l>=p.r)p.l=p.r=0;
    return p;
}
double happytime(int h,int m){//计算h时m分 满足题意的秒数
    double v_diff;//速度差
    double a_diff;//角度差
    interval s0[3][2];
    interval s1;
    /*解方程 Angle<=|hh-mm|<=360-Angle*/
    v_diff=V_HOU-V_MIN;
    a_diff=A_HOU-A_MIN;//时针分针夹角
    s0[0][0]=solve( v_diff, a_diff);
    s0[0][1]=solve(-v_diff,-a_diff);
    /*解方程 Angle<=|hh-ss|<=360-Angle*/
    v_diff=V_HOU-V_SEC;
    a_diff=A_HOU-A_SEC;//时针秒针夹角
    s0[1][0]=solve( v_diff, a_diff);
    s0[1][1]=solve(-v_diff,-a_diff);
    /*解方程 Angle<=|mm-ss|<=360-Angle*/
    v_diff=V_MIN-V_SEC;
    a_diff=A_MIN-A_SEC;//分针秒针夹角
    s0[2][0]=solve( v_diff, a_diff);
    s0[2][1]=solve(-v_diff,-a_diff);
    /*
    六个区间，选三个取交集
    因为绝对值的式子得到的两个区间要并，而三个不同表达式
    的区间要交，故这样做
    */
    double res=0;
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    for(int k=0;k<2;k++){
        s1=jiao(jiao(s0[0][i],s0[1][j]),s0[2][k]);
        res+=s1.r-s1.l;
    }
    return res;
}
int main(){
    int h,m;
    while(scanf("%lf",&Angle)){
        if(Angle==-1)break;
        double res=0;
        for(h=0;h<12;h++)
            for(m=0;m<60;m++)
                res+=happytime(h,m);
        printf("%.3lf\n",res*100.0/43200);
    }
}
