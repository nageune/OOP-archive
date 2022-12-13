#include "registrar.h"

void Registrar::enroll(Student student, Course course) {
    student.getSchedule().addCourse(course.getName());
    course.getRoster().addStudent(student.getName());
}
