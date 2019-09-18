#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT 1
#define FIND 2
#define EDIT 3
#define SAVE 4
#define EXIT 5

struct book {
	char name[31];
	char author[31];
	char publisher[31];
	int year;
	float price;
};

struct book get_book();

void print_book(struct book book);

void print_by_name(struct book *p_book, int size, char *name);

int main(int argc, char const *argv[])
{
	int opts;
	int is_opts_valid;
	int max_len;
	printf("nhap so luong sach: ");
	scanf("%d", &max_len);
	struct book books[max_len];

	int i;
	for (i = 0; i < max_len; i++) {
		printf("nhap thong tin sach %d/%d:\n", i + 1, max_len);
		books[i] = get_book();
	}
	printf("\n");

	/* menu */
	while (1) {
		do {
			printf("chon 1 trong cac lua chon sau:\n");
			printf("%d. in thong tin sach\n", PRINT);
			printf("%d. tim kiem sach theo ten\n", FIND);
			printf("%d. sua thong tin sach\n", EDIT);
			printf("%d. luu thong tin sach\n", SAVE);
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
		case PRINT: {
			int i;
			for (i = 0; i < max_len; i++) {
				print_book(books[i]);
				printf("\n");
			}
			break;
		}
		case FIND: {
			char name[31];
			fflush(stdin);
			printf("nhap ten sach: ");
			fgets(name, 30, stdin);
			print_by_name(&books[0], max_len, name);
			break;
		}
		case EDIT: {
			int pos;
			fflush(stdin);
			printf("nhap vi tri can sua: ");
			scanf("%d", &pos);
			if (pos >= 0 && pos < max_len) {
				printf("nhap thong tin: \n");
				struct book book = get_book();
				books[i] = book;
				printf("da sua thong tin sach %d", pos);
			} else {
				printf("vi tri %d khong hop le", pos);
			}
			break;
		}
		case SAVE: {
			char path[] = ".\\books";
			FILE *fp = fopen(path, "w");
			int i;
			for (i = 0; i < max_len; i++) {
				fprintf(fp, "%d. ten sach: %s - ", i + 1, books[i].name);
				fprintf(fp, "tac gia: %s - ", books[i].author);
				fprintf(fp, "xuat ban: %s -", books[i].publisher);
				fprintf(fp, "nam: %d -", books[i].year);
				fprintf(fp, "gia: %.2f\n", books[i].price);
			}
			fflush(fp);
			fclose(fp);
			printf("da xuat ra file %s", path);
			break;
		}
		case EXIT:
			exit(0);
		default:
			printf("chuong chinh co loi, xin thu lai\n");
		}
		printf("\n");
	}

	return 0;
}

void print_by_name(struct book *p_book, int size, char *name) {
	int i;
	for (i = 0; i < size; i++) {
		struct book book = *(p_book + i);
		if (strcmp(book.name, name) == 0) {
			print_book(book);
		}
	}
}

struct book get_book()
{
	struct book book;
	fflush(stdin);
	printf("nhap ten sach: ");
	fgets(book.name, 30, stdin);
	printf("nhap ten tac gia: ");
	fgets(book.author, 30, stdin);
	printf("nhap ten nha xuat ban: ");
	fgets(book.publisher, 30, stdin);
	fflush(stdin);
	printf("nhap nam xuat ban: ");
	scanf("%d", &book.year);
	printf("nhap gia tien: ");
	scanf("%f", &book.price);
	return book;
}

void print_book(struct book book)
{
	printf("ten sach: %s", book.name);
	printf("tac gia: %s", book.author);
	printf("nha xuat ban: %s", book.publisher);
	printf("nam xuat ban: %d\n", book.year);
	printf("gia tien: %.2f\n", book.price);
}
