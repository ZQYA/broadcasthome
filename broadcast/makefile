objects = $(patsubst %.cpp,%.o,$(wildcard *.cpp)) 
sources = $(wildcard *.cpp)
VPATH = data_trans
sender: $(objects) 
	gcc -o sender.out $(objects) -l stdc++ -lpthread -DSENDER -fpack-struct=1 -ggdb
receiver : $(objects) dktool.o
	gcc -o receiver.out $(objects) dktool.o -l stdc++ -lpthread -USENDER -fpack-struct=1 -ggdb
$(objects) : $(sources)
ifdef SD 
	gcc -c $^ -l stdc++ -DSENDER -ggdb
else 
	gcc -c $^ -l stdc++ -USENDER -ggdb
endif	
dktool.o : ../../ZLTCPTransfer/src/dktool.cpp
	gcc -c $^ -l stdc++ -ggdb
.PHONY : clean
clean :
	-rm -rf *.dSYM
	-rm *.o
