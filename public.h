#ifndef __PUBLIC_H__
#define __PUBLIC_H__
#define	SERVER_PORT	8000
#define SERVER_IP		"39.106.146.7"

<<<<<<< HEAD
#define MSG_GAME_START		10
#define MSG_GAME_OVER			11
#define MSG_GAME_NEXT			12
#define MSG_REQUEST_UNDO	20
#define MSG_ALLOW_UNDO		21
#define MSG_REFUSE_UNDO		22
#define MSG_CHAT					100
=======
>>>>>>> 285a2bac7ddba6f17b77ff886ac428997982c8a8


#include<stdio.h>  
#include<stdlib.h>  
#include<errno.h>  
#include<string.h>  
#include<sys/types.h>  
#include<netinet/in.h>  
#include<sys/socket.h>  
#include<sys/wait.h>  
<<<<<<< HEAD

struct Position{
		unsigned int x:16;
		unsigned int y:16;
=======
#include<arpa/inet.h>
struct Position{
		unsigned int x:4;
		unsigned int y:4;
>>>>>>> 285a2bac7ddba6f17b77ff886ac428997982c8a8
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
<<<<<<< HEAD
		
		10:		Game start
		11:		Game over
		12:		Next 
=======
		10:		Game start
		11:		Game over
>>>>>>> 285a2bac7ddba6f17b77ff886ac428997982c8a8
		20:		request Undo
		21:		Allow Undo
		22:		Refuse undo
		100:	chat Message	
		Other undefine
	*/
		const int comm;	//External read-only
<<<<<<< HEAD
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

=======
		union{
			struct Position p;		//
			char chat[256];
		}content; 
		
		
		int setNext(struct Position v) {
			content.p.setVal(v.x,v.y);
			
		}
		int setComm(int v){
			int * p = (int *)&comm;
			if(v>=0&&v<256){
				*p=v;
				printf("comm:%d",comm);
				return 0;
			}else return 1;			
		};
		
		int setGameStart() {
		//	10:		Game start
		int * p =(int *) &comm;
		*p = 10;	
		};
		int setGameOver() {
		//	11:		Game start
		int * p = (int *)&comm;
		*p = 11;	
		};
		int setUndo() {
		//	20:		request undo
		int * p =(int *) &comm;
		*p = 20;	
		};
		int setAllowUndo() {
		//	21:		AllowUndo
		int * p = (int *)&comm;
		*p = 21;	
		};
		int setRefuseUndo(){
		//	22:		Refuse undo
		int * p = (int *)&comm;
		*p = 22;	
		};

};

struct MSG_Chat{
	char chat[256];
};
>>>>>>> 285a2bac7ddba6f17b77ff886ac428997982c8a8

struct Connection{
	int fd;											//file descriptor
	int numbytes;								//MSG bytes
	struct sockaddr_in	sockaddr;	//socket
	int len;										//length
	
	int getConnect() {
<<<<<<< HEAD
		if((sockaddr=socket(AF_INET,SOCK_STREAM,0)) == -1){
			perror("socket");
			exit(1;)
=======
		if((fd=socket(AF_INET,SOCK_STREAM,0)) == -1){
			perror("socket");
			exit(1);
>>>>>>> 285a2bac7ddba6f17b77ff886ac428997982c8a8
		}
		sockaddr.sin_family = AF_INET;
		sockaddr.sin_port = htons(SERVER_PORT);
		sockaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
		bzero(&(sockaddr.sin_zero),8);
		
<<<<<<< HEAD
		if(connect(fd,(struct sockaddr *)&socket,sizeof(struct sockaddr))==-1){
=======
		if(connect(fd,(struct sockaddr *)&sockaddr,sizeof(sockaddr))==-1){
>>>>>>> 285a2bac7ddba6f17b77ff886ac428997982c8a8
			perror("connect");
			exit(1);
		}
		puts("connect Sucess!!");
	};
	int sendOptional(){
		
<<<<<<< HEAD
		    numbytes = send(sockfd, "12345", 10, 0);
=======
		    numbytes = send(fd, "12345", 10, 0);
>>>>>>> 285a2bac7ddba6f17b77ff886ac428997982c8a8
		
	};	
	int sendChat(){
		
	};	
	
	int recvMSG(){
<<<<<<< HEAD
		  numbytes = recv(fd, buf, BUFSIZ, 0);
=======
		char buf[200];
		  numbytes = recv(fd, buf, 100, 0);
>>>>>>> 285a2bac7ddba6f17b77ff886ac428997982c8a8
		
	};
	
	
	};
	
	
	
	
<<<<<<< HEAD
};
#endif
=======
#endif
>>>>>>> 285a2bac7ddba6f17b77ff886ac428997982c8a8
