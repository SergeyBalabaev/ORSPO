#ifndef RESISTANCE_H
#define RESISTANCE_H

/**
 * Вычисляет общее сопротивление двух резисторов при параллельном соединении
 * @param r1 - указатель на сопротивление первого резистора (константный)
 * @param r2 - указатель на сопротивление второго резистора (константный)
 * @return общее сопротивление (double)
 */
double parallel_resistance(const double *r1, const double *r2);

#endif