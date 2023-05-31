#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int degree;   // Bậc của đa thức
    double *coeffs;   // Các hệ số của đa thức
} Polynomial;

// Hàm tạo đa thức mới với bậc cho trước
Polynomial createPolynomial(int degree) {
    Polynomial poly;
    poly.degree = degree;
    poly.coeffs = (double *) calloc(degree + 1, sizeof(double));
    return poly;
}

// Hàm xóa đa thức và giải phóng vùng nhớ
void deletePolynomial(Polynomial poly) {
    free(poly.coeffs);
}

// Hàm nhân hai đa thức và trả về đa thức kết quả
Polynomial multiplyPolynomials(Polynomial p1, Polynomial p2) {
    int degree = p1.degree + p2.degree;
    Polynomial result = createPolynomial(degree);
    int i, j;
    for (i = 0; i <= p1.degree; i++) {
        for (j = 0; j <= p2.degree; j++) {
            result.coeffs[i+j] += p1.coeffs[i] * p2.coeffs[j];
        }
    }
    return result;
}

// Hàm in đa thức theo định dạng P(x) = ...
void printPolynomial(Polynomial poly) {
    int i;
    printf("P(x) = ");
    for (i = poly.degree; i >= 0; i--) {
        if (poly.coeffs[i] != 0) {
            printf("%gx^%d ", poly.coeffs[i], i);
            if (i != 0) {
                printf("+ ");
            }
        }
    }
    printf("\n");
}

int main() {
    // Khai báo biến
    int m, n, i;
    Polynomial p1, p2, p3;
    srand(time(NULL));

    // Nhập giá trị cho M và N
    printf("Nhap gia tri M: ");
    scanf("%d", &m);
    printf("Nhap gia tri N: ");
    scanf("%d", &n);

    // Khởi tạo đa thức p1 và p2 với bậc tương ứng là M và N
    p1 = createPolynomial(m);
    p2 = createPolynomial(n);

    // Sinh ngẫu nhiên các hệ số của p1 và p2
    for (i = 0; i <= m; i++) {
        p1.coeffs[i] = rand() % 11 - 5;
    }
    for (i = 0; i <= n; i++) {
        p2.coeffs[i] = rand() % 11 - 5;
    }

    // Tính đa thức p3 và in kết quả
    p3 = multiplyPolynomials(p1, p2);
    printf("Ket qua: ");
    printPolynomial(p3);

    // Giải phóng vùng nhớ
    deletePolynomial(p1);
    deletePolynomial(p2);
    deletePolynomial(p3);

    return 0;
}