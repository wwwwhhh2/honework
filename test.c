//下面给出牛顿迭代法去求解方程（给定方程）的思路与方法
/*牛顿迭代法求解非线性方程的根*/
#include <stdio.h>
#include <math.h>
#define tol 0.000001 //精度

/*由方程导出的函数在此，返回计算值*/
double fun(double fun_a)
{
	fun_a = fun_a * fun_a * fun_a + 2 * fun_a * fun_a + 10 * fun_a - 20;
	return fun_a;
}
/*由方程导出的函数的导数在此，返回计算值*/
double fun1(double fun_a)
{
	fun_a = 3 * fun_a * fun_a + 4 * fun_a + 10;
	return fun_a;
}
int main()
{
	unsigned int c_times = 0;
	double c_result, p;
	p = 1.5;//给一个摸约是根的值，值约接近，迭代越快

	printf("以下利用牛顿迭代法计算X^3+2X^2+10X-20=0的根	精度为%g\n", tol);
	printf("取初值p为：%g\n", p);
	for (c_times = 1; c_times < 1000; c_times++) // 迭代最多1000次，不行就退出
	{
		c_result = p - fun(p) / fun1(p);//迭代方程
		printf("当前计算次数为：%d	计算结果为：%g\n", c_times, c_result);
		if (fabs(p - c_result) < tol) break;
		p = c_result;

		if (c_times == 999)
		{
			printf("计算方法失效！");
			goto _end;
		}
	}

	printf("最终计算得结果为：%g	所需计算次数为：%d\n", c_result, c_times);

_end:
	printf("计算完成，按回车退出程序。");
	getchar();
	return 0;
}

