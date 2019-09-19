#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WRITE 1
#define READ 2
#define EXIT 3

typedef struct student {
	char name[31];
	char class[31];
	int age;
} student;

student get_student();

int main(int argc, char const *argv[])
{
	char filename[] = "student_data.txt";
	while (1) {
		int opts;
		int is_opts_valid;
		do {

			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. nhap du lieu va luu ra file\n", WRITE);
			printf("%d. doc du lieu tu file\n", READ);
			printf("%d. thoat\n", EXIT);
			printf("lua chon cua ban la: ");
			scanf("%d", &opts);
			is_opts_valid = opts >= WRITE && opts <= EXIT;
			if (!is_opts_valid) {
				printf("lua chon cua ban (%d) khong hop le!\n", opts);
			}
		} while (!is_opts_valid);

		switch (opts) {
		case READ: {
			student student;
			FILE *fp = fopen(filename, "r");
			fscanf(fp, "%30s - %30s - %d", student.name, student.class, &student.age);
			printf("du lieu doc duoc la:\n");
			printf("%s - %s - %d\n", student.name, student.class, student.age);
			break;
		}
		case WRITE: {
			student student = get_student();
			FILE *fp = fopen(filename, "w");
			fprintf(fp, "%s - %s - %d", student.name, student.class, student.age);
			fflush(fp);
			fclose(fp);
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

student get_student() {
	student student;
	fflush(stdin);
	printf("nhap ten sv: ");
	scanf("%30s", student.name);
	fflush(stdin);
	printf("nhap ten lop: ");
	scanf("%30s", student.class);
	fflush(stdin);
	printf("nhap tuoi: ");
	scanf("%d", &student.age, 30);
	fflush(stdin);
	return student;
}
