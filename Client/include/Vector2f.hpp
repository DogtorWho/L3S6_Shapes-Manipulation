/**
 * @file Vector2f.hpp
 * File containing a representation of a vector with two real components
 */
#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "Error.hpp"

class Vector2f {
  private :
    // === Variables ===
    /** @var _x
     * @brief double stocking the x position of the vector
     */
    double _x;

    /** @var _y
     * @brief double stocking the y position of the vector
     */
    double _y;

  public :
    // === Constructor & Destructor ===
    /**
     * @fn Vector2f()
     * @brief Constructor of the Vector2f class
     * @param x position of x (default=0)
     * @param y position of y (default=0)
     */
    Vector2f(double x = 0, double y = 0) : _x(x), _y(y) {}

    /**
     * @fn Vector2f(const Vector2f& v)
     * @brief Copy Constructor of the Vector2f class
     * @param p the vector2f to copy
     */
    Vector2f(const Vector2f &v) : _x(v._x), _y(v._y) {}

    /**
     * @fn virtual ~Vector2f()
     * @brief Destructor of the Vector2f class
     */
    virtual ~Vector2f(){}

    // === Getters & Setters ===
    /**
     * @fn double getPosX() const
     * @brief getter for the x position of the vector
     * @return double
     */
    double getPosX() const { return _x; }

    /**
     * @fn double getPosY() const
     * @brief getter for the y position of the vector
     * @return double
     */
    double getPosY() const { return _y; }

    /**
     * @fn Vector2f getVector2f() const
     * @brief getter for the vector
     * @return Vector2f
     */
    Vector2f getVector2f() const { return Vector2f(_x, _y); }

    /**
     * @fn void setPosX(double x)
     * @brief setter for the x position of the vector
     * @param x the new x position
     */
    void setPosX(double x) { _x = x; }

    /**
     * @fn void setPosX(double y)
     * @brief setter for the y position of the vector
     * @param y the new y position
     */
    void setPosY(double y) { _y = y; }

    /**
     * @fn void setVector2f(const Vector2f &v)
     * @brief setter for the vector
     * @param v the new vector
     */
    void setVector2f(const Vector2f &v) { _x = v._x, _y = v._y; }

    // === Functions ===
    /**
     * @fn const Vector2f& operator=(const Vector2f &v)
     * @brief overload of the = operator of Vector2f
     * @param v the new vector
     * @return const Vector2f&
     */
    const Vector2f& operator=(const Vector2f &v) { _x = v._x; _y = v._y; return *this; }

    /**
     * @fn const Vector2f& operator+(const Vector2f &v)
     * @brief overload of the + operator of Vector2f
     * @param v the vector to add
     * @return Vector2f
     */
    Vector2f operator+(const Vector2f &v) const { return Vector2f(_x + v._x, _y + v._y); }

    /**
     * @fn const Vector2f& operator-(const Vector2f &v)
     * @brief overload of the - operator of Vector2f
     * @param v the vector to substract
     * @return Vector2f
     */
    Vector2f operator-(const Vector2f &v) const { return Vector2f(_x - v._x, _y - v._y); }

    /**
     * @fn Vector2f operator-() const
     * @brief overload of the - operator of Vector2f to negate the vector
     * @return Vector2f
     */
    Vector2f operator-() const { return Vector2f(-_x, -_y); }

    /**
     * @fn const Vector2f& operator*(const Vector2f &v)
     * @brief overload of the * operator of Vector2f
     * @param m the double to multiply with the vector
     * @return Vector2f
     */
    Vector2f operator*(double m) const { return Vector2f(_x * m, _y * m); }

    /**
     * @fn bool operator==(const Vector2f &v) const
     * @brief overload of the == operator of Vector2f
     * @param v the vector to compare
     * @return bool
     * @retval false if v is not equal to this vector
     * @retval true if v is equal to this vector
     */
    bool operator==(const Vector2f &v) const { return (_x == v._x && _y == v._y); }

    /**
     * @fn bool operator!=(const Vector2f &v) const
     * @brief overload of the != operator of Vector2f
     * @param v the vector to compare
     * @return bool
     * @retval false if v is equal to this vector
     * @retval true if v is not equal to this vector
     */
    bool operator!=(const Vector2f &v) const { return (_x != v._x || _y != v._y); }

    /**
     * @fn const Vector2f& operator+=(const Vector2f &v)
     * @brief overload of the += operator of Vector2f
     * @param v the vector to add to this vector
     * @return const Vector2f&
     */
    const Vector2f& operator+=(const Vector2f &v) { return (*this = *this + v); }

    /**
     * @fn const Vector2f& operator-=(const Vector2f &v)
     * @brief overload of the -= operator of Vector2f
     * @param v the vector to substract to this vector
     * @return const Vector2f&
     */
    const Vector2f& operator-=(const Vector2f &v) { return (*this = *this + (-v)); }

    /**
     * @fn const Vector2f& operator*=(const Vector2f &v)
     * @brief overload of the *= operator of Vector2f
     * @param v the double to mutilply to this vector
     * @return const Vector2f&
     */
    const Vector2f& operator*=(double m) { return (*this = *this * m); }

    /**
     * @fn const Vector2f& operator^(const Vector2f &v)
     * @brief overload of the ^ operator of Vector2f, used to calculate the determinant
     * @param v the vector to calculate the determinant with this vector
     * @return double
     */
    double operator^(const Vector2f &v) const { return ( (_x * v.getPosY()) - (v.getPosX()) * _y ); }

    /**
     * @fn Vector2f* clone()
     * @brief clone the vector
     * @return Vector2f*
     */
    Vector2f* clone() const { return new Vector2f(*this); }

    /**
     * @fn operator std::string()
     * @brief overload of the string cast operator
     * @return std::string
     */
    operator std::string() const {
      std::ostringstream os;
      os << "Vector2f : " << "(" << _x << ", " << _y << ")";
      return os.str();
    }

    /**
     * @fn std::string export_to_string()
     * @brief export the vector into a string
     * @return std::string
     */
    std::string export_to_string() const {
      std::ostringstream os;
      os << _x << ";" << _y << ";";
      return os.str();
    }

    /**
     * @fn friend std::ostream& operator<< (std::ostream &s, Vector2f &v)
     * @brief overload of the << operator to print the class info
     * @param s the stream to write to
     * @param v the class to write into the stream
     * @return std::ostream&
     */
    friend std::ostream& operator<< (std::ostream &s, const Vector2f &v);
};

inline std::ostream& operator<< (std::ostream &s, const Vector2f &v){
  return (s << (std::string)v);
}

#endif
