Objects  = main.o investor_class.o set_up_screen.o dashboard.o money_management.o  stock_manipulation.o stock_trading.o search_data.o

main: $(Objects)
	g++ -pedantic-errors -std=c++11 $^ -o $@

main.o: main.cpp investor_class.h set_up_screen.h dashboard.h money_management.h stock_manipulation.h stock_trading.h search_data.h
	g++ -pedantic-errors -std=c++11 -c $<

investor_class.o: investor_class.cpp investor_class.h
	g++ -pedantic-errors -std=c++11 -c $<

dashboard.o: dashboard.cpp dashboard.h investor_class.h
	g++ -pedantic-errors -std=c++11 -c $<

money_management.o: money_management.cpp money_management.h investor_class.h
	g++ -pedantic-errors -std=c++11 -c $<

set_up_screen.o: set_up_screen.cpp set_up_screen.h investor_class.h
	g++ -pedantic-errors -std=c++11 -c $<

stock_manipulation.o: stock_manipulation.cpp stock_manipulation.h 
	g++ -pedantic-errors -std=c++11 -c $<

stock_trading.o: stock_trading.cpp stock_trading.h investor_class.h money_management.h
	g++ -pedantic-errors -std=c++11 -c $<

search_data.o: search_data.cpp search_data.h
	g++ -pedantic-errors -std=c++11 -c $<

clean:
	rm main $(Objects)

.PHONY: clean