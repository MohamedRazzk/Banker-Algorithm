""""
Project :Assignment 3
Created by : Mohamed Fathi
C-Date : 11/12/2020 , 12:03AM
Des: Discount system
"""


class Customer:
    def __init__(self, user, user_type):
        self.user = user
        self.type = user_type

    def print_user(self):
        print("User Name : \"{}\" User Membership Type \"{}\"".format(self.user, self.type))

    def call(self):
        return self.user, self.type

