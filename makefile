export CXX := clang++-5.0
export CXXFLAGS := --std=c++1z

application_arguments_test: application_arguments_test.cpp application_arguments.hpp
	${CXX} ${CXXFLAGS} application_arguments_test.cpp -o $@ -lm
