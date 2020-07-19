#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/*
 *栈 后缀表达式计算
 *请使用已定义好的栈完成后缀表达式计算：
 *(1)如果是操作数，直接入栈
 *(2)如果是操作符op，连续出栈两次，得到操作数x 和 y,计算 x op y，并将结果入栈。
 *后缀表达式示例如下：
 *9  3  1  -  3  *  +  10  2  /  +
 *13  445  +  51  /  6  -
 *操作数、操作符之间由空格隔开，操作符有 +，-，*, /, %共 5 种符号，所有操作数都为整型。
 */
int compute_reverse_polish_notation(char *str)
{
	Stack S;
	init_stack(&S);

	while(*str != '\0')
	{
		int x, y;
		switch(*str)
		{
			case '+': 
				pop(&S, &y);
				pop(&S, &x);
				push(&S, x+y);
				
				break;
			case '-': 
				pop(&S, &y);
				pop(&S, &x);
				push(&S, x-y);
				
				break;
			case '*': 
				pop(&S, &y);
				pop(&S, &x);
				push(&S, x*y);
				
				break;
			case '/': 
				pop(&S, &y);
				pop(&S, &x);
				push(&S, x/y);
				
				break;
			case '%': 
				pop(&S, &y);
				pop(&S, &x);
				push(&S, x%y);
		
				break;
			case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case'9':
				x = *str - '0';
				while(*(++str) != ' ')
					x = 10*x + *str - '0';
				push(&S,x);
				break;
		}
		str++;	
	}
	int t;
	pop(&S, &t);
	return t;
}

int main()
{
    char s[] = "9 6 5 + 2 * + 7 -";
	printf("%d\n",compute_reverse_polish_notation(s));
	return 0;
}