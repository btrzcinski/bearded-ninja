#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
	unsigned id;
	char *name;
} student;

void create_student(
	unsigned id, char *name, student** s)
{
	*s = malloc(sizeof(student));
	(*s)->id = id;
	(*s)->name = malloc(sizeof(char) * (strlen(name)+1));
	strcpy((*s)->name, name);
}

void free_student(student** s)
{
	free((*s)->name);
	free(*s);
	*s = NULL;
}

void swap_students(student** one, student** two)
{
	student* temp = *two;
	*two = *one;
	*one = temp;
}

void print_student(student* s)
{
	printf("id = %d, name = %s\n", s->id, s->name);
}

void print_students(student** c, int c_size)
{
    int i;
	for(i = 0; i < c_size; i++)
	{
		print_student(c[i]);
	}
	printf("\n");
}

void shuffle_students(student** c, int c_size)
{
	srand(time(NULL));

    int i;
	for(i = 0; i < c_size; i++)
	{
		int dest = rand() % 50;
		swap_students(&c[i], &c[dest]);
	}
}

unsigned countsort_students(student** c, int c_size)
{
	unsigned swaps = 0;
    int i;
	for(i = 0; i < c_size; i++)
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
    int i;
	for(i = 0; i < 50; i++)
	{
		char name[10];
		sprintf(name, "Student%d", i);
		create_student(i, name, &c[i]);
	}

	print_students(c, 50);
	shuffle_students(c, 50);
	print_students(c, 50);
	countsort_students(c, 50);
	print_students(c, 50);

	for(i = 0; i < 50; i++)
	{
		free_student(&c[i]);
	}

	return 0;
}
