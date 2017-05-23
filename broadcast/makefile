objects = $(patsubst %.cpp,%.o,$(wildcard *.cpp)) 
sources = $(wildcard *.cpp)
VPATH = data_trans
sender: $(objects)
	gcc -o sender.out $(objects) -l stdc++ -DSENDER
receiver : $(objects)
	gcc -o receiver.out $(objects) -l stdc++ -USENDER	
$(objects) : $(sources)
ifdef SD 
	gcc -c $^ -l stdc++ -DSENDER 
else 
	gcc -c $^ -l stdc++ -USENDER
endif	

.PHONY : clean
clean :
	-rm -rf *.dSYM
	-rm *.o
