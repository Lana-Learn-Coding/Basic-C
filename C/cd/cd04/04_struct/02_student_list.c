#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADD 1
#define REMOVE 2
#define PRINT 3
#define PRINT_BY_GRADE 4
#define PRINT_HIGHEST 5
#define EXIT 6

struct subject {
	char code[6];
	char name[31];
	float credit;
	float value;
};

struct mark {
	struct subject math_a1;
	struct subject math_a2;
	struct subject physics;
	struct subject english;
};

struct student {
	char code[6];
	char name[31];
	char grade[31];
	float average;
	struct mark marks;
};

void print_by_grade(struct student *ptr_arr, int size, char *grade);

void print_by_highest(struct student *ptr_arr, int size);

int is_str_equals(char *str1, char *str2);

int add_student(struct student *ptr_arr, int len_max, int len);

void shift(struct student *ptr_arr, int size, int pos);

int delete_student(struct student *ptr_arr, int len_max, int len);

void delete(struct student *ptr_arr, int size, int pos);

struct student get_student();

struct mark get_mark();

void print_student(struct student student);

float get_average(struct mark mark);

void grading(float average, char *grade);

int main(int argc, char const *argv[]) {
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
		case EXIT:
			exit(0);
		default:
			printf("chuong chinh co loi, xin sua lai\n");
		}
		printf("\n");
	}
}

void print_by_highest(struct student *ptr_arr, int size) {
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

void print_by_grade(struct student *ptr_arr, int size, char *grade) {
	int i = 0;
	for (i = 0; i < size; i++) {
		struct student student = *(ptr_arr + i);
		if (is_str_equals(student.grade, grade)) {
			print_student(student);
		}
	}
}

int is_str_equals(char *str1, char *str2) {
	int len = strlen(str1);
	if (len == strlen(str2)) {
		int i;
		for (i = 0; i < len; i++) {
			char c1 = *(str1 + i);
			char c2 = *(str2 + i);
			if (c1 != c2) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int add_student(struct student *ptr_arr, int len_max, int len) {
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

void shift(struct student *ptr_arr, int size, int pos) {
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


void delete(struct student *ptr_arr, int size, int pos) {
	if (pos < size && pos >= 0) {
		int i = 0;
		for (i = pos; i < size - 1; i++) {
			struct student *ptr_current = ptr_arr + i;
			struct student *ptr_nxt = ptr_arr + i + 1;
			*ptr_current = *ptr_nxt;
		}
	}
}

int delete_student(struct student *ptr_arr, int len_max, int len) {
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

/* student spec */
struct student get_student() {
	struct student student;
	fflush(stdin);
	printf("nhap ma sinh vien (toi da 5 ki tu): ");
	scanf("%s", &student.code[0]);
	fflush(stdin);
	printf("nhap ten sinh vien (toi da 30 ki tu): ");
	gets(&student.name[0]);
	fflush(stdin);

	student.marks = get_mark();
	student.average = get_average(student.marks);
	grading(student.average, student.grade);

	return student;
}

struct mark get_mark() {
	struct subject math_a1 = {"m1001", "toan a1", 2};
	struct subject math_a2 = {"m1002", "toan a2", 2};
	struct subject physics = {"p1001", "vat ly", 1};
	struct subject english = {"e1001", "tieng anh", 3};
	struct mark mark = {math_a1, math_a2, physics, english};

	printf("[%s] nhap diem mon %s: ", mark.math_a1.code, mark.math_a1.name);
	scanf("%f", &mark.math_a1.value);
	printf("[%s] nhap diem mon %s: ", mark.math_a2.code, mark.math_a2.name);
	scanf("%f", &mark.math_a2.value);
	printf("[%s] nhap diem mon %s: ", mark.physics.code, mark.physics.name);
	scanf("%f", &mark.physics.value);
	printf("[%s] nhap diem mon %s: ", mark.english.code, mark.english.name);
	scanf("%f", &mark.english.value);
	return mark;
}

void print_student(struct student student) {
	printf("[%s] %s:\n", student.code, student.name);
	printf("%s: %.2f - ", student.marks.math_a1.name, student.marks.math_a1.value);
	printf("%s: %.2f\n", student.marks.math_a2.name, student.marks.math_a2.value);
	printf("%s: %.2f - ", student.marks.physics.name, student.marks.physics.value);
	printf("%s: %.2f\n", student.marks.english.name, student.marks.english.value);
	printf("diem trung binh: %.2f -> %s\n", student.average, student.grade);
	printf("\n");
}

float get_average(struct mark mark) {
	float avg_factor = mark.math_a1.credit +
	                   mark.math_a2.credit +
	                   mark.physics.credit +
	                   mark.english.credit;
	return (mark.math_a1.value * mark.math_a1.credit +
	        mark.math_a2.value * mark.math_a2.credit +
	        mark.physics.value * mark.physics.credit +
	        mark.english.value * mark.english.credit) / avg_factor;

}

void grading(float average, char *grade) {
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
	}
}
