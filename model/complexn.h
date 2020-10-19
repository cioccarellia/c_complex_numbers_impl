#pragma once

typedef struct complex_struct {
    double a;
    double b;
} complex;

double __intern_complex_roh(complex c);
double __intern_complex_theta(complex c);

complex complex_of(double a, double b);
complex complex_sum(complex v, complex w);
complex complex_mul(complex v, complex w);
complex complex_exp(complex v, unsigned int n);
complex complex_90rot(complex v, unsigned int n);
complex complex_180rot(complex v, unsigned int n);
complex complex_270rot(complex v, unsigned int n);

void complex_print(complex c);
void complex_print_int(complex c);