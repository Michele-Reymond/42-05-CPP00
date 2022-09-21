#ifndef CONTACT_H
# define CONTACT_H

class Contact {

public:

    char *firstname;
    char *lastname;
    char *nickname;
    char *phonenbr;
    char *secret;

    Contact(void);
    ~Contact(void);

    void get_infos(void);
    void search(void);

};

#endif