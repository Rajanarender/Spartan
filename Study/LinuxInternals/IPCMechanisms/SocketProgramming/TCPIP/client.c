#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h> //for struct sockaddr_in

/**********************************************************************************
gcc client.c -o client.out
CLI:./client.out hostipaddress portno
socket();

serv_addr.sin_family = AF_INET;
serv_addr.sin_addr.s_addr = INADDR_ANY; //IP address 
portno = atoi(argv[2]); //portno from char array to integer format ,V.V.Imp step
serv_addr.sin_port = htons(portno); //portno from integer to N/w format 

connect(); //same as bind(),socket struct should be filled using serv_addr object
read();
write();
***************************************************************************************/

int main(int argc,char* argv[])
{
	int sockfd,portno;
        char buff[256];
	struct sockaddr_in serv_addr,cli_addr;

	if(argc <3) //argv[0]=./a.out, argv[1]=hostaddress[say 192.168.20.105], argv[2]=portno[say 1234]
	{
         //fprintf(stderr,"ERROR since no portno provided in client Commandline\n");
          perror("ERROR since no portno provided in client Commandline\n");
          exit(1);
	}

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
             perror("ERROR in creating socket\n");
             exit(1);
	}

//Fill the sockaddr_in structure using serv_addr object before connecting client to serv_addr
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY; //IP address 
	portno = atoi(argv[2]); //portno from char array to integer format ,V.V.Imp step
	serv_addr.sin_port = htons(portno); //portno from integer to N/w format 

	if ( connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0 ) //same as bind() API in server.c
	{
        perror("ERROR in connecting to the server\n");
        exit(0);
	}


	printf("Please Enter the message\n");
	scanf("%d",&buff);
	int n;
	n=write(sockfd,buff,strlen(buff));
	if(n<0)
	{
        perror("ERROR in writing to socket\n");
        exit(0);
	}

	n=read(sockfd,buff,strlen(buff));
	if(n<0)
	{
        perror("ERROR in reading from socket\n");
        exit(0);
	}
}
