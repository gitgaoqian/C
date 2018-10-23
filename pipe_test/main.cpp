////管道测试
//#include<stdio.h>
//#include<unistd.h>
//#include<string.h>
//int main()
//{
//	int _pipe[2];//建立第一个管道,实现子进程写,父进程读
//	int _pipe1[2];//建立第二个管道,实现子进程读,父进程写
//	int ret=pipe(_pipe);
//	int ret2 = pipe(_pipe1);
//    if(ret<0 || ret2<0)
//    {
//         perror("pipe error\n");
//    }
//  	pid_t id=fork();
//  	if(id<0)
//	{
//       	perror("fork error\n");
//   	}
//   	else if(id==0)  // child
//    {
//        close(_pipe[0]);//子进程关闭管道0读端
//        close(_pipe1[1]);//子进程关闭管道1写端
//        int i=0;
//        char write_mesg[100]="I am child";
//        char recv_mesg[100];
//       while(i<100)
//       {
//           write(_pipe[1],write_mesg,11);//子进程往管道0写
//           read(_pipe1[0],recv_mesg,21);//子进程从管道1读
//           printf("child read from the parent:%s\n",recv_mesg);
//           sleep(1);
//           ++i;
//        }
//     }
//    else  //father
//   {
//       	close(_pipe[1]);//父进程关闭管道0写端
//       	close(_pipe1[0]);//父进程关闭管道1读端
//        int j=0;
//        char write_mesg[100] = "I am parent process";
//        char recv_mesg[100];
//        while(j<100)
//        {
//          //memset(_mesg,'\0',sizeof(_mesg ));
//          read(_pipe[0],recv_mesg,11);//父进程从管道0读
//          write(_pipe1[1],write_mesg,21);//父进程往管道1写
//          printf("parent read from the child:%s\n",recv_mesg);
//          sleep(1);
//          j++;
//        }
//    }
//   return 0;
//}

//命名管道测试
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#define FIFO_PIPE "/home/ros/fifo"
int main()
{
    int stat;
    stat = mkfifo(FIFO_PIPE,0777);//创建命名管道
    if (stat == -1 )
    {
        printf("fifo_pipe create error\n");
        return 0;
    }
    int fd = open(FIFO_PIPE,O_RDWR);//以读写方式打开命名管道
    if (fd == -1)
    {
        printf("open the fifo_pipe error\n");
        return 0;
    }
    char write_msg[100] = "fifo_pipe test";
    char read_msg[100];
    write(fd,write_msg,15);
    sleep(1);
    read(fd,read_msg,15);
    printf("read from the fifo_pipe:%s\n",read_msg);
}


