// Commission.cpp
#include "stdio.h"
#include "math.h"

// 该函数是Chap5白盒测试中用到的一个例子
// 函数主要功能是计算每半年的销售额和销售员的提成
// 这里为了分析的需要，加入了循环，且输入直接用设定好的来获取
double Commission()
{// alcohol, redWine和beer分别记录白酒、红酒和啤酒的月销售量（单位：瓶）
	int alcoholPrice = 168;// 白酒的单价
	int redWinePrice = 120; // 红酒的单价
	int beerPrice = 5; // 啤酒的单价

	int totalSales = 0;// 记录半年总销售额
	double totalCommission = 0.0;// 总提成
	int monthSales = 0;// 记录每月销售额
	double commission = -1.0;// 记录提成

	int input[6][3] = { {50, 30, 300},// 所有输入数据
						{69, 49, 506},
						{143, 123, 1244 },
						{5000, 3000, 30000},
						{60, 39, 398},
						{106, 86, 875}	};
	double exp[6][2] = { {13500, 540.00},// 预期输出
						{20002, 800.02},
						{45004, 1050.02},
						{1350000, 7575.00},
						{16750, 670.00},
						{32503, 925.03} };
	int month = 0;
	while( month < 6 )
	{
		monthSales = alcoholPrice * input[month][0] + redWinePrice * input[month][1] + beerPrice * input[month][2];
		if( monthSales <= 20000 )// 如果销售额低于20000元的部分，按4%提成
			commission = monthSales * 0.04;
		else if( monthSales <= 45000 )// 销售额低于45000元的部分，按1%提成
			commission = (monthSales - 20000) * 0.01 + 20000 * 0.04;
		else// 销售额高于45000元的部分，按0.5%提成
		commission = (monthSales - 45000) * 0.005 + (45000 - 20000) * 0.01 + 20000 * 0.04;

		printf( "alcohol = %d, redWine = %d, beer = %d, monthSales = %d, commission = %f------\n", 
			input[month][0], input[month][1], input[month][2], monthSales, commission );
		if( monthSales==exp[month][0] && fabs(commission-exp[month][1])<1e-3 )
			printf( "Pass.\n ");
		else
			printf( "Fail.\n" );

		totalSales = totalSales + monthSales;
		totalCommission = totalCommission + commission;

		month = month +1;
	}
	printf( "totalSales = %d, totalCommission = %f\n", totalSales, totalCommission );

	return totalCommission;
}

void main()
{
	Commission();
	int in;
	printf( "请随便输入一个整数结束...\n" );
	scanf( "%d", &in );
}