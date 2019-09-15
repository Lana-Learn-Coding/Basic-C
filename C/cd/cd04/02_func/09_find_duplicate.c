#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void get_input(int *ptr_arr, int size);

int is_contains(int *ptr_arr, int size, int element);

int count_duplicate(int *ptr_arr, int size, int element);

int main(int argc, char const *argv[])
{

	int *p, *p_duplicates;
	int i;
	int duplicates_len = 0;
	int len;
	printf("nhap kich thuoc mang: ");
	scanf("%d", &len);
	int a[len];
	int duplicates[len];

	p = &a[0];
	p_duplicates = &duplicates[0];

	get_input(p, len);

	for (i = 0; i < len; i++) {
		int element = *(p + i);
		if (!is_contains(duplicates, duplicates_len, element)) {
			*(p_duplicates + duplicates_len) = element;
			duplicates_len++;
		}
	}

	for (i = 0; i < duplicates_len; i++) {
		int element = *(p_duplicates + i);
		int cnt = count_duplicate(p, len, element);
		printf("phan tu %d xuat hien %d lan trong mang\n", element, cnt);
	}

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

int is_contains(int *ptr_arr, int size, int element)
{
	int i;
	for (i = 0; i < size; i++) {
		if (*(ptr_arr + i) == element) {
			return 1;
		}
	}
	return 0;
}

int count_duplicate(int *ptr_arr, int size, int element)
{
	int cnt = 0;
	int i;
	for (i = 0; i < size; i++) {
		if (*(ptr_arr + i) == element) {
			cnt++;
		}
	}
	return cnt;
}
