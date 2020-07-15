CXX		=	g++
CC_DBG	+=	-g
#CC_OPT	+=	-D_GNU_SOURCE -D_USE_PGSQL -D_USE_MYSQL
CC_OPT	+=	-D_GNU_SOURCE -D_USE_PGSQL
CC_INC	+=	-I/usr/local/include
CXXFLAGS	+=	$(CC_DBG) $(CC_OPT) $(CC_INC)
SRCS	=	LFile.cpp LSocket.cpp LPgSQL.cpp LMySQL.cpp G.cpp LCgi.cpp
OBJS	=	${SRCS:.cpp=.o}

all:	.deps libcpp.a main.x

.deps:
	$(CXX) -M $(CXXFLAGS) $(SRCS) main.cpp > $@

libcpp.a:	$(OBJS)
	ar rv $@ $?
	ranlib $@

main.x:	main.cpp libcpp.a
	$(CXX) $(CXXFLAGS) -o $@ $^ -lssl -lcrypto -lpq

clean:
	rm -f *.o *.a *.x .deps

-include .deps
