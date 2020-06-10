#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include <vector>


class Summation
{
public:
    Summation();
    void set_x(std::vector<double> x);
    void set_y(std::vector<double> y);
    void std_sum_x();
    void std_sum_y();
    void std_sum_xy();
    void sum_of_sqr();
    void sqr_of_sum();
    void sum_x_lny();
    void sum_lny_sqr();
    void find_n();
    void find_a0();
    void find_a1();
    void find_x_av();
    void find_lny_av();
    void Sxx();
    void Sxy();
    void Syy();
    void find_r();
    void find_A();
    void find_B();
    void initialize_variables();
    void regression_prediction();
    void print_regression();

private:
    std::vector<double> input_x;
    std::vector<double> input_y;
    double sum_x_;
    double sum_y_;
    double sum_xy_;
    double sum_sqr_;
    double sqr_sum_;
    double sum_x_lny_;
    double sum_lny_sqr_;
    double n;
    double a0;
    double a1;
    double x_av_;
    double lny_av_;
    double Sxx_;
    double Sxy_;
    double Syy_;
    double r_;
    double B_;
    double A_;
};

#endif