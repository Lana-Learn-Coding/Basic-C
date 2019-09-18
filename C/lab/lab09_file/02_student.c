#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT 1
#define PRINT 2
#define READ 3
#define SAVE 4
#define HIGHEST_D 5
#define HIGHEST_T 6
#define EXIT 7

struct student {
	char code[6];
	char name[31];
	char class[31];
	int birth_year;
	float mark_t;
	float mark_d;
};

struct student get_student();
void print_by_highest_t(struct student *p_student, int size);
void print_by_highest_d(struct student *p_student, int size);
void print_students(struct student *p_student, int size);
void sort_by_avg(struct student *p_student, int size);
void swap(struct student *a, struct student *b);
void print_student(struct student student);
float get_avg(struct student student);
void print_grading(struct student student);


int main(int argc, char const *argv[])
{
	int opts;
	int is_opts_valid;
	int max_len , len = 0;
	printf("nhap so luong hoc sinh toi da: ");
	scanf("%d", &max_len);
	struct student students[max_len];

	/* menu */
	while (1) {
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. nhap thong tin sinh vien\n", INPUT);
			printf("%d. in danh sach sinh vien\n", PRINT);
			printf("%d. doc thong tin sinh vien\n", READ);
			printf("%d. luu thong tin sinh vien\n", SAVE);
			printf("%d. tim sinh vien co diem thuc hanh cao nhat\n", HIGHEST_D);
			printf("%d. tim sinh vien co diem ly thuyet cao nhat\n", HIGHEST_T);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			printf("\n");

			is_opts_valid = opts >= 1 && opts <= EXIT;
			if (!is_opts_valid) {
				printf("lua chon cua ban (%d) khong hop le!\n", opts);
			}
		} while (!is_opts_valid);

		switch (opts) {
		case INPUT:
			printf("nhap thong tin sinh vien:\n");
			students[len] = get_student();
			len++;
			break;
		case PRINT: {
			print_students(students, len);
			break;
		}
		case SAVE: {
			char path[] = ".\\students.txt";
			FILE *fp = fopen(path, "wb");
			/* write number of student. */
			fwrite(&len, sizeof(int), 1, fp);
			/* write students. */
			int write_result = fwrite(students, sizeof(struct student), len, fp);
			fflush(fp);
			fclose(fp);
			printf("da xuat %d sv ra file %s", write_result, path);
			break;
		}
		case READ: {
			int saved_len = 0;
			char path[] = ".\\students.txt";
			FILE *fp = fopen(path, "rb");
			/* read number of student. */
			fread(&saved_len, sizeof(int), 1, fp);
			/* read students. */
			int read_result = fread(students, sizeof(struct student), saved_len, fp);
			fclose(fp);

			printf("da nap %d sv tu file %s", read_result, path);
			len = saved_len;
			break;
		}
		case HIGHEST_T:
			printf("danh sach sv co diem ly thuyet cao nhat: \n");
			print_by_highest_t(students, len);
			break;
		case HIGHEST_D:
			printf("danh sach sv co diem thuc hanh cao nhat: \n");
			print_by_highest_d(students, len);
			break;
		case EXIT:
			exit(0);
		default:
			printf("chuong chinh co loi, xin thu lai\n");
		}
		printf("\n\n");
	}

	return 0;
}

struct student get_student()
{
	struct student student;
	fflush(stdin);
	printf("nhap ma sv: ");
	scanf("%5s", &student.code);
	fflush(stdin);
	printf("nhap ten sv: ");
	scanf("%30s", &student.name);
	fflush(stdin);
	printf("nhap ten lop: ");
	scanf("%30s", &student.class);
	fflush(stdin);
	printf("nhap nam sinh: ");
	scanf("%d", &student.birth_year);
	printf("nhap diem ly thuyet: ");
	scanf("%f", &student.mark_t);
	printf("nhap diem thuc hanh: ");
	scanf("%f", &student.mark_d);
	return student;
}

void print_by_highest_t(struct student *p_student, int size)
{
	float highest = 0;
	int i = 0;
	for (i = 0; i < size; i++) {
		struct student student = *(p_student + i);
		if (highest < student.mark_t) {
			highest = student.mark_t;
		}
	}
	for (i = 0; i < size; i++) {
		struct student student = *(p_student + i);
		if (highest == student.mark_t) {
			print_student(student);
		}
	}
}

void print_by_highest_d(struct student *p_student, int size)
{
	float highest = 0;
	int i = 0;
	for (i = 0; i < size; i++) {
		struct student student = *(p_student + i);
		if (highest < student.mark_d) {
			highest = student.mark_d;
		}
	}
	for (i = 0; i < size; i++) {
		struct student student = *(p_student + i);
		if (highest == student.mark_d) {
			print_student(student);
		}
	}
}

void print_students(struct student *p_student, int size) {
	sort_by_avg(p_student, size);
	int i;
	for (i = 0; i < size; i++) {
		print_student(*(p_student + i));
	}
}

void sort_by_avg(struct student *p_student, int size) {
	int is_sorted;
	do {
		is_sorted = 1;
		int i;
		for (i = 1; i < size; i++) {
			struct student *ptr_std = p_student + i;
			struct student *ptr_pre_std = p_student + i - 1;
			float avg = get_avg(*ptr_std);
			float pre_avg = get_avg(*ptr_pre_std);
			if (pre_avg < avg) {
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

void print_student(struct student student)
{
	printf("[%s] %s (%d):\n", student.code, student.name, student.birth_year);
	printf("lop: %s\n", student.class);
	printf("ly thuyet: %.2f - thuc hanh: %.2f\n", student.mark_t, student.mark_d);
	printf("trung binh: %.2f ", get_avg(student));
	print_grading(student);
	printf("\n");
}

void print_grading(struct student student) {
	float mark_avg = get_avg(student);
	float mark_rate = mark_avg * 100 / 20;
	if (mark_rate < 40) {
		printf("-> thi lai\n");
	} else if (mark_rate < 75) {
		printf("-> kha\n");
	} else {
		printf("-> gioi\n");
	}
}

float get_avg(struct student student) {
	return (student.mark_d + student.mark_t) / 2;
}