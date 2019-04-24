Objects  = main.o investor_class.o dashboard.o money_management.o start.o stock_manipulation.o stock_trading.o

main: $(Objects)
	g++ -pedantic-errors -std=c++11 -c $^ -o $@

main.o: main.cpp investor_class.h dashboard.h money_management.h start.h stock_manipulation.h stock_trading.h
	g++ -pedantic-errors -std=c++11 -c $<

investor_class.o: investor_class.cpp investor_class.h
	g++ -pedantic-errors -std=c++11 -c $<

dashboard.o: dashboard.cpp dashboard.h investor_class.h
	g++ -pedantic-errors -std=c++11 -c $<

money_management.o: money_management.cpp money_management.h investor_class.h
	g++ -pedantic-errors -std=c++11 -c $<

start.o: start.cpp start.h
	g++ -pedantic-errors -std=c++11 -c $<

stock_manipulation.o: stock_manipulation.cpp stock_manipulation.h 
	g++ -pedantic-errors -std=c++11 -c $<

stock_trading.o: stock_trading.cpp stock_trading.h investor_class.h
	g++ -pedantic-errors -std=c++11 -c $<
