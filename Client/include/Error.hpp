/**
 * @file Error.hpp
 * File containing methods for handling errors log
 */
#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>
#include <string>

class Error {
  public:
    /** @var log_message
     * @brief string stocking the error message
     */
    std::string log_message;

    /**
     * @fn Error(std::string msg = "Error...")
     * @brief Constructor of the Error class
     * @param msg message to log (default="Error...")
     */
    Error(std::string msg = "Error...") : log_message(msg) {}

    /**
     * @fn operator std::string()
     * @brief overload of the string cast operator
     * @return std::string
     */
    operator std::string() const { return log_message; }

    /**
     * @fn friend std::ostream& operator<< (std::ostream &s, const Error &r)
     * @brief overload of the << operator to print the class info
     * @param s the stream to write to
     * @param r the class to write into the stream
     * @return std::ostream&
     */
    friend std::ostream& operator<< (std::ostream &s, const Error &r);
};

inline std::ostream& operator<< (std::ostream &s, const Error &r){
  return (s << (std::string)r);
}

#endif
