#ifndef ROSTER_STUDENT_H
#define ROSTER_STUDENT_H

#include <string>
#include <iostream>
#include <stdexcept>

namespace roster {

/**
 * A student record.  Each record consists of a
 * first name, last name, email address and gpa.
 *
 * @author Ken Baclawski
 */
class Student {
public:
  /**
   * Construct a student record from field values.
   */
  Student(/** The first name. */ const std::string& firstName,
          /** The last name. */ const std::string& lastName,
          /** The email address. */ const std::string& email,
          /** The grade point average. */ double gpa);

  /**
   * Construct a student record from an input
   * stream.  The fields are pipe-delimited.  For
   * example, if John Doe has email address
   * jdoe@example.com and GPA 3.75, the input line
   * must be "John|Doe|jdoe@example.com|3.75".
   */
  Student(/** The input stream. */ std::istream& input);

  /**
   * Get the first name.
   * @return The first name of the student.
   */
  std::string getFirstName() const noexcept;

  /**
   * Get the last name.
   * @return The last name of the student.
   */
  std::string getLastName() const noexcept;

  /**
   * Get the email address.
   * @return The email address of the student.
   */
  std::string getEmailAddress() const noexcept;

  /**
   * Get the GPA.
   * @return The GPA of the student.
   */
  double getGPA() const noexcept;

  /**
   * Print a student record to an output stream.
   * For the example in the constructor
   * "John|Doe|jdoe@example.com|3.75", the output
   * should be "John Doe <jdoe@example.com> has GPA 3.75".
   */
  void print(/** The output stream. */ std::ostream& out) const noexcept;

private:
  /** The first name of the student. */
  std::string firstName_;
  /** The last name of the student. */
  std::string lastName_;
  /** The email address of the student. */
  std::string emailAddress_;
  /** The GPA of the student. */
  double gpa_ = 0.0;
};

}

#endif
