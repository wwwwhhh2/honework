//�������ţ�ٵ�����ȥ��ⷽ�̣��������̣���˼·�뷽��
/*ţ�ٵ������������Է��̵ĸ�*/
#include <stdio.h>
#include <math.h>
#define tol 0.000001 //����

/*�ɷ��̵����ĺ����ڴˣ����ؼ���ֵ*/
double fun(double fun_a)
{
	fun_a = fun_a * fun_a * fun_a + 2 * fun_a * fun_a + 10 * fun_a - 20;
	return fun_a;
}
/*�ɷ��̵����ĺ����ĵ����ڴˣ����ؼ���ֵ*/
double fun1(double fun_a)
{
	fun_a = 3 * fun_a * fun_a + 4 * fun_a + 10;
	return fun_a;
}
int main()
{
	unsigned int c_times = 0;
	double c_result, p;
	p = 1.5;//��һ����Լ�Ǹ���ֵ��ֵԼ�ӽ�������Խ��

	printf("��������ţ�ٵ���������X^3+2X^2+10X-20=0�ĸ�	����Ϊ%g\n", tol);
	printf("ȡ��ֵpΪ��%g\n", p);
	for (c_times = 1; c_times < 1000; c_times++) // �������1000�Σ����о��˳�
	{
		c_result = p - fun(p) / fun1(p);//��������
		printf("��ǰ�������Ϊ��%d	������Ϊ��%g\n", c_times, c_result);
		if (fabs(p - c_result) < tol) break;
		p = c_result;

		if (c_times == 999)
		{
			printf("���㷽��ʧЧ��");
			goto _end;
		}
	}

	printf("���ռ���ý��Ϊ��%g	����������Ϊ��%d\n", c_result, c_times);

_end:
	printf("������ɣ����س��˳�����");
	getchar();
	return 0;
}

