#ifndef __PUBLIC_H__
#define __PUBLIC_H__
#define	SERVER_PORT	8000
#define SERVER_IP		"39.106.146.7"

#define MSG_GAME_START		10
#define MSG_GAME_OVER			11
#define MSG_GAME_NEXT			12
#define MSG_REQUEST_UNDO	20
#define MSG_ALLOW_UNDO		21
#define MSG_REFUSE_UNDO		22
#define MSG_CHAT					100


#include<stdio.h>  
#include<stdlib.h>  
#include<errno.h>  
#include<string.h>  
#include<sys/types.h>  
#include<netinet/in.h>  
#include<sys/socket.h>  
#include<sys/wait.h>  

struct Position{
		unsigned int x:16;
		unsigned int y:16;
		int init(){
			x=0;y=0;
		};
		int setVal(int a,int b){
			if(a>=0&&a<15&&b>=0&&b<15){
				x=a;
				y=b;
				return 0;
			}else return -1;
		} ;
	};
	
struct MSG_Optional{
	/*
		comm Provide 256 States
		0:
		
		10:		Game start
		11:		Game over
		12:		Next 
		20:		request Undo
		21:		Allow Undo
		22:		Refuse undo
		100:	chat Message	
		Other undefine
	*/
		const int comm;	//External read-only
		unsigned int len;
		union{
			struct Position p;		//
			char chat[256] ;
		}content;
		 
		
	
		int commCheck(int v){
			switch(v){
				case MSG_GAME_START:
				case MSG_GAME_OVER:
				case MSG_GAME_NEXT:
				case MSG_REQUEST_UNDO:
				case MSG_ALLOW_UNDO:
				case MSG_REFUSE_UNDO:
				case MSG_CHAT:
					return 0;
				default:return -1;
			}
			
		}
		int setChat(char * v){
			
			strcpy(content.chat,v);
			
		}
		
		int setNext(struct Position v) {
			//12:		Next 
			int * p = (int *)&comm;
			*p = 12;
			content.p.setVal(v.x,v.y);
			
		}
		
		int setComm(int v){
			int * p = (int *)&comm;
			if(commCheck(v)==0)*p=v;		
			else {
				printf("Undefine Command :%d",v) ;
				exit(1);
			}
		};
		
};


struct Connection{
	int fd;											//file descriptor
	int numbytes;								//MSG bytes
	struct sockaddr_in	sockaddr;	//socket
	int len;										//length
	
	int getConnect() {
		if((sockaddr=socket(AF_INET,SOCK_STREAM,0)) == -1){
			perror("socket");
			exit(1;)
		}
		sockaddr.sin_family = AF_INET;
		sockaddr.sin_port = htons(SERVER_PORT);
		sockaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
		bzero(&(sockaddr.sin_zero),8);
		
		if(connect(fd,(struct sockaddr *)&socket,sizeof(struct sockaddr))==-1){
			perror("connect");
			exit(1);
		}
		puts("connect Sucess!!");
	};
	int sendOptional(){
		
		    numbytes = send(sockfd, "12345", 10, 0);
		
	};	
	int sendChat(){
		
	};	
	
	int recvMSG(){
		  numbytes = recv(fd, buf, BUFSIZ, 0);
		
	};
	
	
	};
	
	
	
	
};
#endif
