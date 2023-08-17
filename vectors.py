
class Vector:

    def __init__(self, i=None, j=None, k=None):
        self.i = i if i is not None else 0
        self.j = j if j is not None else 0
        self.k = k if k is not None else 0

    def display(self):
        print(f"{self.i}i, {self.j}j, {self.k}k")

    def dotProduct(self, other):
        dot_product = self.i * other.i + self.j * other.j + self.k * other.k

        return dot_product

    def crossProduct(self, other):
        new_i = self.j * other.k - self.k * other.j
        new_j = self.k * other.i - self.i * other.k
        new_k = self.i * other.j - self.j * other.i

        return Vector(new_i, new_j, new_k)

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

        # elif isinstance(other, Vector):
        #     dot_product = self.i * other.i + self.j * other.j + self.k * other.k

        #     return dot_product


if __name__ == "__main__":
    v1 = Vector(1, 2, 3)
    v2 = Vector(3, 2, 1)
    # v1 = v1 * 2
    # v1.display()
    v1 = v1.crossProduct(v2)

    v1.display()
