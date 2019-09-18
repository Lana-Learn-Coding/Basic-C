#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADD 1
#define REMOVE 2
#define PRINT 3
#define PRINT_BY_GRADE 4
#define PRINT_HIGHEST 5
#define SORT_AVG 6
#define SORT_NAME 7
#define PRINT_BY_CODE 8
#define PRINT_BY_NAME  9
#define EXIT 10

struct subject {
	char code[6];
	char name[31];
	int credit;
	float value;
};

struct student {
	char code[6];
	char name[31];
	char grade[31];
	float average;
	struct subject subjects[5];
	int subject_cnt;
};

void print_by_code(struct student *ptr_arr, int size, char *code);
void print_by_name(struct student *ptr_arr, int size, char *name);
void print_by_grade(struct student *ptr_arr, int size, char *grade);
void print_by_highest(struct student *ptr_arr, int size);
void print_student(struct student student);

void sort_by_average(struct student *ptr_arr, int size);
void sort_by_name(struct student *ptr_arr, int size);
void swap(struct student *a, struct student *b);

int add_student(struct student *ptr_arr, int len_max, int len);
void shift(struct student *ptr_arr, int size, int pos);
int delete_student(struct student *ptr_arr, int len_max, int len);
void delete(struct student *ptr_arr, int size, int pos);

struct student get_student();
void get_subjects(struct subject *subject, int size);
struct subject get_subject();
float get_average(struct subject *subject, int size);
void grading(float average, char *grade);

int main(int argc, char const *argv[])
{
	struct student *p;
	int len = 0, len_max;
	int opts;
	int is_opts_valid;
	printf("nhap luong sinh vien toi da: ");
	scanf("%d", &len_max);
	struct student a[len_max];
	p = &a[0];

	while (1) {
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. them sinh vien\n", ADD);
			printf("%d. xoa sinh vien\n", REMOVE);
			printf("%d. liet ke sinh vien\n", PRINT);
			printf("%d. liet ke sinh vien theo loai\n", PRINT_BY_GRADE);
			printf("%d. tim sinh vien co diem trung binh cao nhat\n", PRINT_HIGHEST);
			printf("%d. sap xep theo diem trung binh (nho ->lon)\n", SORT_AVG);
			printf("%d. sap xep theo ten (a->z)\n", SORT_NAME);
			printf("%d. tim sinh vien theo ma\n", PRINT_BY_CODE);
			printf("%d. tim sinh vien theo ten\n", PRINT_BY_NAME);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			printf("\n");

			is_opts_valid = opts >= ADD && opts <= EXIT;
			if (!is_opts_valid) {
				printf("lua chon cua ban (%d) khong hop le!\n", opts);
			}
		} while (!is_opts_valid);

		switch (opts) {
		case ADD:
			if (add_student(p, len_max, len)) {
				len++;
			}
			break;
		case REMOVE:
			if (delete_student(p, len_max, len)) {
				len--;
			}
			break;
		case PRINT_BY_GRADE: {
			char grade[31];
			fflush(stdin);
			printf("nhap xep loai can liet ke: ");
			gets(grade);
			print_by_grade(p, len, grade);
			break;
		}
		case PRINT_HIGHEST:
			print_by_highest(p, len);
			break;
		case PRINT: {
			int i;
			for (i = 0; i < len; i++) {
				print_student(*(p + i));
			}
			break;
		}
		case SORT_AVG:
			sort_by_average(p, len);
			printf("da sap xep theo diem trung binh\n");
			printf("chon %d de in sinh vien trong danh sach\n", PRINT);
			break;
		case SORT_NAME:
			sort_by_name(p, len);
			printf("da sap xep theo ten\n");
			printf("chon %d de in sinh vien trong danh sach\n", PRINT);
			break;
		case PRINT_BY_NAME: {
			char name[31];
			fflush(stdin);
			printf("nhap ten sinh vien can tim: ");
			gets(name);
			print_by_name(p, len, name);
			break;
		}
		case PRINT_BY_CODE: {
			char code[6];
			fflush(stdin);
			printf("nhap ma sinh vien can tim: ");
			gets(code);
			print_by_code(p, len, code);
			break;
		}
		case EXIT:
			exit(0);
		default:
			printf("chuong chinh co loi, xin sua lai\n");
		}
		printf("\n");
	}
}

