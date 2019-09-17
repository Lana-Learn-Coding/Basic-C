#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct subject {
	char code[6];
	char name[31];
	int credit;
	float value;
};

struct mark {
	struct subject *p_subjects;
	int len;
};

struct student {
	char code[6];
	char name[31];
	struct mark marks;
};

struct student get_student();

struct mark get_mark();

void input_subjects(struct mark *mark);

void print_mark(struct mark mark);

int main(int argc, char const *argv[]) {

	getch();
	return 0;
}

struct student get_student() {
	struct student student;
	struct mark mark = get_mark();

	return student;
}

struct mark get_mark() {
	struct subject math_a1 = {"m1001", "toan a1", 2};
	struct subject math_a2 = {"m1002", "toan a2", 2};
	struct subject physics = {"p1001", "vat ly", 1};
	struct subject english = {"e1001", "tieng anh", 3};
	struct subject subjects[] = {math_a1, math_a2, physics, english};
	int len = sizeof(subjects) / sizeof(subjects[0]);
	struct mark mark = {&subjects[0], len};
	input_subjects(&mark);
	struct subject *p_sub = mark.p_subjects;
	int i;
	for (i = 0; i < 4; i++) {
		printf("%f \n", (*(p_sub + i)).value);
	}
	return mark;
}

void input_subjects(struct mark *mark) {
	int i;
	for (i = 0; i < mark->len; i++) {
		struct subject *p_subjects = mark->p_subjects + i;
		printf("%d. ", i + 1);
		printf("[%s] nhap diem mon %s: ", p_subjects->code, p_subjects->name);
		scanf("%f", &(p_subjects->value));
	}
}

void print_mark(struct mark mark) {
	int i;
	for (i = 0; i < mark.len; i++) {
		struct subject subject = *(mark.p_subjects + i);
		printf("diem so mon: %.2f\n", subject.value);
	}
}

int get_grade(struct mark mark) {

}

int get_average(struct mark mark) {
	/* TODO: not implemented */
}



