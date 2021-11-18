#include <iostream>
#include "user.h"
#include "emailmsg.h"
#include "mobilemsg.h"
#include "msgmanager.h"

void partB();

void partC();

int main() {
    std::cout << "Parte A\n" << std::endl;

    User u1("Maria", "m@ua.pt", "+351234370500");
    std::cout << u1 << std::endl;

    User u2;
    std::cout << "new user (name email mobile)? ";
    std::cin >> u2;
    std::cout << u2 << std::endl;

    User u3(u1);
    std::cout << u3 << std::endl;
    u3.name("Manuel"); u3.email("mm@ua.pt"); u3.mobile("+351234370522");
    std::cout << u3.name() << " ; " << u3.email() << " ; " << u3.mobile() << std::endl;

    if(u1 < u3) // comparison by email
       std::cout << "first is " << u1 << std::endl;
    else
       std::cout << "first is " << u3 << std::endl;

    std::cout <<"------------------------------------------------" <<  std::endl;

    EmailMsg e1("The PpO exam is today!", "m@ua.pt", "mm@ua.pt");
    std::cout << e1 << std::endl;

    EmailMsg e2;
    std::string dummy;
    std::getline(std::cin, dummy); // remove any lost \n
    std::cout << "new email (first the content in one line, then the from and to addresses)? ";
    std::cin >> e2;
    std::cout << e2 << std::endl;

    EmailMsg e3(e2);
    std::cout << "e3 id: " << e3.id() << std::endl;

    MobileMsg m1("The PpO exam is indeed today!", "+351234370500", "+351234370522");
    std::cout << m1 << std::endl;

    MobileMsg m2;
    std::getline(std::cin, dummy); // remove any lost \n
    std::cout << "new mobile (first the content in one line, then the from and to mobiles)? ";
    std::cin >> m2;
    std::cout << m2 << std::endl;

    MobileMsg m3(m2);
    std::cout << "m3 id: " << m3.id() << " and type " << m3.type() << std::endl;

    partB();

    partC();

    return 0;
}

void partB(){
    std::cout << "\n*** Part B ***\n" << std::endl;

    MsgManager m;

    m.addUser(User("Maria", "m@ua.pt", "+351234370500"));
    m.addUser(User("Ana", "a@ua.pt", "+351234370555"));
    m.addUser(User("Ze", "z@ua.pt", "+351234234234"));
    m.addUser(User("Bernardo", "b@ua.pt", "+351234370111"));

    m.addMsg(new EmailMsg("The PpO exam is today!", "m@ua.pt", "a@ua.pt"));
    m.addMsg(new EmailMsg("I am ready :-)", "a@ua.pt", "m@ua.pt"));
    m.addMsg(new MobileMsg("The PpO exam is indeed today!", "+351234370000", "+351234370111"));
    m.addMsg(new EmailMsg("The content is what I studied.", "a@ua.pt", "z@ua.pt"));
    m.addMsg(new MobileMsg("I love programming.", "+351234370555", "+351234370500"));

    std::cout << m << std::endl;

    std::cout << "Sent emails from a@ua.pt: " << std::endl;
    m.emailsFrom("a@ua.pt");

    m.saveTo("messages");
}

void partC(){
    std::cout << "\n*** Part C ***" << std::endl;

    MsgManager m;

	m.loadFrom("messages");

    std::cout << m << std::endl;
}
