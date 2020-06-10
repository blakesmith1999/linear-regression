#include "Summation.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <fstream>





Summation::Summation() {
    input_x.clear();
    input_y.clear();
    sum_x_ = 0;
    sum_y_ = 0;
    sum_xy_ = 0;
    sum_sqr_ = 0;
    sqr_sum_ = 0;
    n = 0;
    a0 = 0;
    a1 = 0;
}


void Summation::set_x(std::vector<double> x) {
    //Populates the input_x vector with the desired values.
    for (int i = 0; i < x.size(); i++) {
        double element = x.at(i);
        input_x.push_back(element);
    }
}

void Summation::set_y(std::vector<double> y) {
    //Populates the input_y vector with the desired values.
    for (int i = 0; i < y.size(); i++) {
        double element = y.at(i);
        input_y.push_back(element);
    }
}

void Summation::std_sum_x() {
    //Finds the sum of the x values.
    double sum = 0;
    for (int i = 0; i < input_x.size(); i++) {
        double element = input_x.at(i);
        sum += element;
    }
    sum_x_ = sum;
}

void Summation::std_sum_y() {
    //Finds the sum of the y values.
    double sum = 0;
    for (int i = 0; i < input_y.size(); i++) {
        double element = input_y.at(i);
        sum += element;
    }
    sum_y_ = sum;
}

void Summation::std_sum_xy() {
    //Finds the sum of each x and y pair multiplied together.
    double sum = 0;
    for (int i = 0; i < input_x.size(); i++) {
        double x = input_x.at(i), y = input_y.at(i);
        sum += (x * y);
    }
    sum_xy_ = sum;
}

void Summation::sum_of_sqr() {
    //Finds the sum of each x value squared.
    double sum = 0;
    for (int i = 0; i < input_x.size(); i++) {
        double element = input_x.at(i);
        sum += pow(element, 2);
    }
    sum_sqr_ = sum;
}

void Summation::sqr_of_sum() {
    //Finds the value given by the square of the sum of the x values.
    double sum = 0;
    for (int i = 0; i < input_x.size(); i++) {
        double element = input_x.at(i);
        sum += element;
    }
    sqr_sum_ = pow(sum, 2);
}

void Summation::sum_x_lny() {
    int sum = 0;
    for (int i = 0; i < input_x.size(); i++) {
        double element1 = input_x.at(i);
        double element2 = 0;
        if (input_y.at(i) != 0) {
            element2 = log(input_y.at(i));
        }
        sum += (element1 * element2);
    }
    sum_x_lny_ = sum;
    std::cout << sum_x_lny_ << std::endl;
}

void Summation::sum_lny_sqr() {
    int sum = 0;

    for (int i = 0; i < input_x.size(); i++) {
        double element = pow(log(input_y.size()), 2);
        sum += element;
    }
    sum_lny_sqr_ = sum;
    std::cout << sum_lny_sqr_ << std::endl;
}

void Summation::find_n() {
    //Finds the number of coordinate pairs.
    n = input_x.size();
}

void Summation::find_a0() {
    //Finds a0 in the linear regression equation.
    a0 = (((sum_sqr_ * sum_y_) - (sum_x_ * sum_xy_)) / (n * sum_sqr_ - sqr_sum_));
}

void Summation::find_a1() {
    //Finds a1 in the linear regression equation
    a1 = ((n * sum_xy_ - sum_x_ * sum_y_) / (n * sum_sqr_ - sqr_sum_));
}

void Summation::find_x_av() {
    int sum = 0;
    for (int i = 0; i < input_x.size(); i++) {
        double element = input_x.at(i);
        sum += element;
    }
    x_av_ = sum / n;
    //std::cout << x_av_ << std::endl;
}

void Summation::find_lny_av() {
    int sum = 0;
    for (int i = 0; i < input_y.size(); i++) {
        double element = 0;
        if (input_y.at(i) != 0) {
            double element = log(input_y.at(i));
        }
        sum += element;
    }
    lny_av_ = sum / n;
    //std::cout << lny_av_ << std::endl;
}

void Summation::Sxx() {
    Sxx_ = sum_sqr_ - (n * pow(x_av_, 2));
    //std::cout << Sxx_ << std::endl;
}

void Summation::Sxy() {
    Sxy_ = sum_x_lny_ - (n * x_av_ * lny_av_);
    //std::cout << Sxy_ << std::endl;
}

void Summation::Syy() {
    Syy_ = sum_lny_sqr_ - (n * pow(lny_av_, 2));
    //std::cout << Syy_ << std::endl;
}

void Summation::find_r() {
    r_ = Sxy_ / (pow(Sxx_, 0.5) * pow(Syy_, 0.5));
    //std::cout << r_ << std::endl;
}

void Summation::find_B() {
    B_ = exp(Sxy_ / Sxx_);
    //std::cout << B_ << std::endl;
}

void Summation::find_A() {
    A_ = exp(lny_av_ - (x_av_ * exp(B_)));
    //std::cout << A_ << std::endl;
}

void Summation::initialize_variables() {
    //Initializes and sets all of the variables necessary for the equation.
    std_sum_x();
    std_sum_y();
    std_sum_xy();
    sum_of_sqr();
    sqr_of_sum();
    sum_x_lny();
    sum_lny_sqr();
    find_n();
    find_a0();
    find_a1();
    find_x_av();
    find_lny_av();
    Sxx();
    Sxy();
    Syy();
    find_A();
    find_B();
}

void Summation::regression_prediction() {
    //Function for user input
    double x_value;
    std::cout << "\nEnter your x-value: ";
    std::cin >> x_value;
    std::cout << "The predicted linear y-value is: " << a0 + (a1 * x_value) << std::endl;
    //std::cout << "The predicted exponential y-value is: " << A_ * (pow(B_, x_value)) << std::endl;
}

void Summation::print_regression() {
    //the only function called in main
    std::string filename;
    std::vector<double> x, y;


    std::cout << "Please indicate the name of the file to be analyzed(data.txt): ";
    std::cin >> filename;
    
    
    //find the file, call setx and y
    
    std::ifstream file;

    
    file.open(filename);
    if (file.is_open()) {
        std::string digit;
        while(std::getline(file,digit)){
            int x_digit = digit[0]-'0';
            int y_digit = digit[2]-'0';
            x.push_back(x_digit);
            y.push_back(y_digit);
        }
    }
    file.close();

    set_x(x);
    set_y(y);

    initialize_variables();
    //initialize all the variables based on file input to x and y

    std::cout << "The linear regression of this dataset is: fit(y)= " << a0 << " + " << a1 << "x" << std::endl;
    //std::cout << "The exponential regression of this dataset is: fit(y)= " << A_ << "(" << B_ << ")^x" << std::endl;
    //std::cout << "The correlation coefficient of this dataset is: " << r_ << std::endl;
    char cont;
    do {
        std::cout << "Would you like me to predict a y-value for your x-value? (y/n): ";
        std::cin >> cont;
        if (cont == 'y') {
            regression_prediction();
        }
        else if (cont != 'n') {
            std::cout << "Please enter a valid input" << std::endl;
        }
    } while (cont != 'n');


    std::cout << "Have a nice day" << std::endl;
    
}