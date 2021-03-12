main: driver.o customer.o event.o
	g++ main driver.o customer.o event.o

driver.o: driver.cpp
	g++ -c driver.cpp

customer.o: customer.cpp customer.h
	g++ -c customer.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

clean:
	rm *.o