void print_by_code(struct student *ptr_arr, int size, char *code)
{
	int i = 0;
	for (i = 0; i < size; i++) {
		struct student student = *(ptr_arr + i);
		if (strcmp(student.code, code) == 0) {
			print_student(student);
		}
	}
}
void print_by_name(struct student *ptr_arr, int size, char *name)
{
	int i = 0;
	for (i = 0; i < size; i++) {
		struct student student = *(ptr_arr + i);
		if (strcmp(student.name, name) == 0) {
			print_student(student);
		}
	}
}

void print_by_grade(struct student *ptr_arr, int size, char *grade)
{
	int i = 0;
	for (i = 0; i < size; i++) {
		struct student student = *(ptr_arr + i);
		if (strcmp(student.grade, grade) == 0) {
			print_student(student);
		}
	}
}

void print_by_highest(struct student *ptr_arr, int size)
{
	float highest = 0;
	int i = 0;
	for (i = 0; i < size; i++) {
		struct student student = *(ptr_arr + i);
		if (highest < student.average) {
			highest = student.average;
		}
	}
	for (i = 0; i < size; i++) {
		struct student student = *(ptr_arr + i);
		if (highest == student.average) {
			print_student(student);
		}
	}
}

void print_student(struct student student)
{
	printf("[%s] %s:\n", student.code, student.name);
	int i;
	for (i = 0; i < student.subject_cnt; i++) {
		struct subject subject = student.subjects[i];
		printf("%s: %.2f", subject.name, subject.value);
		if (i % 2 == 0 && i != 0) {
			printf("\n");
		} else {
			printf(" - ");
		}
	}
	printf("diem trung binh: %.2f -> %s\n", student.average, student.grade);
	printf("\n");
}

void sort_by_average(struct student *ptr_arr, int size)
{
	int is_sorted;
	do {
		is_sorted = 1;
		int i;
		for (i = 1; i < size; i++) {
			struct student *ptr_std = ptr_arr + i;
			struct student *ptr_pre_std = ptr_arr + i - 1;
			if (ptr_pre_std->average > ptr_std->average) {
				swap(ptr_std, ptr_pre_std);
				is_sorted = 0;
			}
		}
	} while (!is_sorted);
}

void sort_by_name(struct student *ptr_arr, int size)
{
	int is_sorted;
	do {
		is_sorted = 1;
		int i;
		for (i = 1; i < size; i++) {
			struct student *ptr_std = ptr_arr + i;
			struct student *ptr_pre_std = ptr_arr + i - 1;
			if (strcmp(ptr_pre_std->name, ptr_std->name) > 0) {
				swap(ptr_std, ptr_pre_std);
				is_sorted = 0;
			}
		}
	} while (!is_sorted);
}

void swap(struct student *a, struct student *b)
{
	struct student tmp = *a;
	*a = *b;
	*b = tmp;
}

int add_student(struct student *ptr_arr, int len_max, int len)
{
	int pos;
	printf("nhap vi tri can them: ");
	scanf("%d", &pos);
	if (len >= len_max) {
		printf("danh sach da day, chon %d de xoa bot sinh vien\n", REMOVE);
	} else if (pos < 0 || pos >= len_max) {
		printf("vi tri khong hop le (0-%d)\n", len_max - 1);
	} else {
		struct student student = get_student();
		if (pos < len) {
			shift(ptr_arr, len_max, pos);
			*(ptr_arr + pos) = student;
		} else {
			printf("them sinh vien vao cuoi danh sach\n");
			pos = len;
			*(ptr_arr + pos) = student;
		}
		printf("da them sinh vien vao vi tri %d\n", pos);
		printf("chon %d de in sinh vien trong danh sach\n", PRINT);
		return 1;
	}
	return 0;
}

