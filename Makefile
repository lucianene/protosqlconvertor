# Makefile

executable: item_proto_to_sql.o tinyxml2.o
	g++ item_proto_to_sql.o tinyxml2.o

item_proto_to_sql.o: item_proto_to_sql.cpp libs/tinyxml2/tinyxml2.h
	g++ -I ./libs/tinyxml2/ -c item_proto_to_sql.cpp

tinyxml2.o: libs/tinyxml2/tinyxml2.cpp libs/tinyxml2/tinyxml2.h
	g++ -I ./libs/tinyxml2/ -c libs/tinyxml2/tinyxml2.cpp

clean:
	rm item_proto_to_sql.o tinyxml2.o a.out
