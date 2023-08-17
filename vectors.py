
class Vector:

    def __init__(self, i, j, k):
        self.i = i
        self.j = j
        self.k = k

    def display(self):
        print(f"{self.i}i, {self.j}j, {self.k}k")
    

if __name__ == "__main__":
    v1 = Vector(1,2,3)
    v1.display()
