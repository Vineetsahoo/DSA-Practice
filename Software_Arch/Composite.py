from abc import ABC, abstractmethod

class UnoversityComponent(ABC):
    def __init__(self,name):
        self.name = name

    @abstractmethod
    def show_details(self, indent = 0):
        pass

class Professor(UnoversityComponent):
    def __init__(self, name,Subject):
        super().__init__(name)
        self.Subject = Subject

    def show_details(self, indent = 0):
        print(" " * indent + f"Professor: {self.name} | Subject: {self.Subject}")

class Student(UnoversityComponent):
    def __init__(self, name,Year):
        super().__init__(name)
        self.Year = Year

    def show_details(self, indent = 0):
        print(" " * indent + f"Student: {self.name} | Year: {self.Year}")

class Department(UnoversityComponent):
    def __init__(self, name):
        super().__init__(name)
        self.members = []

    def add_member(self, component):
        self.members.append(component)

    def show_details(self, indent = 0):
        print("\n"+" " * indent + f"Department: {self.name}")

        for member in self.members:
            member.show_details(indent + 4)

if __name__ == "__main__":
    dept_name = input("Enter Department Name: ")
    department = Department(dept_name)

    while True:
        print("\n Choose member type to add: ")
        print("1. Professor")
        print("2. Student")
        print("3. Show Department Details")
        print("4. Exit")

        choice = input("Enter your choice (1-4): ")

        if choice == "1":
            name = input("Enter Professor Name: ")
            subject = input("Enter Subject: ")

            professor = Professor(name, subject)

            department.add_member(professor)

            print(" Professor added successfully!")

        elif choice == "2":
            name  = input("Enter Student Name: ")
            year = input("Enter Year: ")

            student = Student(name, year)

            department.add_member(student)

            print(" Student added successfully!")

        elif choice == "3":
            department.show_details()

        elif choice == "4":
            print(" Exiting the program. Goodbye!")
            break

        else:
            print(" Invalid choice. Please try again.")