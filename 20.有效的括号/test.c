#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int STDataType;
struct Stack
{
	STDataType* _array;
	size_t _top;
	size_t _capacity;
};

typedef struct Stack Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
size_t StackSize(Stack* ps);
bool StackEmpty(Stack* ps);

void StackInit(Stack* ps)
{
	assert(ps);
	ps->_array = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_array != NULL)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_capacity = ps->_top = 0;
	}
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity * 2;
		ps->_array = (STDataType*)realloc(ps->_array, newcapacity * sizeof(STDataType));
		ps->_capacity = newcapacity;
	}

	ps->_array[ps->_top] = x;
	ps->_top++;
}

void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);

	return ps->_array[ps->_top - 1];
}

size_t StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0;
}

bool isValid(char* s)
{
	Stack st;
		StackInit(&st);
	char* symbol[3][3] = { '()','[]','{}' };
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
		}
		else if (*s == ')' || *s == ']' || *s == '}')
		{
			if (StackEmpty(&st))
			{
				return false;
			}
			STDataType top = StackTop(&st);
			StackPop(&st);
			for (size_t i = 0;i < 3;++i)
			{
				if (*s == symbol[i][1])
				{
					if (top != symbol[i][0])
					{
						StackDestory(&st);
						return false;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
}