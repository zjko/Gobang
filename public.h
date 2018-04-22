#ifndef __PUBLIC_H__
#define __PUBLIC_H__
#define	SERVER_PORT	8000
#define SERVER_IP		"39.106.146.7"

struct Position{
		unsigned int x:4;
		unsigned int y:4;
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
		20:		request Undo
		21:		Allow Undo
		22:		Refuse undo
		--100:	chat Message	
		Other undefine
	*/
		const int comm:8;	//External read-only
		union{
			struct Position p;		//
			
		}content; 
		int undefine:16;
		
		int setNext() {
			
		}
		int setComm(int v){
			int * p = &comm;
			if(v>=0&&v<256){
				*p=v;
				printf("comm:%d",comm);
				return 0;
			}else return 1;			
		};
		
		int setGameStart() {
		//	10:		Game start
		int * p = &comm;
		*p = 10;	
		};
		int setGameOver() {
		//	11:		Game start
		int * p = &comm;
		*p = 11;	
		};
		int setUndo() {
		//	20:		request undo
		int * p = &comm;
		*p = 20;	
		};
		int setAllowUndo() {
		//	21:		AllowUndo
		int * p = &comm;
		*p = 21;	
		};
		int setRefuseUndo(){
		//	22:		Refuse undo
		int * p = &comm;
		*p = 22;	
		};

};

struct MSG_Chat{
	char chat[256];
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