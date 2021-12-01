class Person:

    def __init__(self,n,a):
        self.name = n
        self._age = a

    @property ##data should only be changed in the decorator methods
    def age(self):
        return self_age

    @age.setter
    def age(self, arg):
        if (arg >= 1 and arg <= 120):
            self._age = arg

    def __repr__(self):
        return f"{self.name} is {self._age} years old"

class Student(Person):

    def __init__(self, n, a, courses):
        super(). __init__ (n,a)
        self.courses = courses

    def takes_class(self, list):
        for course in self.courses:
            if course in list:
                return True
        return False
    
    def __repr__ (self):
        return f"{super().__repr__()} is a student is {self.courses}"


if __name__ == '__main__':
    print("hello")
    clara = Person("Clara", 1)
    print (clara)
    clara.age = 10
    print (clara)

    paul = Student("Paul", 52, ["Intro to Management", "Programming 101"])
    print (paul)
    paul.age = 300
    print (paul)
    print (paul.takes_class(["HR Admin"]))
    print (paul.takes_class(["Intro to Management"]))