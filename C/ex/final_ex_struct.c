#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT 1
#define PRINT 2
#define WRITE 3
#define EXIT 4

typedef struct student {
	int id;
	char name[50];
	char phone[20];
} student;

void input_array(student **p_arr, int *size);
void print_array(student *p_arr, int size);
void print_student(student student, int pos);
void get_string(char *str, int num);

void write(const char *filename, student *ptr_arr, int size);

int main(int argc, char const *argv[])
{
	char filename[] = "sinh_vien.txt";
	int is_input_valid = 0;
	int len;
	student *pa_student;

	while (1) {
		/* menu */
		int opts;
		int is_opts_valid;
		do {
			printf("============== MENU CHUONG TRINH =============\n");
			printf("%d: Nhap so luong sinh vien va thong tin sinh vien\n", INPUT);
			printf("%d: Hien thi thong tin sinh vien vua nhap\n", PRINT);
			printf("%d: Ghi thong tin sinh vien vao file\n", WRITE);
			printf("%d: Thoat chuong trinh\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			fflush(stdin);
			is_opts_valid = opts >= INPUT && opts <= EXIT;
			if (!is_opts_valid) {
				printf("Lua chon cua ban (%d) khong hop le!\n", opts);
			}
			/* ask for input */
			is_input_valid = is_input_valid || opts == EXIT || opts == INPUT;
			while (!is_input_valid) {
				printf("Ban chua nhap phan tu cho mang!\n");
				input_array(&pa_student, &len);
				is_input_valid = 1;
			}
		} while (!is_opts_valid);

		switch (opts) {
		case INPUT:
			input_array(&pa_student, &len);
			break;
		case PRINT:
			printf("THONG TIN SINH VIEN DA NHAP\n");
			print_array(pa_student, len);
			break;
		case WRITE: {
			write(filename, pa_student, len);
			printf("DA XUAT THONG TIN RA FILE %s\n", filename);
			break;
		}
		case EXIT:
			exit(0);
		default:
			printf("-> chuong chinh co loi, xin thu lai\n");
		}
		printf("\n");
	}
	return 0;
}

void input_array(student **p_arr, int *size)
{
	int i;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", size);
	fflush(stdin);
	/* dynamic array allocation */
	student *p = (student *) malloc(*size * sizeof(student));
	for (i = 0; i < *size; i++) {
		printf("Nhap thong tin sinh vien %d\n", i + 1);
		printf("ID ");
		scanf("%d", &((p + i)->id));
		fflush(stdin);
		printf("Name ");
		get_string((p + i)->name, 50);
		fflush(stdin);
		printf("Phone Number ");
		get_string((p + i)->phone, 20);
		fflush(stdin);
	}
	/* free exist mem allocation for previous array. */
	if (p_arr != NULL) {
		free(p_arr);
	}
	*p_arr = p;
	printf("\n");
}

void print_array(student *p_arr, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		print_student(*(p_arr + i), i + 1);
	}
	printf("\n");
}

void print_student(student student, int pos) {
	printf("SINH VIEN %d =>	  ", pos);
	printf("ID: %d   ", student.id);
	printf("Name: %s   ", student.name);
	printf("Phone Number %s", student.phone);
	printf("\n");
}

void write(const char *filename, student *ptr_arr, int size) {
	FILE *fp = fopen(filename, "w");
	int i;
	for (i = 0; i < size; i++) {
		student student = *(ptr_arr + i);
		fprintf(fp, "SINH VIEN %d =>   ", i + 1);
		fprintf(fp, "ID: %d   ", student.id);
		fprintf(fp, "Name: %s   ", student.name);
		fprintf(fp, "Phone Number %s", student.phone);
		fprintf(fp, "\n");
	}
	fflush(fp);
	fclose(fp);
}

/*
* better gets
* avoid buffer overflow
*/
void get_string(char *str, int num)
{
	char *pos;
	fgets(str, num, stdin);
	/* remove newline at the end */
	pos = strchr(str, '\n');
	if (pos != NULL) {
		*pos = '\0';
	}
}
