""""
Project :Assignment 3
Created by : Mohamed Fathi
C-Date : 11/12/2020 , 12:07PM
Des: Discount system
"""
from customer import Customer
from discount import Discount
from visit import visit


def bill(customer, membership, Service_Price, service_discount, lsprice, Product_Price, product_discount, lpprice,
         total_price):
    print("Customer Name: {} \nMembership: {}\n"
          "Service Price: {} \nService Discount: {}\n"
          "Final Service Price: {} \nProduct Price: {} \nProduct discount: {} \n"
          "Final Product Price: {}\nTotal: {} "
          .format(customer, membership, Service_Price, service_discount, lsprice, Product_Price, product_discount,
                  lpprice, total_price))


def print_user_disc_info(username, membership, dis_service, dis_product):  # print User all info
    return "Username: {} , Membership: {} , Service Discount {} , Product Discount: {}".format(username, membership,
                                                                                               dis_service, dis_product)


# Test of Customer Class
user1 = Customer("Eng Ahmed Mostafa", "platinum")
user2 = Customer("Mohamed Razzk", "gold")
user3 = Customer("Khaled", "silver")
user4 = Customer("Omer", "normal")

product = "product"
service = "service"

# ---------------------Test of Customer Class Functions------------------------
print("///////////////////// Customer Function Test ///////////////////\n")
user1.print_user()
print("{}{}".format(user1.call(), '\n'))
print("///////////////////////////////////////////////////////////////\n")
print(100 * "*" + '\n')
# -----------------------------------------------------------------------------


# ------------------------- Test Of Discount Class ----------------------------

print("/////////////////// Discount Functions Test ////////////////////\n")
print("User1 Service Discount: " + str(Discount(user1.call()[1], service).discount()))
print("User1 Product Discount: " + str(Discount(user1.call()[1], product).discount()))
print("\n///////////////////////////////////////////////////////////////\n")
print(100 * "*" + '\n')
# -----------------------------------------------------------------------------


# ------------------Print All Users Data Info with discount--------------------
users = [user1, user2, user3, user4]
print("//////////// All user Name, Type and Discount Info /////////////\n")

for i in range(4):
    print(print_user_disc_info(users[i].call()[0], users[i].call()[1], Discount(users[i].call()[1], service).discount(),
                               Discount(users[i].call()[1], product).discount()))

print("\n///////////////////////////////////////////////////////////////\n")
print(100 * "*" + '\n')
# -----------------------------------------------------------------------------


# ------------------------- Test Of Discrete visit Class -----------------------

print("//////////// Discrete visit Class Test /////////////\n")

Service_Price = 100
Product_Price = 200

service_discount, product_discount, total_price, lsprice, lpprice = visit("platinum", Service_Price,
                                                                          Product_Price).visit()  # type , all service price , all product price

bill("", "", Service_Price, service_discount, lsprice, Product_Price, product_discount, lpprice, total_price)

print("\n///////////////////////////////////////////////////////////////\n")
print(100 * "*" + '\n')
# -----------------------------------------------------------------------------



# ------------------------- User Case Reset -----------------------  change user by id amd prices number to check
id = 0
Service_Price = 1000
Product_Price = 500
print("//////////// User Reset  /////////////\n")
user_name = users[id].call()[0]
user_membership = users[id].call()[1]

service_discount, product_discount, total_price, lsprice, lpprice = visit(user_membership, Service_Price,
                                                                          Product_Price).visit()  # type , all service price , all product price

bill(user_name, user_membership, Service_Price, service_discount, lsprice, Product_Price, product_discount, lpprice,
     total_price)

print("\n///////////////////////////////////////////////////////////////\n")
print(100 * "*" + '\n')
# -----------------------------------------------------------------------------
