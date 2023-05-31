#include <iostream>
#include <string>

struct Customer
{
    int customerID;              // mã khách hàng
    std::string fullName;        // họ tên khách hàng
    std::string nickname;        // biệt danh (nếu có)
    std::string address;         // địa chỉ
    std::string dateOfBirth;     // ngày sinh (dd/mm/yyyy)
    int serviceCode;             // mã dịch vụ
    int usageCount;              // số lần sử dụng dịch vụ
    float cost;                  // chi phí
    std::string time;            // thời gian sử dụng dịch vụ (hh:mm dd/mm/yyyy)
    std::string taxCode;         // mã số thuế (nếu là doanh nghiệp)
    std::string businessName;    // tên doanh nghiệp (nếu là doanh nghiệp)
    std::string businessAddress; // địa chỉ doanh nghiệp (nếu là doanh nghiệp)
    std::string phone;           // số điện thoại doanh nghiệp (nếu là doanh nghiệp)
    std::string fax;             // số fax doanh nghiệp (nếu là doanh nghiệp)
    std::string email;           // email doanh nghiệp (nếu là doanh nghiệp)
    std::string website;         // địa chỉ website doanh nghiệp (nếu là doanh nghiệp)
    std::string cardType;        // loại thẻ khách hàng (thẻ vàng, thẻ bạc, thẻ thông thường)
};

struct CRM
{
    int numCustomers = 0;     // số khách hàng hiện có trong danh sách
    Customer customers[1000]; // danh sách khách hàng
};
void addCustomer(CRM &crm, Customer newCustomer)
{
    bool found = false;
    int i = 0;
    while (i < crm.numCustomers && !found)
    {
        if (crm.customers[i].customerID == newCustomer.customerID)
        {
            found = true;
        }
        i++;
    }
    if (!found)
    {
        crm.customers[crm.numCustomers] = newCustomer;
        crm.numCustomers++;
    }
}
Customer *findCustomer(CRM crm, std::string name)
{
    int i = 0;
    while (i < crm.numCustomers)
    {
        if (crm.customers[i].fullName == name)
        {
            return &crm.customers[i];
        }
        i++;
    }
    return nullptr;
}

// Hàm truy xuất thông tin của khách hàng
void printCustomerInfo(Customer customers[], int numCustomers)
{
    for (int i = 1; i <= numCustomers; i++)
    {
        if (customers[i].taxCode.empty())
        {
            std::cout << "Loai khach hang: Ca nhan" << std::endl;
        }
        else
        {
            std::cout << "Loai khach hang: Doanh nghiep" << std::endl;
            std::cout << "Ma so thue: " << customers[i].taxCode << std::endl;
            std::cout << "Ten doanh nghiep: " << customers[i].businessName << std::endl;
            std::cout << "Dia chi doanh nghiep: " << customers[i].businessAddress << std::endl;
            std::cout << "Dien thoai doanh nghiep: " << customers[i].phone << std::endl;
            std::cout << "Fax doanh nghiep: " << customers[i].fax << std::endl;
            std::cout << "Email doanh nghiep: " << customers[i].email << std::endl;
            std::cout << "Website doanh nghiep: " << customers[i].website << std::endl;
            std::cout << "Loai the: " << customers[i].cardType << std::endl;
        }
        std::cout << "Ma khach hang: " << customers[i].customerID << std::endl;
        std::cout << "Ho va ten: " << customers[i].fullName << std::endl;
        if (!customers[i].nickname.empty())
        {
            std::cout << "Biet danh: " << customers[i].nickname << std::endl;
        }
        std::cout << "Dia chi: " << customers[i].address << std::endl;
        std::cout << "Ngay sinh: " << customers[i].dateOfBirth << std::endl;

        std::cout << "Ma dich vu: " << customers[i].serviceCode << std::endl;
        std::cout << "So lan su dung dich vu: " << customers[i].usageCount << std::endl;
        std::cout << "Tong chi phi: " << customers[i].cost << std::endl;
        std::cout << "Thoi gian su dung dich vu: " << customers[i].time << std::endl;
        std::cout << std::endl;
    }
}

