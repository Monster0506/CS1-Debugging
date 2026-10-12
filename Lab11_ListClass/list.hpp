#ifndef LIST_HPP
#define LIST_HPP

class List {
public:
  List();
  int size() const { return size_; }

  int check(double number);   // index of number, or -1
  void addNumber(double);     // adds unless already present
  void removeNumber(double);  // removes if present
  void output();              // prints the values

  // big three
  List(const List &);
  List &operator=(const List &);
  ~List();

private:
  double *list_;
  int size_;
};

#endif
