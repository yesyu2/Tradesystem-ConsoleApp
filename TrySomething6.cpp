/*Yapmak istediğimiz şey Kayıt sistemi olan ve sonrasında bu kayıt yapılan bilgilerle daha sonra giriş yapılabilen 
bir sistem oluşturmak daha sonra giriş yapılan sistemin içinde bazı ürünler satın aldıracağız. Satın aldığı ürün için 
bir müşteri gelecek ve bir fiyat verecek eğer fiyatı beğenirsek satacağız beğenmezsek başka bir satıcı bekleyeceğiz. 
Ürünü satınca başka bir ürün almak için tekrar ürün alma sayfasına geçeceğiz ve daha sonra tekrar satış işlemi başlayacak.*/


/*Pseudocode (Output) version : 
YESYU ticaret sistemine hoşgeldiniz. Lütfen üye kaydı yaptırınız.
=====================================================================
Registration 
=====================================================================
Username : 
Password :
Başarıyla kayıt olundu!
=====================================================================
İşlem yapmak için lütfen giriş yapın.
=====================================================================
Username :
Password :
Başarıyla giriş yapıldı!
=====================================================================
Satın alabileceğiniz ürünler : 
=====================================================================
1- 
2-
3-
4-
5- 
=====================================================================
Mevcut Paranız : $500
=====================================================================
Satın almak istediğiniz ürünün kodunu girin : 
Satın almak istediğiniz ürünün adetini girin :

*/


#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

// String variables
string purchaseQuestion;
string userName;
string password;
string loginUserName;
string loginPassword;

// int variables
int amount;
int productCode;
int productCodeList;
int selectProduct; // En son eklediğim variables


// float variables
float purchaseBalance;
float balance = 500;

// products float variables
float halkBankPrice = 0.52;
float thyPrice = 1.20;
float aselsanPrice = 0.70;
float tusasPrice = 0.20;
float bcimentoPrice = 0.35;

// products string variables
string aselsan;
string halkBank;
string tusas;
string thy;
string bursaCimento;
string productCollector;

void RegistrationSystem();
void ProductSystem();
void LoginSystem();
void ProductList();
void Purchase();
void TradeSystem();
void Line();

int main()
{
    cout << "Welcome to the YESYU trading system. Please register as a member." << endl;
    Line();
    RegistrationSystem();
    LoginSystem();
}

void RegistrationSystem()
{
    cout << "Registration :" << endl;
    Line();
    cout << "Username : "; cin >> userName;
    cout << "Password : "; cin >> password;
    loginUserName = userName;
    loginPassword = password;
    cout << "Registration succesfull!\n";
    Line();
}

void LoginSystem()
{
    cout << "Please log in to trade.\n";
    Line();
    cout << "Username : "; cin >> userName;
    cout << "Password : "; cin >> password;
    while (true)
    {
        if (loginUserName == userName && loginPassword == password)
        {
            ProductSystem();
            break;
        }
        else
        {
            cout << "Please input correct information !\n";
            Line();
            LoginSystem();
            break;

        }
    }

}

void ProductSystem()
{
    Line();
    cout << "Products you can buy : \n";
    ProductList();
    cout << "Enter the code: "; cin >> productCode; cout << "Enter the amount :"; cin >> amount;
    productCodeList = productCode;
    Line();
    switch (productCodeList)
    {
        case 12300:
            cout << "The product you bought : Halkbank | Amount : " << amount << endl;
            purchaseBalance = balance - halkBankPrice * amount;
            halkBank = "Halkbank";
            productCollector = halkBank;
            Line();
            Purchase();
            break;
        case 32400:
            cout << "The product you bought : Turkish Airlines | Amount : " << amount << endl;
            purchaseBalance = balance - thyPrice * amount;
            thy = "Turkish Airlines";
            productCollector = thy;
            Line();
            Purchase();
            break;
        case 42510:
            cout << "The product you bought : Aselsan | Amount : " << amount << endl;
            purchaseBalance = balance - aselsanPrice * amount;
            aselsan = "Aselsan";
            productCollector = aselsan;
            Line();
            Purchase();
            break;
        case 24125:
            cout << "The product you bought : TUSAS | Amount : " << amount << endl;
            purchaseBalance = balance - tusasPrice * amount;
            tusas = "TUSAS";
            productCollector = tusas;
            Line();
            Purchase();
            break;
        case 61235:
            cout << "The product you bought : Bursa Cimento | Amount : " << amount << endl;
            purchaseBalance = balance - bcimentoPrice * amount;
            bursaCimento = "Bursa Cimento";
            productCollector = bursaCimento;
            Line();
            Purchase();
            break;
    }
    
    

}

void Line()
{
    cout << "==================================================================\n";
}

void ProductList()
{
    
    cout << "Product Name        | Price | Product Code     Balance : $" << balance << endl;
    Line();
    cout << "1- Halkbank         : $0.52 : 12300\n";
    cout << "2- Turkish Airlines : $1.20 : 32400\n";
    cout << "3- Aselsan          : $0.70 : 42510\n";
    cout << "4- TUSAS            : $0.20 : 24125\n";
    cout << "5- Bursa Cimento    : $0.35 : 61235\n";
    Line();
}

void Purchase()
{

    cout << "Do you confirm the purchase? (YES/NO) : "; cin >> purchaseQuestion;
    
    if (purchaseQuestion == "YES" || purchaseQuestion == "yes")
    {
        balance = purchaseBalance;
        TradeSystem();
    }
    if (purchaseQuestion == "NO" || purchaseQuestion == "no")
    {
        Line();
        cout << "Directed to the page...\n";
        sleep_until(system_clock::now() + seconds(2)); // Yönlendirme yaparken 2 saniye bekletiyoruz.
        ProductSystem();
    }
}   

void TradeSystem()
{
    cout << "New Balance : $" << balance << endl;
    Line();
    if (productCodeList == productCode)
    {
        cout << "Product : " << productCollector << " | " " Amount : " << amount << endl;
    }

    /* Burada alınan ürün ve kaç adet alındığı gözükmeli ayrıca sistem 1sn bekledikten sonra bize burada yeni
    teklifler vermeli bu teklifler üzerinden işlem yapmalıyız. Eğer verilen teklif hoşumuza gitmezse yeni teklif
    ver demeliyiz bunu deyince sistem bize yeni teklif vermeli. Eğer teklifi beğenirsek teklifi kabul edebilmeliyiz
    ve kabul edersek bizi yeni bakiyemizle beraber tekrar satın alma ekranına göndermeli. Satın alma ekranına 
    tekrar döndüğümüzde ürünlerin yeni fiyatı olmalı her biri $0.20 artmalı.*/
 }