// Thay đổi nâng cấp loại thẻ cho khách hàng.
void changeCardType(Customer &customer, std::string cardType)
{
    customer.cardType = cardType;
}
// Kiểm tra loại khách hàng là cá nhân
bool isIndividual(Customer customer)
{
    return customer.taxCode.empty();
}
// Kiểm tra loại khách hàng là doanh nghiệp
bool isBusiness(Customer customer)
{
    return !customer.taxCode.empty();
}
Customer customer;
int main()
{
    // Khởi tạo struct CRM
    CRM crm;
    std::cout << "Nhap so luong khach hang them vao: ";
    std::cin >> crm.numCustomers;
    // Nhập thông tin 5 khách hàng cá nhân
    for (int i = 1; i <= crm.numCustomers; i++)
    {
        std::cout << "Nhap thong tin khach hang thu " << i << '\n';
        std::cout << "Ma khach hang: ";
        std::cin >> crm.customers[i].customerID;
        std::cin.ignore();
        std::cout << "Ho va ten: ";
        getline(std::cin, crm.customers[i].fullName);
        std::cout << "Biet danh: ";
        getline(std::cin, crm.customers[i].nickname);
        std::cout << "Dia chi: ";
        getline(std::cin, crm.customers[i].address);
        std::cout << "Ngay sinh: ";
        getline(std::cin, crm.customers[i].dateOfBirth);
        std::cout << "Ma dich vu: ";
        std::cin >> crm.customers[i].serviceCode;
        std::cin.ignore();
        std::cout << "So lan su dung dich vu: ";
        std::cin >> crm.customers[i].usageCount;
        std::cout << "Tong chi phi: ";
        std::cin >> crm.customers[i].cost;
        std::cin.ignore();
        std::cout << "Thoi gian su dung dich vu: ";
        std::cin >> crm.customers[i].time;
        std::cin.ignore();
        std::cout << '\n';
    }

    // Nhập thông tin 5 khách hàng doanh nghiệp
    for (int i = 1; i <= crm.numCustomers; i++)
    {
        std::cout << "Nhap thong tin khach hang doanh nghiep thu " << i + 1 << '\n';
        // Thông tin cá nhân khác hàng doanh nghiệp
        std::cout << "Ma khach hang: ";
        std::cin >> crm.customers[i].customerID;
        std::cin.ignore();
        std::cout << "Ho va ten: ";
        getline(std::cin, crm.customers[i].fullName);
        std::cout << "Biet danh: ";
        getline(std::cin, crm.customers[i].nickname);
        std::cout << "Dia chi: ";
        getline(std::cin, crm.customers[i].address);
        std::cout << "Ngay sinh: ";
        getline(std::cin, crm.customers[i].dateOfBirth);
        // Thông tin doanh nghiệp
        std::cout << "Ten doanh nghiep: ";
        getline(std::cin, crm.customers[i].businessName);
        std::cout << "Dia chi doanh nghiep: ";
        getline(std::cin, crm.customers[i].businessAddress);
        std::cout << "Ma so thue: ";
        getline(std::cin, crm.customers[i].taxCode);
        std::cout << "Dien thoai doanh nghiep: ";
        getline(std::cin, crm.customers[i].phone);
        std::cout << "Fax: ";
        getline(std::cin, crm.customers[i].fax);
        std::cout << "Dia chi email doanh nghiep: ";
        getline(std::cin, crm.customers[i].email);
        std::cout << "Dia chi website doanh nghiep: ";
        getline(std::cin, crm.customers[i].website);
        std::cout << "Loai the khac hang doanh nghiep: ";
        getline(std::cin, crm.customers[i].cardType);
    }

    // In thông tin khách hàng sau khi đã nhập.
    printCustomerInfo(crm.customers, crm.numCustomers);

    return 0;
}
