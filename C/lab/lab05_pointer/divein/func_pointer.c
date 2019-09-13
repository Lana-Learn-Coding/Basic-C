#include <stdio.h>
#include <conio.h>

void print_arr(int *p_arr, int size);

void for_each(int *p_arr, int size, void(*p_fun)(int *));

void increase_one(int *num);

int main(int argc, char const *argv[])
{
    int a[4] = {1, 2, 3, 4};
    int len = 4;
    int *ptr = &a[0];
    /*
    * declare and define a function-pointer
    * the name must be different from function name
    * e.g increase_one_p vs increase_one
    */
    void (*increase_one_p)(int *) = increase_one;

    printf("origin: ");
    print_arr(ptr, len);
    printf("\n");

    for_each(ptr, len, increase_one_p);
    printf("increased: ");
    print_arr(ptr, len);

    getch();
    return 0;
}

void print_arr(int *p_arr, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", *p_arr);
        p_arr++;
    }
}

/* accept function-pointer as arg */
void for_each(int *p_arr, int size, void(*p_fun)(int *))
{
    int i;
    for (i = 0; i < size; i++) {
        p_fun(p_arr);
        p_arr++;
    }
}

void increase_one(int *num)
{
    *num = *num + 1;
}
