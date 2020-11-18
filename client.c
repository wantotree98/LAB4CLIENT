#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>  //inet_addr
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<netdb.h>

int main(int argc, char*argv[]){


int socket_desc,new_socket, k;
char server_reply[2000]={0};
struct sockaddr_in server, server2;
char*message;
char client_reply[2000]={0};

//create socket
socket_desc = socket(AF_INET, SOCK_STREAM, 0);
if(socket_desc == -1){
printf("Socket could not be created");

}

server.sin_addr.s_addr = inet_addr("192.168.43.219"); //server ip address
server.sin_family = AF_INET;
server.sin_port = htons(8888);

//connect to remote server
if(connect(socket_desc, (struct sockaddr*)&server, sizeof(server))<0){

puts("connect error");
return 1;
}

puts("Connected!\n");
//send some data

message = "Connect";
if(send(socket_desc, message, strlen(message), 0)<0){

puts("Send Failed");
return 1;
}
puts("Data send \n");
//receive a reply from the server

if(recv(socket_desc,server_reply,2000,0) < 0){
puts("Receicved Failed \n");

}

puts("Reply  received \n");
puts(server_reply);

k = sizeof(struct sockaddr_in);
//while(new_socket = accept(socket_desc, (struct sockaddr *)&server2, (socklen_t*)&k)){
while(1){
printf("Bosskiut tgh buat : ");
fgets(client_reply, 100, stdin);
send(socket_desc, client_reply, 2000, 0);
break;
}
if(send(socket_desc, client_reply, 2000, 0)<0){
puts("CLient send failed \n");
return 1;
}
else{
puts("Client send succesful");
}



close(socket_desc);

return 0;
}
