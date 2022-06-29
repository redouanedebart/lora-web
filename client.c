#include <netinet/in.h> //structure for storing address information
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket APIs
#include <sys/types.h>

int main(int argc, char const* argv[])
{
    int sockD = socket(AF_INET, SOCK_STREAM, 0);
  
    struct sockaddr_in servAddr;
  
    servAddr.sin_family = AF_INET; //https://www.ibm.com/docs/en/i/7.4?topic=family-af-inet-address
    servAddr.sin_port = htons(9001); // use some unused port number
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");//everything will be tested locally
  
    int connectStatus = connect(sockD, (struct sockaddr*)&servAddr,
                  sizeof(servAddr));

    if (connectStatus == -1) {
        printf("Erreur lors de la connexion...\n");
    }else {
        char strData[255]; //string contenant les donnees
  
        recv(sockD, strData, sizeof(strData), 0); //on recoit les donnees et on les stock dans la string
  
        printf("Message: %s\n", strData); //on affiche les donnees
    }
  
    return 0;
}