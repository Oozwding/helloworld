#include <iostream>
#include <iomanip> // 控制格式用
using namespace std;
int factor[11] = {1,1};//阶乘结果
double e[11]={1}; //计算e的结果
int main(){
	int n;
	for(int i = 2; i <= 9; ++i){ //计算所有阶乘
		factor[i] = factor[i-1] * i;
	}
	cout << "n e" << endl
	     << "- -----------" << endl;//注意，是中横，我没留心看以为是底横_，白白WA了几次
    	for(int i = 1; i <= 10; ++i){
           e[i] = e[i-1] + double(1.0) / factor[i];
           if(i == 8){  //特别注意，第8位的零要保留。因此也WA了一次
                cout << i - 1 << " " << setprecision(10) << setiosflags(ios::showpoint) <<  e[i-1] << endl;
           }//setiosflags(ios::showpoibt)强制显示无效0
           else{
                cout << i - 1 << " " <<  setprecision(10) //连同小数点一起保留10位，小数共有9位
                        <<  e[i-1] << endl;
           }
    }
}
