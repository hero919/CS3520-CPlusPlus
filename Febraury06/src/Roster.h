#ifndef ROSTER_ROSTER_H
#define ROSTER_ROSTER_H

#include <vector>
#include <functional>
#include "Student.h"

namespace roster {

/**
 * A roster of students.
 * @author Ken Baclawski
 */
class Roster {
public:
  /**
   * Add a student to the roster.
   */
  void addStudent(/** The student to be added. */
                  const Student& student) noexcept;

  /**
   * Compute the average GPA of all students
   * specified by a predicate.
   * @return The average GPA of the students for
   * which the predicate is true, or NAN if there
   * are no such students.
   */
  double computeAverage(std::function<bool(const Student&)> func)// Missing Code and Documentation Part 1
    const noexcept;

private:
  /** The list of students. */
  std::vector<Student> studentList_;
};

}

#endif
