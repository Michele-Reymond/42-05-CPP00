#ifndef CONTACT_H
# define CONTACT_H

class Contact {

public:
    Contact(void);
    ~Contact(void);

    void        add_contact(void);
    int         is_not_ok(void);
    std::string getFirstname(void);
    std::string getLastname(void);
    std::string getNickname(void);
    std::string getPhonenbr(void);
    std::string getSecret(void);


private:
    std::string _ask(std::string question);
    std::string _firstname;
    std::string _lastname;
    std::string _nickname;
    std::string _phonenbr;
    std::string _secret;
};

#endif