#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "complexn.h"

#define i complex_of(0, 1)
#define i2 complex_of(-1, 0)
#define i3 complex_of(0, -1)
#define i4 complex_of(1, 0)


double __intern_complex_roh(complex z) {
    return sqrt(pow(z.a, 2) + pow(z.b, 2));
};

double __intern_complex_theta(complex z) {
    double a = z.a, b = z.b;

    if (a == 0 && b == 0) {
        exit(-1);
    }

    if (a != 0 && b > 0) {
        return atan(b / a);
    } else if (a != 0 && b < 0) {
        return atan((b / a) + M_PI);
    } else if (a == 0 && b > 0) {
        return M_PI / 2;
    } else if (a == 0 && b < 0) {
        return (3 * M_PI) / 2;
    }

    return 0;
}


complex complex_of(double a, double b) {
    complex ret = {
            .a = a,
            .b = b
    };

    return ret;
}

complex complex_sum(complex v, complex w) {
    complex ret = {
            .a = v.a + w.a,
            .b = v.b + w.b
    };

    return ret;
}


complex complex_mul(complex v, complex w) {
    double v_roh = __intern_complex_roh(v),
           w_roh = __intern_complex_roh(w);

    double v_theta = __intern_complex_theta(v),
           w_theta = __intern_complex_theta(w);

    double z_roh = v_roh * w_roh;
    double z_theta = v_theta + w_theta;

    complex ret = {
            .a = (z_roh * cos(z_theta)),
            .b = (z_roh * sin(z_theta))
    };

    return ret;
}

complex complex_mul_n(complex v, complex w, unsigned int n) {
    complex base = complex_of(0, 0);

    for (int j = 0; j < n; j++) {
        base = complex_sum(base, complex_mul(v, w));
    }

    return base;
}

complex complex_exp(complex v, unsigned int n) {
    double v_roh = __intern_complex_roh(v);
    double v_theta = __intern_complex_theta(v);

    double z_roh = pow(v_roh, n);
    double z_theta = v_theta * n;

    complex ret = {
            .a = (z_roh * cos(z_theta)),
            .b = (z_roh * sin(z_theta))
    };

    return ret;
}

complex complex_90rot(complex v, unsigned int n) {
    return complex_mul_n(v, i, n);
}

complex complex_180rot(complex v, unsigned int n) {
    return complex_mul_n(v, i2, n);
}

complex complex_270rot(complex v, unsigned int n) {
    return complex_mul_n(v, i3, n);
}

void complex_print(complex c) {
    printf("(%f,%fi)\n", c.a, c.b);
}

void complex_print_int(complex c) {
    int _a = (int) c.a, _b = (int) c.b;
    printf("(%d,%di)\n", _a, _b);
}