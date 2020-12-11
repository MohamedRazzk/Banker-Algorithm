""""
Project :Assignment 3
Created by : Mohamed Fathi
C-Date : 11/12/2020 , 12:07PM
Des: Discount system
"""

from discount import Discount
from customer import Customer


class visit:
    def __init__(self, type, all_service_price, all_product_price):
        self.type = type
        self.all_service_price = all_service_price
        self.all_product_price = all_product_price

    def visit(self):
        ser_dis_amount = self.all_service_price * Discount(self.type, "service").discount()
        final_ser_price = self.all_service_price - ser_dis_amount
        pro_dis_amount = self.all_product_price * Discount(self.type, "product").discount()
        final_pro_price = self.all_product_price - pro_dis_amount
        total = final_ser_price + final_pro_price

        return ser_dis_amount, pro_dis_amount, total, final_ser_price, final_pro_price



#print(visit("platinum", 100, 200).visit())
