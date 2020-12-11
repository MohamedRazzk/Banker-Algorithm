""""
Project :Assignment 3
Created by : Mohamed Fathi
C-Date : 11/12/2020 , 12:09PM
Des: Discount system
"""


class Discount:

    def __init__(self, user_type, discount_type):
        self.user_type = user_type
        self.discount_type = discount_type

    def discount(self):
        discount_pres = 0
        if self.discount_type == "product":
            discount_pres = 0.1
            return discount_pres
        elif self.discount_type == "service":
            if self.user_type == "platinum":
                discount_pres = 0.25
                return discount_pres
            elif self.user_type == "gold":
                discount_pres = 0.2
                return discount_pres
            elif self.user_type == "silver":
                discount_pres = 0.15
                return discount_pres
            elif self.user_type == "normal":
                discount_pres = 0
                return discount_pres
            else:
                print("please enter correct membership type ")

        else:
            print("please enter correct discount type")

        return discount_pres
