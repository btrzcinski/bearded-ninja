#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <time.h>

typedef struct
{
	unsigned id;
	wchar_t *name;
} student;

void create_student(
	unsigned id, wchar_t *name, student** s)
{
	*s = malloc(sizeof(student));
	(*s)->id = id;
	(*s)->name = malloc(sizeof(wchar_t) * (wcslen(name)+1));
	wcscpy((*s)->name, name);
}

void free_student(student** s)
{
	free((*s)->name);
	free(*s);
	*s = NULL;
}

inline void swap_students(student** one, student** two)
{
	student* temp = *two;
	*two = *one;
	*one = temp;
}

void print_student(student* s)
{
	wprintf(L"id = %d, name = %ls\n", s->id, s->name);
}

void print_students(student** c, int c_size)
{
	for(int i = 0; i < c_size; i++)
	{
		print_student(c[i]);
	}
	wprintf(L"\n");
}

void shuffle_students(student** c, int c_size)
{
	srand(time(NULL));

	for(int i = 0; i < c_size; i++)
	{
		int dest = rand() % 50;
		swap_students(&c[i], &c[dest]);
	}
}

unsigned countsort_students(student** c, int c_size)
{
	unsigned swaps = 0;
	for(int i = 0; i < c_size; i++)
	{
		while(c[i]->id != i)
		{
			int dest = c[i]->id;
			swap_students(&c[i], &c[dest]);
			swaps++;
		}
	}

	return swaps;
}

int main(int argc, char **argv)
{
	student* c[50];
	for(int i = 0; i < 50; i++)
	{
		wchar_t name[10];
		swprintf(name, 10, L"Student%d", i);
		create_student(i, name, &c[i]);
	}

	print_students(c, 50);
	shuffle_students(c, 50);
	print_students(c, 50);
	countsort_students(c, 50);
	print_students(c, 50);

	for(int i = 0; i < 50; i++)
	{
		free_student(&c[i]);
	}

	return 0;
}