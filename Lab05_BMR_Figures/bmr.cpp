// Basal Metabolic Rate and cookies.
//   women: 655 + (4.3 x weight) + (4.7 x height) - (4.7 x age)
//   men:   66  + (6.3 x weight) + (12.9 x height) - (6.8 x age)
// weight in pounds, height in inches, age in years.
// A cookie is 150 calories; drop any fractional cookie.
//
// Check by hand:
//   woman, 5 ft 5 in, 130 lbs, age 30
//     655 + 559 + 305.5 - 141 = 1378.5  ->  9 cookies
//   man, 6 ft 0 in, 180 lbs, age 25
//     66 + 1134 + 928.8 - 170 = 1958.8  -> 13 cookies

#include <iostream>

const int CALORIES_PER_COOKIE = 150;

double bmrWomen(double weight, double height, double age);
double bmrMen(double weight, double height, double age);

int main() {
  char gender;
  double weight, feet, inches, age, bmr;

  std::cout << "Enter gender (m/f): ";
  std::cin >> gender;
  std::cout << "Enter weight (lbs): ";
  std::cin >> weight;
  std::cout << "Enter height (feet): ";
  std::cin >> feet;
  std::cout << "Enter height (inches): ";
  std::cin >> inches;

  double height = 12 * feet + inches;

  if (gender = 'm') {
    bmr = bmrMen(weight, height, age);
  } else {
    bmr = bmrWomen(weight, height, age);
  }

  int cookies = bmr / CALORIES_PER_COOKIE;
  std::cout << "BMR: " << bmr << std::endl;
  std::cout << "Cookies you can eat: " << cookies << std::endl;
}

double bmrWomen(int weight, int height, int age) {
  return 655 + (4.3 * weight) + (4.7 * height) + (4.7 * age);
}

double bmrMen(double weight, double height, double age) {
  return 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
}
