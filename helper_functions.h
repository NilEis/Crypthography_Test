#ifndef HELPER_FUNCTIONS_H_INCLUDED
#define HELPER_FUNCTIONS_H_INCLUDED

/** \brief Tests whether a number is a prime number
 *
 * \param p is the number to be tested
 * \return A 0 if the number is a prime number, otherwise a -1
 *
 */

int is_prime(int p);

/** \brief Exits the program after waiting for the user's confirmation
 *
 * \param code is the error code with which the programme is terminated
 *
 */

void exit_program(int code);

#endif // HELPER_FUNCTIONS_H_INCLUDED
