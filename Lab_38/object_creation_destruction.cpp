#include "object_creation_destruction.hpp"


Class::Class(){
    a = 'a';
    std::cout<<"Called Default Constructor"<<std::endl;
}

Class::Class(Class o){
    a = o.a;
    std::cout<<"Called Copy Constructor"<<std::endl;
}

Class::~Class(){
    std::cout<<"Called Destructor"<<std::endl;
}

Class& Class::operator=(const Class& o){
    if (this == &o){
        return *this;
    }

    a = a;
    std::cout<<"Called Assignment Operator"<<std::endl;
}
