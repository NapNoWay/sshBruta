#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;


int main(int argc,char* argv[]){

    ssh_session my_ssh_session;
    int rc;
    int port = 22;
    int verbosity = SSH_LOG_PROTOCOL;
    char *password;
    string Username = "";
    string IPADDR = "";
    string Wordlist = "";

    cout << "Enter Username : ";
    cin >> Username;

    cout << "Enter IP : ";
    cin >> Username;
    

    // How to check arguments for specific things

    for (int i = 0; i < argc; ++1) {
        if (argv[i] == "-i"){
           IPADDR = argv[i+1]

        }else if (argv[i] == "-u"){
            Username = argv[i+1]

        }else if (argv[i] == "-w"){
            Wordlist = argv[i+1]
        }


    }

    // Open sshsession and set the options

    my_ssh_session = ssh_new();
    if (my_ssh_session == NULL)
        exit(-1); // Why -1
    ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST,"TARGET IP");
    ssh_options_set(my_ssh_session, SSH_OPTIONS_USER, "USERNAME");
    ssh_options_set(my_ssh_session, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);

    rc = ssh_connect(my_ssh_session)
    if (rc != SSH_OK){
        fprintf(stderr, "Error: %s\n",ssh_get_error(my_ssh_session));
        ssh_free(my_ssh_session);
        exit(-1);

    }

    password = "FOR LINE IN PASSFILE";
    rc = ssh_userauth_password(my_ssh_session, NULL, password);
    if (rc != SSH_AUTH_SUCCESS){
        fprintf(stderr, "Not " + password, ssh_get_error(my_ssh_session));
        ssh_disconnect(my_ssh_session);
        ssh_free(my_ssh_session);
        exit(-1);

    }

    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);
}
