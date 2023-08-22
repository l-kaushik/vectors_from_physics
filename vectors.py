"""
Vector Module

This module defines a Vector class for performing vector operations.
It provides methods for creating vectors from magnitude and angles, calculating magnitudes,
performing dot and cross products, checking for vector equality and negativity, and more.

Classes:
    Vector: A class representing a vector and providing various vector operations.

Author: Lokesh Kaushik
Date: August 22, 2023
"""

import math


class Vector:

    def __init__(self, i=None, j=None, k=None):
        self.i = i if i is not None else 0
        self.j = j if j is not None else 0
        self.k = k if k is not None else 0

    @classmethod
    def from_magnitude(cls, magnitude, angle_xy, angle_xz=None) :
        ''' takes magnitude and angle of xy plane and xz plane, then returns a vector with x, y, z coordinates'''
        x = round(magnitude * math.cos(math.radians(angle_xy)), 2)
        y = round(magnitude * math.sin(math.radians(angle_xy)), 2)

        if angle_xz is not None:
            z = round(magnitude * math.cos(math.radians(angle_xz)), 2)
            return cls(x, y, z)
        else:
            return cls(x, y, 0)

    @classmethod
    def angle_between(cls, vector1, vector2):
        '''take 2 vectors then calculate the angle between them and returns the angle which is of float type'''
        product = vector1.dot_product(vector2)
        magnitude_product = vector1.magnitude() * vector2.magnitude()

        cos_angle = product / magnitude_product
        angle_radians = math.acos(cos_angle)
        angle_degrees = round(math.degrees(angle_radians), 2)

        return angle_degrees


    @classmethod
    def is_negative(cls,first,other):
        ''' returns 1 if one vector is negate of other'''
        if(first.to_negative() == other):
            return 1
        else:
            return 0
        

    @classmethod
    def is_equal(cls,first,other):
        ''' return 1 if both vectors have same magnitude and direction'''
        if(first == other):
            return 1
        else:
            return 0
        

    def display(self):
        ''' returns nothing but display x, y, z of a vector'''
        print(f"{self.i}i, {self.j}j, {self.k}k")

    def magnitude(self):
        ''' calculate the magnitude of a vector and returns a float value'''
        return math.sqrt(self.i ** 2 + self.j ** 2 + self.k ** 2)

    def dot_product(self, other):
        '''performs dot product on two vectors and returns a value of type int or float depends upon given x, y, z'''
        product = self.i * other.i + self.j * other.j + self.k * other.k

        return product

    def crossProduct(self, other):
        ''' performs cross product on two vectors and returns a new vector'''
        new_i = self.j * other.k - self.k * other.j
        new_j = self.k * other.i - self.i * other.k
        new_k = self.i * other.j - self.j * other.i

        return Vector(new_i, new_j, new_k)

    def to_negative(self):
        ''' return negate of a vector'''
        x = self.i * -1
        y = self.j * -1
        z = self.k * -1

        return Vector(x, y, z)
    

    def __add__(self, other):
        new_i = self.i + other.i
        new_j = self.j + other.j
        new_k = self.k + other.k

        return Vector(new_i, new_j, new_k)

    def __sub__(self, other):
        new_i = self.i - other.i
        new_j = self.j - other.j
        new_k = self.k - other.k

        return Vector(new_i, new_j, new_k)

    def __mul__(self, other):
        if isinstance(other, (int, float)):
            new_i = self.i * other
            new_j = self.j * other
            new_k = self.k * other

            return Vector(new_i, new_j, new_k)
        
    def __eq__(self, other):
        return self.i == other.i and self.j == other.j and self.k == other.k
    
    def __str__(self):
        return f"{self.i}i, {self.j}j, {self.k}k"


if __name__ == "__main__":
   v1 = Vector(3,5,6)
   v2 = Vector(2,8,4)
   print(v1+v2)
