all : ser dap cli

ser : service.o
	cc -pthread -o ser service.o -lmysqlclient


dap : dapeng.o jiance.o zhixing.o
	cc -pthread -o dap dapeng.o jiance.o zhixing.o


cli : client.o
	cc -pthread -o cli client.o


service.o : service.h

dapeng.o : dapeng.h

jiance.o : headfile.h

zhixing.o : headfile.h

client.o : client.h
