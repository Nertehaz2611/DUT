#pragma once
#include"User.h"
#include"CustomerList.h"
#include"StaffList.h"
#include"Menu.h"
#include"Orders.h"
#include"BillList.h"

class Manager : public User {
    public:
        Manager();
        virtual ~Manager();
        void AddStaff(StaffList&, Staff);
        void RemoveStaff(StaffList&, Staff);
        void StaffInfo(StaffList);
        void CustomerInfo(CustomerList);
        void AddFood(Menu&, Food);
        void RemoveFood(Menu&, Food);
        void UpdateMenu(Menu&);
        void ViewMenu(Menu);
        void ViewOrders(Orders);
        void RevenueStatistics(BillList);
};