void shift(struct student *ptr_arr, int size, int pos)
{
	if (pos < size && pos >= 0) {
		struct student tmp = *(ptr_arr + pos);
		int i = 0;
		for (i = pos + 1; i < size; i++) {
			struct student *ptr_current = ptr_arr + i;
			struct student current = *ptr_current;
			*ptr_current = tmp;
			tmp = current;
		}
	}
}

int delete_student(struct student *ptr_arr, int len_max, int len)
{
	int pos;
	printf("nhap vi tri can xoa: ");
	scanf("%d", &pos);
	if (len <= 0) {
		printf("danh sach da rong, chon %d de them sinh vien\n", ADD);
	} else if (pos < 0 || pos >= len_max) {
		printf("vi tri khong hop le (0-%d)\n", len_max - 1);
	} else {
		if (pos < len) {
			delete(ptr_arr, len, pos);
			printf("da xoa sinh vien tai vi tri %d\n", pos);
			printf("chon %d de in sinh vien trong danh sach\n", PRINT);
			return 1;
		}
		printf("sinh vien khong ton tai");
	}
	return 0;
}

void delete(struct student *ptr_arr, int size, int pos)
{
	if (pos < size && pos >= 0) {
		int i = 0;
		for (i = pos; i < size - 1; i++) {
			struct student *ptr_current = ptr_arr + i;
			struct student *ptr_nxt = ptr_arr + i + 1;
			*ptr_current = *ptr_nxt;
		}
	}
}

/* student spec */
struct student get_student()
{
	struct student student;
	fflush(stdin);
	printf("nhap ma sinh vien (toi da 5 ki tu): ");
	scanf("%5s", &student.code[0]);
	fflush(stdin);
	printf("nhap ten sinh vien (toi da 30 ki tu): ");
	gets(&student.name[0]);
	fflush(stdin);

	student.subject_cnt = 5;
	get_subjects(&student.subjects[0], student.subject_cnt);
	student.average = get_average(&student.subjects[0], student.subject_cnt);
	grading(student.average, student.grade);

	return student;
}

void get_subjects(struct subject *subject, int size)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("mon thu %d/%d:\n", i + 1, size);
		*(subject + i) = get_subject();
	}
}

struct subject get_subject()
{
	struct subject subject;
	fflush(stdin);
	printf("nhap ma mon (toi da 5 ki tu): ");
	scanf("%5s", &subject.code[0]);
	fflush(stdin);
	printf("nhap ten mon (toi da 30 ki tu): ");
	gets(&subject.name[0]);
	fflush(stdin);
	printf("nhap so tin chi: ");
	scanf("%d", &subject.credit);
	printf("nhap diem mon: ");
	scanf("%f", &subject.value);
	return subject;
}

float get_average(struct subject *subject, int size)
{
	float sum = 0;
	int avg_factor = 0;
	int i;
	for (i = 0; i < size; i++) {
		struct subject current = *(subject + i);
		avg_factor += current.credit;
		sum += current.value * (float) current.credit;
	}
	return (sum / (float) avg_factor);
}

void grading(float average, char *grade)
{
	if (average < 5) {
		strcpy(grade, "yeu");
	} else if (average >= 5 && average < 6.5) {
		strcpy(grade, "trung binh");
	} else if (average >= 6.5 && average < 8) {
		strcpy(grade, "kha");
	} else if (average >= 8 && average < 9) {
		strcpy(grade, "gioi");
	} else if (average >= 9 && average <= 10) {
		strcpy(grade, "xuat sac");
	} else {
		strcpy(grade, "quai vat");
	}
}
