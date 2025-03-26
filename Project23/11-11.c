//猜数字游戏：
//界面：选择进入游戏还是退出
//进入游戏；弹出游戏提醒，随机生成1~100的数字，输入数字后弹出提示：猜大了还是猜小了，有6次机会。
//成功：弹出恭喜您，猜对了，并且显示再来一次还是退出。
//失败：弹出很遗憾，您没有回答正确，并且显示正确结果，和选择再来一次还是退出。
//再来一次：重复进入游戏的操作。
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int input = 0, guess = 0, i, p = 0;
	printf("*************欢迎来到猜数字游戏!*************\n");
	printf("*********************************************\n");
	printf("*****************1.开始游戏******************\n");
	printf("*****************0.退出游戏******************\n");
	printf("***********请输入数字进行下一步操作**********\n");
	srand((signed int)time(NULL));
	while (1)
	{
		int ret = rand() % 99 + 1;
		if (p > 0)
		{
			printf("\n*****************1.再来一次******************\n");
			printf("*****************0.退出游戏******************\n");
			printf("**********请输入数字进行下一步操作***********\n");
		}
		scanf("%d", &input);
		if (1 == input)
		{
			printf("\n本模式需要您根据游戏的提醒，在1~100中猜出指定的数字。\n");
			for (i = 0; i < 5; i++)
			{
				printf("第%d次，请输入数字>:", i + 1);
				scanf("%d", &guess);
				if (ret > guess)
				{
					printf("猜小了，再试试!\n\n");
				}
				else if (ret < guess)
				{
					printf("猜大了，再试试!\n\n");
				}
				else
				{
					break;
				}
			}
			if (ret != guess)
			{
				printf("最后一次，加油！请输入>:");
				scanf("%d", &guess);
				if (ret == guess)
				{
					printf("恭喜您，猜对了!\n");
				}
				else
				{
					printf("很遗憾，您输了,答案为%d\n",ret);
				}
			}
			else
			{
				printf("恭喜您，猜对了!\n");
			}
		}
		else
		{
			printf("已退出");
			return 0;
		}
		p++;
	}
	return 0;
}