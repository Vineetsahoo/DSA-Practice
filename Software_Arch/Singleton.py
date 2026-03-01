class ConfigurationMnager:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(ConfigurationMnager,cls).__new__(cls)

            cls._instance.settings = {}

        return cls._instance
    
    def set_config(self, key, value):
        self.settings[key] = value

    def get_config(self, key):
        return self.settings.get(key, "Not Found")
    
if __name__ == "__main__":
    print("Creating first instance of ConfigurationManager")
    config1 = ConfigurationMnager()

    key = input("Enter config key: ")
    value = input("Enter config value: ")

    config1.set_config(key, value)

    print("\nCreating second instance of ConfigurationManager")
    config2 = ConfigurationMnager()
    
    print("key: ", key)
    print("Value from config2: ", config2.get_config(key))

    print("\nChecking if both instances are the same: ", config1 is config2)