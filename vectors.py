import math

class Vector:

    def __init__(self, i=None, j=None, k=None):
        self.i = i if i is not None else 0
        self.j = j if j is not None else 0
        self.k = k if k is not None else 0

    @classmethod
    def from_magnitude(cls, magnitude, angle_xy, angle_xz=None) :
        ''' this function takes magnitude and angle of xy plane and xz plane, then returns a vector with x, y, z coordinates'''
        x = round(magnitude * math.cos(math.radians(angle_xy)), 2)
        y = round(magnitude * math.sin(math.radians(angle_xy)), 2)

        if angle_xz is not None:
            z = round(magnitude * math.cos(math.radians(angle_xz)), 2)
            return cls(x, y, z)
        else:
            return cls(x, y, 0)

    @classmethod
    def angle_between(cls, vector1, vector2):
        product = vector1.dot_product(vector2)
        magnitude_product = vector1.magnitude() * vector2.magnitude()

        cos_angle = product / magnitude_product
        angle_radians = math.acos(cos_angle)
        angle_degrees = round(math.degrees(angle_radians), 2)

        return angle_degrees

    @classmethod
    def check_negative(cls,first,other):
        if(first.to_negative() == other):
            return 1
        else:
            return 0
        
    @classmethod
    def check_equal(cls,first,other):
        if(first == other):
            return 1
        else:
            return 0
        
    def display(self):
        print(f"{self.i}i, {self.j}j, {self.k}k")

    def magnitude(self):
        return math.sqrt(self.i ** 2 + self.j ** 2 + self.k ** 2)

    def dot_product(self, other):
        product = self.i * other.i + self.j * other.j + self.k * other.k

        return product

    def crossProduct(self, other):
        new_i = self.j * other.k - self.k * other.j
        new_j = self.k * other.i - self.i * other.k
        new_k = self.i * other.j - self.j * other.i

        return Vector(new_i, new_j, new_k)

    def to_negative(self):
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


if __name__ == "__main__":
    v1 = Vector().from_magnitude(5, 45,60)

    v2 = v1.to_negative()
    v1 = v1.to_negative()

    print(Vector.check_negative(v1,v2))
