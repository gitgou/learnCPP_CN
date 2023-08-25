INC_DIR:= ./ 
SRC_DIR:= ./
SRCS:= $(wildcard $(SRC_DIR)*.cc) #wildcard搜索当前目录下的文件名
CC:= g++
CXXFLAGS:= -g -Wall $(addprefix -I, $(INC_DIR)) #加载头文件
LIBS:= -lpthread
OBJS:= $(patsubst %.cc, %.o, $(SRCS))
##执行下面所有依赖文件命令
BIN_EXE:= testThread.exe 

#	$(CC) -o $@ $^ $(CXXFLAGS)

$(BIN_EXE):$(OBJS)
	$(CC) -o $@ $^ $(CXXFLAGS) $(LIBS)

%.o:%.cc 
	$(CC) -o $@ -c $< $(CXXFLAGS) $(LIBS)  #依赖于第一个文件
print:
	@echo $(OBJS)

clean:
	rm -rf $(OBJS)  $(BIN_EXE)
