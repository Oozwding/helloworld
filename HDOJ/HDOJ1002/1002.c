/**
 *  Filename:HDOJ1002
 *  Date    :2016/3/29
 *  @Author :zwding
 *  Describe:C大数加法
 */
#include <stdio.h>
#include <string.h>
void add ( char a[], char b[] )
{
    //和数组
    char sum[1010] = {' '};
    //用于标志进位
    int flg = 0;
    //存储临时数据
    int temp = 0;
    //获得字符串的长度也就是数字的位数
    int len_a = strlen ( a );
    int len_b = strlen ( b );
    int i = len_a;
    int j = len_b;
    //循环加法 就跟小学列竖式算加法一样，原理很简单
    for ( ; i > 0; i-- )
    {
        //当b数组还有数字时，相加
        if ( j > 0 )
        {
            //flg为进位标志
            //'0' - 48 = 0
            //'1' - 48 = 1
            //减96是将字符0（1，...）转换为数字0（1，...）
            temp = a[i-1] + b[j-1] + flg - 96;
            //每加完一位就向前移一位
            j--;
        }
        //否则只剩a数组的数字，b数组没有数字可加
        else
            //同上
            temp = a[i-1] + flg - 48;
        //用于判断当前和是否大于10，大于的话 flg应该置于1
        if ( temp >= 10 )
            flg = 1;
        else
            flg = 0;
        //进1，取temp-10，也就是temp%10
        temp = temp % 10;
        //存储数据
        sum[i] = temp + 48;
    }
    //最后一项有进位的话，将sum【0】 = 1
    if ( flg == 1 )
        sum[0] = 49;
    i = 0;
    while ( i <= len_a )
    {
        //用于判断sum【0】，默认是 ' '
        if ( sum[i] != ' ' )
            printf("%c",sum[i]);
        i++;
    }
    printf("\n");
}
int main()
{
    int N;
    scanf("%d",&N);
    for ( int i = 1; i <= N; i++ )
    {
        //用字符串读取数据
        char a[1000];
        char b[1000];
        scanf("%s %s",a,b);
        //获得长度
        int len_a = strlen ( a );
        int len_b = strlen ( b );
        printf("Case %d:\n%s + %s = ",i,a,b);
        //优先将位数多的放到前面，减少后面的计算量
        if ( len_a >= len_b )
            add ( a, b );
        else
            add ( b, a );
        //最后一组数据后面不用输出换行
        if ( i != N )
            printf("\n");
    }
    return 0;
}
