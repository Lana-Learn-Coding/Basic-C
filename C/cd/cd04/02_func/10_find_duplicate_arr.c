#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void get_input(int *ptr_arr, int size);

void print_arr(int *ptr_arr, int size);

int count_duplicate_arr(int *ptr_arr, int size, int *ptr_a_subrr, int sub_size);

int is_arr_equal(int *ptr_arra, int *ptr_arrb, int size);

int main(int argc, char const *argv[])
{

	int *p, *p_sub;
	int cnt;
	int len, len_sub;
	printf("nhap kich thuoc mang: ");
	scanf("%d", &len);
	printf("nhap kich thuoc mang con: ");
	scanf("%d", &len_sub);
	int a[len];
	int a_sub[len_sub];

	p = &a[0];
	p_sub = &a_sub[0];

	printf("nhap du lieu cho mang chinh: \n");
	get_input(p, len);
	printf("nhap du lieu cho mang con: \n");
	get_input(p_sub, len_sub);
	printf("\n");

	printf("mang chinh: ");
	print_arr(p, len);
	printf("\n");
	printf("mang con: ");
	print_arr(p_sub, len_sub);
	printf("\n");

	cnt = count_duplicate_arr(p, len, p_sub, len_sub);
	printf("mang con xuat hien %d lan", cnt);

	getch();
	return 0;
}

void get_input(int *ptr_arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("nhap phan tu %d/%d: ", i, size);
		scanf("%d", ptr_arr);
		ptr_arr++;
	}
	printf("\n");
}

void print_arr(int *ptr_arr, int size)
{
	int i;
	printf("[");
	for (i = 0; i < size; i++) {
		if (i == 0) {
			printf("%d", *ptr_arr);
		} else {
			printf(", %d", *ptr_arr);
		}
		ptr_arr++;
	}
	printf("]");
}

int count_duplicate_arr(int *ptr_arr, int size, int *ptr_a_subrr, int sub_size)
{
	int cnt = 0;
	if (sub_size <= size) {
		int compare_size = size - sub_size + 1;
		int i;
		for (i = 0; i < compare_size; i++) {
			if (is_arr_equal(ptr_arr + i, ptr_a_subrr, sub_size)) {
				cnt++;
			}
		}
	}
	return cnt;
}

int is_arr_equal(int *ptr_arra, int *ptr_arrb, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		int element_a = *(ptr_arra + i);
		int element_b = *(ptr_arrb + i);
		if (element_a != element_b) {
			return 0;
		}
	}
	return 1;
}
