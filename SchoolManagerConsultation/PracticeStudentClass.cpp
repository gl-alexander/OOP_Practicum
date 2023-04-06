#include <iostream>
#include "School.h"

int main()
{   
    std::cout << "Hello World!\n";

    School s;
    s.addStudent("ivan", "petrov");
    s.addStudent("dragan", "sefot");
    s.addStudent("manol", "manol");
    s.addStudent("georgi", "velizarov");
    s.addStudent("hussein", "armqnov");

    School d = s;
    //d.saveSchoolToFile("random.dat");

    //School b("random.dat");
    std::cout << s.getStudent(2).getFirstName() << " --- " << s.getStudent(2).getLastName();
}

