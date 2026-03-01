from abc import ABC, abstractmethod

class Button(ABC):
    @abstractmethod
    def paint(self):
        pass

class Checkbox(ABC):
    @abstractmethod
    def paint(self):
        pass

class WindowButton(Button):
    def paint(self):
        print(" Windows button has been crafted !! ")

class WindowCheckbox(Checkbox):
    def paint(self):
        print(" Windows checkbox has been crafted !! ")

class MacOSButton(Button):
    def paint(self):
        print(" MacOS button has been crafted !! ")

class MacOSCheckbox(Checkbox):
    def paint(self):
        print(" MacOS checkbox has been crafted !! ")

class GUIFactory(ABC):
    @abstractmethod
    def create_button(self):
        pass
    
    @abstractmethod
    def create_checkbox(self):
        pass

class WindowsFactory(GUIFactory):
    def create_button(self):
        return WindowButton()
    
    def create_checkbox(self):
        return WindowCheckbox()
    
class MacOSFactory(GUIFactory):
    def create_button(self):
        return MacOSButton()
    
    def create_checkbox(self):
        return MacOSCheckbox()
    
if __name__ == "__main__":
    print("Choosing OS Type: ")
    print("1. Windows")
    print("2. MacOS")

    choice = input("Enter your choice (1 or 2): ")

    if choice == "1":
        factory = WindowsFactory()

    elif choice == "2":
        factory = MacOSFactory()

    else:
        print("Invalid Choice ..")
        exit()

    button= factory.create_button()
    checkbox = factory.create_checkbox()
    button.paint()
    checkbox.paint()