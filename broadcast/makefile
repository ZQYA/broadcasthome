objects = $(patsubst %.cpp,%.o,$(wildcard *.cpp)) 
sources = $(wildcard *.cpp)
VPATH = data_trans
sender: $(objects) 
	gcc -o sender.out $(objects) -l stdc++ -lpthread -DSENDER -fpack-struct=1
receiver : $(objects) dktool.o
	gcc -o receiver.out $(objects) dktool.o -l stdc++ -lpthread -USENDER -fpack-struct=1
$(objects) : $(sources)
ifdef SD 
	gcc -c $^ -l stdc++ -DSENDER 
else 
	gcc -c $^ -l stdc++ -USENDER
endif	
dktool.o : ../../ZLTCPTransfer/src/dktool.cpp
	gcc -c $^ -l stdc++
.PHONY : clean
clean :
	-rm -rf *.dSYM
	-rm *.o
