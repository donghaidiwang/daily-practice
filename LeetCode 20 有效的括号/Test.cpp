#include<assert.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;
bool StackEmpty(ST* ps)
{
	assert(ps);
	return (ps->top == 0);
}
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * NewCapacity);
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}

	ps->a[ps->top] = x;
	ps->top++;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool isValid(char* s)
{
	ST ps;
	StackInit(&ps);
	char* cur = s;
	int len = strlen(s);
	char* end = s + len - 1;
	while (cur <= end)
	{
		if (*cur == '[' || *cur == '{' || *cur == '(')
		{
			StackPush(&ps, *cur);
		}
		else
		{
			if (StackEmpty(&ps))//栈为空直接输入右括号
			{
				return false;
			}
			char tmp = StackTop(&ps);
			StackPop(&ps);
			if ((tmp == '{' && *cur != '}') || (tmp == '(' && *cur != ')') || (tmp == '[' && *cur != ']'))
			{
				return false;
			}
		}
		cur++;
	}
	if (StackEmpty(&ps))//括号全部匹配完
	{
		return true;
	}
	return false;
}
int main()
{
	return 0;
}