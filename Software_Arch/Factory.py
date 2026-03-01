from abc import ABC, abstractmethod

class Notification(ABC):
    @abstractmethod
    def notify(self, message:str) -> None:
        pass
    
class EmailNotification(Notification):
    def notify(self, message:str) -> None:
        print(f"Sending Email Notification: {message}")

class SMSNotification(Notification):
    def notify(self, message:str) -> None:
        print(f"Sending SMS Notification: {message}")

class PushNotification(Notification):
    def notify(self, message:str) -> None:
        print(f"Sending Push Notification: {message}")

class NotificationFactory:
    @staticmethod
    def get_notification(notification_type:str) -> Notification:
        if notification_type.lower() == "email":
            return EmailNotification()
        elif notification_type.lower() == "sms":
            return SMSNotification()
        elif notification_type.lower() == "push":
            return PushNotification()
        else:
            raise ValueError(f"Unknown notification type: {notification_type}")
        
if __name__ == "__main__":
    try:
        notification = NotificationFactory.get_notification("email")
        notification.notify("Welcome to the Factory Pattern!")

        notification = NotificationFactory.get_notification("sms")
        notification.notify("Your order has been shipped!")

        notification = NotificationFactory.get_notification("push")
        notification.notify("You have a new message!")

        notification = NotificationFactory.get_notification("fax")

    except ValueError as e:
        print(e)