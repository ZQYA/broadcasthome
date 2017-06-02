objects = $(patsubst %.cpp,%.o,$(wildcard *.cpp)) 
sources = $(wildcard *.cpp)
tp_objects = $(patsubst %.cpp,%.o,$(wildcard tcp_data_tp/*.cpp)) 
tp_sources = $(wildcard tcp_data_tp/*.cpp)
VPATH = data_trans
sender: $(objects) $(tp_objects)
	gcc -o sender.out $(objects) -l stdc++ -DSENDER
receiver : $(objects)
	gcc -o receiver.out $(objects) -l stdc++ -USENDER	
$(objects) : $(sources)
ifdef SD 
	gcc -c $^ -l stdc++ -DSENDER 
else 
	gcc -c $^ -l stdc++ -USENDER
endif	
$(tp_objects) : $(tp_sources)
	gcc -c $^ -l stdc++ 
.PHONY : clean
clean :
	-rm -rf *.dSYM
	-rm *.o
